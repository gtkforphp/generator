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
    * does this throw an error? (need a gerror?)
    * @var bool
    */
    public $throws = false;

    /**
    * arguments for the method
    * @var array
    */
    public $args = array();

    /**
    * Get the method proto as a string
    *
    * @return string
    */
    public function getProto() {
        $proto = array();
        foreach($this->args as $arg) {
            if($arg->direction != 'out') {
                $proto[] = $arg->ztype . ' ' . $arg->name;
            }
        }
        return implode(', ', $proto);
    }

    /**
    * Get the method proto as a string
    *
    * @return bool
    */
    public function hasParams() {
        if(empty($this->args)) {
            return false;
        }
        foreach($this->args as $arg) {
            if($arg->direction != 'out') {
                return true;
            }
        }
        return false;
    }

    /**
    * Get the ZPP spec as a string
    *
    * @return string
    */
    public function getZppSpec() {
        $spec = array();
        foreach($this->args as $arg) {
            if($arg->direction != 'out') {
                $spec[] = $arg->zppSpec;
            }
        }
        return implode('', $spec);
    }

    /**
    * Get the ZPP args as a string
    *
    * @return string
    */
    public function getZppArgs() {
        $args = array();
        foreach($this->args as $arg) {
            if($arg->direction != 'out') {
                $args[] ='&' . $arg->name;
            }
        }
        return $args;
    }

    /**
    * Get the args for the call
    *
    * @return string
    */
    public function getArgs() {
        $args = array();
        foreach($this->args as $arg) {
            $args[] ='&' . $arg->name;
        }
        return implode(', ', $args);
    }
}