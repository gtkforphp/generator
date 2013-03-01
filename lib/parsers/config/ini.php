<?php
/**
* ini.php - G\Generator\ConfigParser\Ini class
*
* This is released under the MIT, see LICENSE for details
*
* @author Elizabeth M Smith <auroraeosrose@php.net>
* @copyright Elizabeth M Smith (c) 2012
* @link http://gtkforphp.net
* @license http://www.opensource.org/licenses/mit-license.php MIT
* @since Php 5.4.0
* @package g\generator
* @subpackage configparser
*/

/**
* Namespace for the tool
*/
namespace G\Generator\ConfigParser;

/**
* "parses" ini files into the appropriate PHP array
* from .ini file configuration
*/
class Ini {

    /**
    * absolute path to ini file
    * @var string
    */
    protected $filename;

    /**
    * Does setup work
    * parses options, etc
    *
    * @return void
    */
    public function __construct($filename) {
        if (!file_exists($filename)) {
            trigger_error('Ini file ' . $filename . ' could not be loaded', E_USER_ERROR);
        }
        $this->filename = $filename;
    }

    /**
    * Does setup work
    * parses options, etc
    *
    * @return void
    */
    public function parse() {
        $base = parse_ini_file($this->filename, true, INI_SCANNER_RAW);
        if ($base === false) {
            trigger_error('Ini file ' . $this->filename . ' could not be parsed', E_USER_ERROR);
        }
        // TODO: merge with defaults
        return $base;
    }
}