<?php
/**
* getopt.php - G\Generator\Getopt command line arguments parser helper
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
* Namespace for basic generator stuff
*/
namespace G\Generator;

/**
* Getopt - handles long and short options, descriptions, and help
* display along with argument parsing
*/
class Getopt {

    /**
    * the currently running PHP script filename
    * @var string
    */
    protected $filename;

    /**
    * have we parsed our args?
    * @var boolean
    */
    protected $parsed = false;

    /**
    * argv list storage
    * @var array
    */
    protected $rawArgv;

    /**
    * argc list storage
    * @var int
    */
    protected $rawArgc;

    /**
    * parsed args
    * @var array
    */
    protected $options;

    /**
    * all argv left over after getopt
    * @var array
    */
    protected $parameters;

    /**
    * shortopts to parse in php getopt() format
    * @var string
    */
    protected $shortopts = 'h';

    /**
    * longopts to parse in php getopt() format
    * @var array
    */
    protected $longopts = array('help');

    /**
    * descriptions of each getopt item
    * @var array
    */
    protected $descriptions = array('Argument Help');

    /**
    * stores our argv argc
    *
    * @return void
    */
    public function __construct($argv, $argc) {
        $this->rawArgc = $argc;
        $this->rawArgv = $argv;
    }

    /**
     * sets options to be parsed
     *
     * @param array -> array in shortopt, longopt, description
     */
    public function setOptions(array $options) {
        $this->shortopts = '';
        $this->longopts = array();
        $this->descriptions = array();

        foreach($options as $item) {
            if (!is_array($item) || count($item) < 3) {
                trigger_error('Incorrect option format for index ' . $key
                              . ', Ignoring option', E_USER_WARNING);
            } else {
                $this->shortopts .= $item[0];
                $this->longopts[] = $item[1];
                $this->descriptions[] = $item[2];
            }
        }
    }

    /**
     * Parses command line arguments using getoption settings
     * or defaults
     *
     * NOTE: this will short circuit any app if the special "help" is called
     *
     * @return boolean
     */
    public function parseArgs() {
        $this->parsed = true;

        $return = $this->options = getopt($this->shortopts, $this->longopts);
        if ($return === false) {
            return false;
        }

        return true;
    }

    /**
     * Will parse if not parsed yet and return our options
     *
     * @return array
     */
    public function getOptions() {
        if(!$this->parsed) {
            $this->parseArgs();
        }
        return $this->options;
    }

    /**
     * Will return an array of all argv arguments
     * available AFTER parsed options
     *
     * @return array
     */
    public function getParameters() {
        if(!$this->parsed) {
            $this->parseArgs();
        }
        if (!is_null($this->parameters)) {
            return $this->parameters;
        }

        $argv = $this->rawArgv;
        $options = $this->options;
        $params = $argv;

        // strip out currently running filename
        $this->filename = $params[0];
        unset($params[0]);

        foreach($options as $option => $value) {
            foreach($argv as $key => $chunk) {
                $regex = '/^'. (isset($option[1]) ? '--' : '-') . $option . '/';
                if ($chunk == $value && $argv[$key-1][0] == '-' || preg_match($regex, $chunk)) {
                    if (isset($params[$key])) {
                        unset($params[$key]);
                    }
                }
            }
        }
        $this->parameters = $params;
        return $params;
    }

    /**
     * Will parse if not parsed yet, will parameter if not parametered yet
     * and returns resulting filename
     *
     * @return string
     */
    public function getFilename() {
        if(!$this->parsed) {
            $this->parseArgs();
        }
        if (!is_null($this->parameters)) {
            $this->getParameters();
        }
        return $this->filename;
    }

    /**
     * generates a standard help message from options
     * set for parsing
     *
     * @return array
     */
    public function showHelp($option = ' <option>') {
        $output = 'Usage: ' . basename($this->rawArgv[0]) . $option . PHP_EOL;
        $args = array();
        $longest = 0;
        $position = 0;
        foreach($this->longopts as $key => $item) {
            if (isset($this->shortopts[$position + 1]) &&
                $this->shortopts[$position + 1] == ':') {
                $required = 'required';
                $short = $this->shortopts[$position];
                $position += 2;
            } else {
                $required = '';
                $short = $this->shortopts[$position];
                $position ++;
            }
            $string = '-' . $short . ', --' . $item . $required;
            $total = strlen($string);
            if ($total > $longest) {
                $longest = $total;
            }
            $args[$key] = $string;
            unset($string, $total, $key, $item); // force scope in foreach loop
        }
        $longest += 2;
        foreach($this->descriptions as $key => $text) {
            // pad the args portion to longest + 2 spaces
            $string = str_pad($args[$key], $longest);
            // how much description can fit on a line
            $avail = 80 - strlen($string);
            // stick that much on the main line
            $string = $string . substr($text, 0, $avail);
            // get our leftover description, if any, and 
            $leftover = substr($text, $avail);
            if (strlen($leftover)) {
                $cut = str_repeat(' ', $longest);
                $string .= $cut . wordwrap($leftover, $avail, PHP_EOL . $cut, true);
            }
            $output .= $string . PHP_EOL;
            unset($key, $text, $string, $avail, $cut); // force scope in loop
        }

        echo $output;
        die;
    }

}