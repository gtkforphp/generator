#!/usr/bin/env php
<?php
/**
* ggen.php - command line tool for exension generation
*
* This is released under the MIT, see LICENSE for details
*
* @author Elizabeth M Smith <auroraeosrose@php.net>
* @copyright Elizabeth M Smith (c) 2012
* @link http://gtkforphp.net
* @license http://www.opensource.org/licenses/mit-license.php MIT
* @since Php 5.4.0
* @package G\Generator
* @subpackage cli
*/

/**
 * PHP Environment testing
 *
 * There are a few requirements for the PHP environment that this
 * script needs in order to run.  Fatal errors will be output to
 * stderr if this stuff doesnt' work
 *
 * Current sanity checks
 * 1. PHP version (5.4)
 * 2. PHP SAPI (MUST be cli)
 * 3. PHP extensions (spl, date, pcre, reflection and standard)
 * 4. argv/argc
 *
 * Note this file doesn't use namespaces until after the version check
 * or pollute the global namespace  Should run on any 5+ version of PHP...
 * and bail properly
 */

if (version_compare(PHP_VERSION, "5.4.0", "<")) {
    fwrite(STDERR,
<<<BAD_PHP_ERROR

+-----------------------------------------------------------+
|                       ! ERROR !                           |
| ggen requires PHP 5.40 or higher to run.  Please update to |
| a more recent PHP version to continue.                    |
+-----------------------------------------------------------+

BAD_PHP_ERROR
    );
    exit(1);
}

if (PHP_SAPI != 'cli') {
    fwrite(STDERR,
<<<BAD_SAPI_ERROR

+-----------------------------------------------------------+
|                       ! ERROR !                           |
| ggen must be run using the php cli.  On windows this is    |
| php.exe or php-win.exe.  On linux systems you may need to |
| install a package php5-cli or something similar.          |
+-----------------------------------------------------------+

BAD_SAPI_ERROR
    );
    exit(1);
}

if (!extension_loaded('reflection') ||
    !extension_loaded('pcre') ||
    !extension_loaded('date') ||
    !extension_loaded('spl') ||
    !extension_loaded('standard')) {
    fwrite(STDERR,
<<<BAD_EXT_ERROR

+-----------------------------------------------------------+
|                       ! ERROR !                           |
| ggen requires spl, date, pcre, reflection and standard to  |
| be loaded in order to run.  These extensions are normally |
| built into PHP by default but at least one is missing.    |
| Please rebuild your PHP to include these extensions, or   |
| load them via your php.ini file.                          |
+-----------------------------------------------------------+

BAD_EXT_ERROR
    );
    exit(1);
}

if (!isset($argv) || !isset($argc)) {
    fwrite(STDERR,
<<<BAD_ARGV_ERROR

+-----------------------------------------------------------+
|                       ! ERROR !                           |
| ggen requires both argv and argc (command line argument    |
| information) to be available in order to run.  Please     |
| enable register_argv_argc in your command line php.ini    |
+-----------------------------------------------------------+

BAD_ARGV_ERROR
    );
    exit(1);
}

/**
* Include all our classes with an include all file
* does not load any config or spec parsers
*/
include __DIR__ . DIRECTORY_SEPARATOR . 'include.php';

/**
* Create and run our application
*/
$app = new G\Generator\ExtWriter($argv, $argc);
$app->run();