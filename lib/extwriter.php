<?php
/**
* extwriter.php - G\Generator\ExtWriter application class
*
* This is released under the MIT, see LICENSE for details
*
* @author Elizabeth M Smith <auroraeosrose@php.net>
* @copyright Elizabeth M Smith (c) 2012
* @link http://gtkforphp.net
* @license http://www.opensource.org/licenses/mit-license.php MIT
* @since Php 5.4.0
* @package gig
* @subpackage lib
*/

/**
* Namespace for the tool
*/
namespace G\Generator;

/**
* ExtWriter - handles setup and running for the extension writer ggen tool
*
* uses command line variables and a configuration file to do generation of code
*/
class ExtWriter extends Cli {

    /**
    * version string in major.minor.bug-dev/alpha/beta format
    * @var string
    */
    const VERSION = '0.1.0-dev';

    /**
    * Does setup work
    * parses options, etc
    *
    * @return void
    */
    public function __construct($argv, $argc) {
        parent::__construct($argv, $argc);

        $this->opt->setOptions(
            array(
                array('h', 'help', 'Usage instructions'),
                array('v', 'version', 'Show version information'),
                array('q', 'quiet', 'Suppress all output'),
                array('l:', 'log:', 'Log to file provided --log=logfile'),

                array('c', 'check', 'Lint check config and specification files'),
                array('u', 'update', 'update the extension, do not overwrite existing files this is implicit if the location specified in the config is not empty'),
                array('n', 'new', 'ignore existing files and create a new extension this is implicit if the location specified in the config is empty'),
            )
        );
    }

    /**
    * Runs the application
    *
    * @return void
    */
    public function run() {
        $options = $this->opt->getOptions();
        $this->handleOptions($options);

        // get all our other parameters
        $params = $this->opt->getParameters();

        // no params? ack! trigger fatal - bad bad
        if(count($params) < 1) {
            trigger_error('Config filename was not provided', E_USER_ERROR);
        }

        // filename should be the last param provided
        $filename = array_pop($params);

        // load our config - maybe
        $config = $this->loadConfig($filename);
    }

    /**
    * Walks through our options and handles them
    *
    * @param array $options options to handle
    * @return void
    */
    protected function handleOptions($options) {
        foreach($options as $name => $value) {
            switch($name) {
                case 'h':
                case 'help':
                    return $this->opt->showHelp(' config_filename.type',
                                                'ggen ' . self::VERSION . ', Copyright (c) 2012 Elizabeth M Smith');
                case 'v':
                case 'version':
                    return $this->showVersion();
            }
        }
    }

    /**
    * Attempts to load in our module configuration
    * the last .blah is used for the name of the config parser
    *
    * @param string $filename name of config file to load
    * @return array configuration
    */
    protected function loadConfig($filename) {

        // look for file as absolute path
        $path = realpath($filename);
        if (!file_exists($path)) {
            // look for file in cwd registered
            $path = realpath($this->cwd . DIRECTORY_SEPARATOR . $filename);
            if (!file_exists($path)) {
                // look for file in include path using stream_resolve_include_path
                $path = stream_resolve_include_path($filename);
                if (!file_exists($path)) {
                    trigger_error('Config file ' . $filename . ' could not be loaded', E_USER_ERROR);
                }
            }
        }
        // path should now be a shiny absolute path to a file
        $ext = pathinfo ($filename, PATHINFO_EXTENSION);

        // Parser for config should be in parsers/config/$ext.php
        $parser = realpath(__DIR__ . '/../') . DIRECTORY_SEPARATOR . 'parsers' . DIRECTORY_SEPARATOR . 'config'
                . DIRECTORY_SEPARATOR . strtolower($ext) . '.php';
        $class = 'G\Generator\ConfigParser\\' . ucfirst(strtolower($ext));
        if (!file_exists($parser)) {
            trigger_error('Configuration parser for ' . $ext . ' could not be loaded', E_USER_ERROR);
        }
        include $parser;
        if (!class_exists($class)) {
            trigger_error('Configuration parser class ' . $class . ' could not be found', E_USER_ERROR);
        }

        $config = new $class($path);
        $values = $config->parse($filename);
    }
}