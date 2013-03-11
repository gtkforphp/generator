<?php
/**
* param.php - G\Generator\Param
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
* parameter information
*/
class Param {

    /**
    * constant name
    * @var string
    */
    public $name;

    /**
    * generic type name
    * @var string
    */
    public $type;

    /**
    * one of
    * none: the recipient does not own the value (floating is an alias)
    * container: the recipient owns the container, but not the elements
    * full: the recipient owns the entire value.
    *       For a refcounted type, this means the recipient owns a ref on the value.
    *       For a container type, this means the recipient owns both container and elements.
    * @var string
    */
    public $transfer;

    /**
    * documentation for the param
    * @var string
    */
    public $doc;

    /**
    * c type to actually use
    * @var string
    */
    public $nativeType;

    /**
    * zend c type to use for ZPP
    * @var string
    */
    public $zppType;

    /**
    * ZPP parse string to use
    * @var string
    */
    public $zppSpec;

    /**
    * ztype (bool, int, string, array, object, float)
    * @var string
    */
    public $ztype;

    /**
    * direction can be in, out, or in-out
    * @var string
    */
    public $direction = 'in';
}