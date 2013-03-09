<?php
/**
* class.php - G\Generator\Klass
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
* Like namespace, class is reserved (sigh) - let's spell it funny!
*/
class Klass {

    /**
    * constant name
    * @var string
    */
    public $name;

    /**
    * datatype for storage in a struct
    * @var string
    */
    public $type;

    /**
    * documentation to throw into the proto
    * @var string
    */
    public $doc;

    /**
    * Methods for class
    * @var array
    */
    public $methods = array();

    /**
    * flag if the class has a __construct already
    * @var bool
    */
    public $hasConstructor = false;

    /**
    * a C identifier used to initialize the c data stored in the class struct
    * @var string
    */
    public $createHandler;

    /**
    * a C identifier used to free the c data stored in the class struct
    * @var string
    */
    public $freeHandler;
}