<?php
/**
* module.php - G\Generator\Module
*
* This is released under the MIT, see LICENSE for details
*
* @author Elizabeth M Smith <auroraeosrose@gmail.com>
* @copyright Elizabeth M Smith (c) 2012-2013
* @link http://gtkforphp.net
* @license http://www.opensource.org/licenses/mit-license.php MIT
* @since Php 5.4.0
* @package G\Generator
* @subpackage objects
*/

/**
* Namespace for the tool
*/
namespace G\Generator\Objects;

/**
* Module Object
*/
class Module {

    /**
    * extension name
    * @var string
    */
    public $name;

    /**
    * extension version string
    * @var string
    */
    public $version;

    /**
    * module dependencies
    * @var string
    */
    public $deps;

    /**
    * array of header files to include
    * @var array
    */
    public $headers = array();

    /**
    * array of libs to include
    * @var array
    */
    public $libs = array();

    /**
    * array of namespaces (package objects)
    * @var array
    */
    public $namespaces = array();
}