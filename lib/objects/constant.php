<?php
/**
* constant.php - G\Generator\Constant
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
* Constant information
*/
class Constant {

    /**
    * constant name
    * @var string
    */
    public $name;

    /**
    * constant C definition
    * @var string
    */
    public $def;

    /**
    * constant C type
    * @var string
    */
    public $type;
}