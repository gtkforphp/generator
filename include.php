<?php
/**
* include.php - "include all" file for the application
*
* This is released under the MIT, see LICENSE for details
*
* @author Elizabeth M Smith <auroraeosrose@gmail.com>
* @copyright Elizabeth M Smith (c) 2012-2013
* @link http://gtkforphp.net
* @license http://www.opensource.org/licenses/mit-license.php MIT
* @since Php 5.4.0
* @package G\Generator
* @subpackage cli
*/

include G_GEN_LIBPATH . 'getopt.php';
include G_GEN_LIBPATH . 'cli.php';
include G_GEN_LIBPATH . 'extension.php';
include G_GEN_LIBPATH . 'output.php';

include G_GEN_LIBPATH . 'objects' . DIRECTORY_SEPARATOR . 'module.php';
include G_GEN_LIBPATH . 'objects' . DIRECTORY_SEPARATOR . 'package.php';
include G_GEN_LIBPATH . 'objects' . DIRECTORY_SEPARATOR . 'constant.php';
include G_GEN_LIBPATH . 'objects' . DIRECTORY_SEPARATOR . 'class.php';