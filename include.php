<?php
/**
* include.php - "include all" file for the application
*
* This is released under the MIT, see LICENSE for details
*
* @author Elizabeth M Smith <auroraeosrose@php.net>
* @copyright Elizabeth M Smith (c) 2012
* @link http://gtkforphp.net
* @license http://www.opensource.org/licenses/mit-license.php MIT
* @since Php 5.4.0
* @package G\Generator
* @subpackage include
*/

$libpath = __DIR__ . DIRECTORY_SEPARATOR . 'lib' . DIRECTORY_SEPARATOR;

include $libpath . 'getopt.php';
include $libpath . 'cli.php';
include $libpath . 'extwriter.php';

unset($libpath);