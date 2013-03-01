<?php
/**
* run.php - actually runs the application
*
* We use this instead of ggen itself so if the PHP version is too old
* we don't parse error bomb on startup
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

/**
* Create and run our application
*/
$app = new G\Generator\Extension($argv, $argc);
$app->run();
