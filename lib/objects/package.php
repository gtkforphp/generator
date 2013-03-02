<?php
/**
* package.php - G\Generator\Package
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
namespace G\Generator\Objects;

/**
* This should be called "namespace" but that's a reserved word
* so for the actual classname we'll call it package
*/
class Package {

    /**
    * namespace name
    * @var string
    */
    public $name;

    /**
    * version string
    * @var string
    */
    public $version;

    /**
    * array of constant objects
    * @var array
    */
    public $constants = array();

    /**
    * array of class objects
    * @var array
    */
    public $classes = array();
}