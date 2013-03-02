<?php
/**
* extension.php - G\Generator\Extension application class
*
* This is released under the MIT, see LICENSE for details
*
* @author Elizabeth M Smith <auroraeosrose@gmail.com>
* @copyright Elizabeth M Smith (c) 2012-2013
* @link http://gtkforphp.net
* @license http://www.opensource.org/licenses/mit-license.php MIT
* @since Php 5.4.0
* @package G\Generator
* @subpackage lib
*/

/**
* Namespace for the tool
*/
namespace G\Generator;

/**
* Extension - handles setup and running for the extension writing, updating, docing, etc
*
* uses command line variables and a configuration file to do generation of code
* Expects G_GEN_LIBPATH to be defined
*/
class Extension extends Cli {

    /**
    * version string in major.minor.bug-dev/alpha/beta format
    * @var string
    */
    const VERSION = '0.1.0-dev';

    /**
    * the path to the location of the config file, this is used to
    * look for assets for generation in the same dir
    * @var string
    */
    protected $configpath;

    /**
    * Does setup work
    * parses options, etc
    *
    * @return void
    */
    public function __construct($argv, $argc) {
        $this->logfile = __DIR__ . DIRECTORY_SEPARATOR . 'ggen.log';

        parent::__construct($argv, $argc);

        $this->opt->setOptions(
            array(
                array('h', 'help', 'Usage instructions'),

                array('v', 'verbose', 'Show version information'),
                array('q', 'quiet', 'Suppress all output'),

                array('l', 'log', 'log to file, default is ggen.log'),

                array('n', 'new', 'Generate new extension code'),
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

        // load our spec file
        $spec = $this->loadSpec($config);

        // load our output mechanism
        $output = $this->loadOutput($config);

        // TODO: decide what to output here
        $output->writeNewExtension($spec->parse());
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
        $ext = $this->getConfig(pathinfo ($filename, PATHINFO_EXTENSION));
        $this->printMessage('Config detected as type ' . $ext, 2);

        // Parser for config should be in parsers/config/$ext.php
        $parser = G_GEN_LIBPATH . 'parsers' . DIRECTORY_SEPARATOR . 'config'
                . DIRECTORY_SEPARATOR . $ext . '.php';
        $this->printMessage('Trying to load config parser ' . $parser, 2);
        if (!file_exists($parser)) {
            trigger_error('Configuration parser for ' . $ext . ' could not be loaded', E_USER_ERROR);
        }

        $class = 'G\Generator\Config\\' . ucfirst($ext);
        $this->printMessage('Trying to load class ' . $class, 2);
        include $parser;
        if (!class_exists($class)) {
            trigger_error('Configuration parser class ' . $class . ' could not be found', E_USER_ERROR);
        }
        $this->printMessage('Parser loaded for config type ' . $ext);
        $this->configpath = dirname($path);

        return new $class($path);
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
            $type = $this->getParser($config['specification']['type']);
        } else {
            trigger_error('Specification type missing from configuration file', E_USER_ERROR);
        }

        $this->printMessage('Specification detected as type ' . $type, 2);

        // Parser for spec should be in parsers/spec/$type.php
        $parser = G_GEN_LIBPATH . 'parsers' . DIRECTORY_SEPARATOR . 'spec'. DIRECTORY_SEPARATOR . $type . '.php';
        $this->printMessage('Trying to load parser ' . $parser, 2);
        if (!file_exists($parser)) {
            trigger_error('Specification parser for ' . $type . ' could not be loaded', E_USER_ERROR);
        }

        $class = 'G\Generator\Spec\\' . ucfirst($type);
        $this->printMessage('Trying to load class ' . $class, 2);
        include $parser;
        if (!class_exists($class)) {
            trigger_error('Specification parser class ' . $class . ' could not be found', E_USER_ERROR);
        }
        $this->printMessage('Parser loaded for spec type ' . $type);

        return new $class($config['specification'], $this->configpath);
    }

    /**
    * Starts up an instance to use to output our parsed information
    *
    * @param array $config configuration values
    * @return object instanceof writer
    */
    protected function loadOutput($config) {

        // writer configuration information
        if (!isset($config['output'])) {
            trigger_error('Writer output settings missing from configuration file', E_USER_ERROR);
        }

        return new Output($config['output']);
    }

    /**
    * Echoes out version information to console
    *
    * @return void
    */
    protected function showHeader() {
        if($this->messages > 0) {
            echo 'ggen ' . self::VERSION . ', Copyright (c) 2012 - '. date('Y') . ' Elizabeth M Smith', PHP_EOL, PHP_EOL;
        }
    }

    /**
    * Gets a legal config type value
    * supported types should be added here
    *
    * @return string
    */
    protected function getConfig($ext) {
        switch($ext) {
            case 'json':
                return 'json';
            case 'xml':
                return 'xml';
            case 'ini':
            default:
                return 'ini';
        }
    }

    /**
    * Gets a legal spec parser type
    * supported types should be added here
    *
    * @return string
    */
    protected function getParser($ext) {
        switch($ext) {
            case 'gir':
                return 'gir';
            case 'gintrospection':
                return 'gintrospection';
            case 'peclgen':
            default:
                return 'peclgen';
        }
    }
}