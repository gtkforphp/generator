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

                array('v', 'verbose', 'Show version information'),
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

        // hurray, we have config!
        $spec = $this->loadSpec($config);
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
                    $this->showHeader();
                    return $this->opt->showHelp(' config_filename.type');

                case 'v':
                case 'verbose':
                    $this->messages = 2;
                    break;
                case 'q':
                case 'quiet':
                    if ($this->messages > 1) {
                        $this->showHeader();
                        trigger_error('You cannot use --verbose and --quiet at the same time', E_USER_ERROR);
                    }
                    $this->messages = 0;
                    break;
            }
        }

        $this->showHeader();

        foreach($options as $name => $value) {
            switch($name) {
                case 'l':
                case 'log':
                    // TODO: making logging work... $this->setLogFile($value);
                    break;

                case 'c':
                case 'check':
                    // TODO: do the lint
                    break;

                case 'u':
                case 'update':
                    // TODO: force update
                    break;

                case 'n':
                case 'new':
                    // TODO: force new
                    break;
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
        $this->printMessage('Attempting to load filename ' . $filename, 2);
        $path = realpath($filename);
        $this->printMessage('Looking in ' . $path, 2);
        if (!file_exists($path)) {
            // look for file in cwd registered
            $path = realpath($this->cwd . DIRECTORY_SEPARATOR . $filename);
            $this->printMessage('Looking in ' . $path, 2);
            if (!file_exists($path)) {
                // look for file in include path using stream_resolve_include_path
                $path = stream_resolve_include_path($filename);
                $this->printMessage('Looking in ' . $path, 2);
                if (!file_exists($path)) {
                    trigger_error('Config file ' . $filename . ' could not be loaded', E_USER_ERROR);
                }
            }
        }
        // path should now be a shiny absolute path to a file
        $this->printMessage('Loading configuration from ' . $path);

        // parser type detection
        $ext = pathinfo ($filename, PATHINFO_EXTENSION);
        $this->printMessage('Config detected as type ' . $ext, 2);

        // Parser for config should be in parsers/config/$ext.php
        $parser = realpath(__DIR__ . '/../') . DIRECTORY_SEPARATOR . 'parsers' . DIRECTORY_SEPARATOR . 'config'
                . DIRECTORY_SEPARATOR . strtolower($ext) . '.php';
        $this->printMessage('Trying to load parser ' . $parser, 2);
        if (!file_exists($parser)) {
            trigger_error('Configuration parser for ' . $ext . ' could not be loaded', E_USER_ERROR);
        }

        $class = 'G\Generator\ConfigParser\\' . ucfirst(strtolower($ext));
        $this->printMessage('Trying to load class ' . $class, 2);
        include $parser;
        if (!class_exists($class)) {
            trigger_error('Configuration parser class ' . $class . ' could not be found', E_USER_ERROR);
        }
        $this->printMessage('Parser loaded for config type ' . $ext);

        $config = new $class($path);
        return $config->parse($filename);
    }

    /**
    * Attempts to create and load a spec parser for the requested module
    *
    * @param string $filename name of config file to load
    * @return object instanceof specparser
    */
    protected function loadSpec($config) {

        // parser type detection
        if (isset($config['specification']['type'])) {
            $type = $config['specification']['type'];
        } else {
            trigger_error('Specification type missing from configuration file', E_USER_ERROR);
        }

        $this->printMessage('Specification detected as type ' . $type, 2);

        // Parser for spec should be in parsers/spec/$type.php
        $parser = realpath(__DIR__ . '/../') . DIRECTORY_SEPARATOR . 'parsers' . DIRECTORY_SEPARATOR . 'spec'
                . DIRECTORY_SEPARATOR . strtolower($type) . '.php';
        $this->printMessage('Trying to load parser ' . $parser, 2);
        if (!file_exists($parser)) {
            trigger_error('Specification parser for ' . $type . ' could not be loaded', E_USER_ERROR);
        }

        $class = 'G\Generator\SpecParser\\' . ucfirst(strtolower($type));
        $this->printMessage('Trying to load class ' . $class, 2);
        include $parser;
        if (!class_exists($class)) {
            trigger_error('Specification parser class ' . $class . ' could not be found', E_USER_ERROR);
        }
        $this->printMessage('Parser loaded for spec type ' . $type);

        return new $class($config['specification']);
    }

    /**
    * Echoes out version information to console
    *
    * @return void
    */
    protected function showHeader() {
        if($this->messages > 0) {
            echo 'ggen ' . self::VERSION . ', Copyright (c) 2012 Elizabeth M Smith', PHP_EOL, PHP_EOL;
        }
    }
}