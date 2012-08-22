<?php
/**
* gintrospection.php - G\Generator\SpecParser\Gintrospection class
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
* uses G\Introspection from gintrospection extension
* to load and parse specifications for an extension
*/
class Gintrospection {

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
    }
}