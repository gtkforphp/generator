<?php
/**
* gintrospection.php - G\Generator\Spec\Gintrospection class
*
* This is released under the MIT, see LICENSE for details
*
* @author Elizabeth M Smith <auroraeosrose@gmail.com>
* @copyright Elizabeth M Smith (c) 2012-2013
* @link http://gtkforphp.net
* @license http://www.opensource.org/licenses/mit-license.php MIT
* @since Php 5.4.0
* @package G\Generator
* @subpackage specparser
*/

/**
* Namespace for the tool
*/
namespace G\Generator\Spec;

/**
* uses G\Introspection from gintrospection extension
* to load and parse specifications for an extension
*/
class Gintrospection {

    /**
    * our repository
    * @var object
    */
    protected $repository;

    /**
    * namespace to modularize
    * @var string
    */
    protected $namespace;

    /**
    * version to modularize
    * @var string
    */
    protected $version;

    /**
    * Checks for the extension and attempts to require the proper typelib
    *
    * @return void
    */
    public function __construct($config) {
        if (!extension_loaded('gintrospection')) {
            trigger_error('Requires the gintrospection extension to be available', E_USER_ERROR);
        }

        if (!isset($config['namespace'])) {
            trigger_error('Gintrospection requires a namespace to be loaded', E_USER_ERROR);
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
        $module = array('enums' => array(), 'classes' => array());
        $typelibs = $this->repository->getInfos($this->namespace);

        foreach($typelibs as $info) {
            if($info instanceof \G\Introspection\EnumInfo) {
                $enum = array();
                $values = $info->getValues();
                foreach($values as $item) {
                    $enum[$item->getName()] = $item->getAttribute('c:identifier');
                }
                $module['enums'][$info->getName()] = $enum;
                unset($enum, $values, $item);
            } elseif (($info instanceof \G\Introspection\StructInfo) ||
                     ($info instanceof \G\Introspection\UnionInfo)) {
                $class = array('methods' => array(), 'properties' => array());
                $methods = $info->getMethods();
                foreach($methods as $method) {
                    $class['methods'][] = $method->getName();
                }
                $fields = $info->getFields();
                foreach($fields as $field) {
                    $class['fields'][] = $field->getName();
                }

                $module['classes'][$info->getName()] = $class;
                unset($class, $fields, $field, $methods, $method);
            }
        }
        unset($typelibs, $info);

        return $module;
    }
}