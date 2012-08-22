<?php
/**
* cli.php - G\Generator\Cli base cli application
*
* This is released under the MIT, see LICENSE for details
*
* @author Elizabeth M Smith <auroraeosrose@php.net>
* @copyright Elizabeth M Smith (c) 2012
* @link http://gtkforphp.net
* @license http://www.opensource.org/licenses/mit-license.php MIT
* @since Php 5.4.0
* @package g\generator
* @subpackage lib
*/

/**
* Namespace for the tool
*/
namespace G\Generator;
use G\Generator\Getopt;

/**
* CLI - tools for simple command line applications
*/
abstract class Cli {

    /**
    * binary used to run script
    * @var string
    */
    protected $bin;

    /**
    * cwd where script was started
    * @var string
    */
    protected $cwd;

    /**
    * argument parsing object
    * @var object instanceof GetOpt
    */
    protected $opt;

    /**
    * Does setup work
    * parses options, etc
    *
    * @return void
    */
    public function __construct($argv, $argc) {
        $this->setupErrorHandling();
        $this->setupPhpEnv();
        $this->opt = new GetOpt($argv, $argc);
    }

    /**
    * Provides "readline" functionality with or without readline
    * extension
    *
    * @param string $prompt optional prompt to display
    * @return string
    */
    public function readline($prompt = null) {

        if(function_exists('readline')) {
            return readdline($prompt);
        } else {
            if($prompt) {
                echo $prompt;
            }
            return stream_get_line(STDIN, 1024, PHP_EOL);
        }
    }

    /**
     * write a message to the logfile
     *
     * @param string $message message to display
     * @return void
     */
    public function logMessage($message) {
        if (empty($this->logfile)) {
            // logfile
            $this->logfile = dirname(__FILE__) . '/install.log';
            touch($this->logfile);
        }
        file_put_contents($this->logfile, $message . PHP_EOL, FILE_APPEND);
    }

    /**
     * print a wrapped message to the screen
     *
     * @param string $message message to display
     * @return void
     */
    public function printMessage($message) {
        if (strlen($message) > 78) {
            echo wordwrap($message, 78, PHP_EOL, true);
        } else {
            echo $message . PHP_EOL;
        }
    }

    /**
    * Sets up our PHP environment
    *
    * @return void
    */
    protected function setupPHPEnv() {
        set_time_limit(300);
        ini_set('memory_limit','-1');

        if (ini_get('date.timezone') == '') {
            date_default_timezone_set('UTC');
        }

        $this->cwd = getcwd();
        $this->bin = PHP_BINARY;
    }

    /**
    * Sets up our error handling
    *
    * @return void
    */
    protected function setupErrorHandling() {
        error_reporting(-1);
        // set exception handler
        // set error handler
    }
}