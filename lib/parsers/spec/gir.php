<?php
/**
* gir.php - G\Generator\SpecParser\Gir xml
*
* This is released under the MIT, see LICENSE for details
*
* @author Elizabeth M Smith <auroraeosrose@php.net>
* @copyright Elizabeth M Smith (c) 2012
* @link http://gtkforphp.net
* @license http://www.opensource.org/licenses/mit-license.php MIT
* @since Php 5.4.0
* @package g\generator
* @subpackage specparser
*/

/**
* Namespace for the tool
*/
namespace G\Generator\SpecParser;

/**
* Uses xml format for Gobject Introspection to parse stuff
*/
class Gir {

    /**
    * our simplexml object of doom
    * @var object
    */
    protected $simplexml;

    /**
    * gir file for the project
    * @var string
    */
    protected $file;

    /**
    * Checks for the file existing and stores it
    *
    * @return void
    */
    public function __construct($config) {

        if (!isset($config['filename'])) {
            trigger_error('a gir filename is required for specification', E_USER_ERROR);
        } else {
            $namespace = $config['namespace'];
            if (isset($config['version'])) {
                $version = $config['version'];
            } else {
                $version = null;
            }
        }

        $this->repository = \G\Introspection\Repository::getDefault();
        $this->repository->require($namespace, $version);
        $this->namespace = $namespace;
        $this->version = $version;
    }

    /**
    * Returns an array? of information about the extension specification?
    *
    * @return void
    */
    public function parse() {
        
    }
}