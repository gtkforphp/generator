<?php
/**
* method.php - G\Generator\Method
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
* Method oddly enough is not reserved
*/
class Method {

    /**
    * is this method the constructor?
    * @var bool
    */
    public $isConstructor = false;

    /**
    * constant name
    * @var string
    */
    public $name;

    /**
    * c identifier for the method to use
    * @var string
    */
    public $identifier;

    /**
    * documentation for the method
    * @var string
    */
    public $doc;

    /**
    * by default this is null (void)
    * @var string
    */
    public $returnValue;

    /**
    * arguments for the method
    * @var array
    */
    public $args = array();
}