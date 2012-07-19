<?php
/**
* app.php - Gig\App class for basic applicaiton information
*
* This is released under the MIT, see LICENSE for details
*
* @author Elizabeth M Smith <auroraeosrose@php.net>
* @copyright Elizabeth M Smith (c) 2012
* @link http://gtkforphp.net
* @license http://www.opensource.org/licenses/mit-license.php MIT
* @since Php 5.4.0
* @package gig
* @subpackage lib
*/

/**
* Namespace for Gobject Introspection Generator (gig)
*/
namespace Gig;

/**
* App - handles setup and running for the generator
*
* uses command line variables and a configuration file to do generation of code
*/
class App {
// set up PHP environment
// big memory limit
// big time limit
// error reporting

// set up includes for all files

// parse args
// application options
// 1. help
// 2. version
// 3. list available parsers for config
// 4. list available formats for specifications
// 5. lint config
// 6. lint specification
// 6.a. config and/or spec generation?
// 5. changes in behavior
//    1. overall "quiet" tag shuts ALL up (except fatals, see above)
//    2. overall "verbose" makes REALLY loud - can't do both!
//    3. actual output location for generation
//    4. logging behavior/location
//    5. update existing or new generation switch
//    6. generate ext, tests, doc
// 6. do generation
//    1. parse configuration
//     1. choose and load parser format
//     2. parse into array/load
//     3. format check
//     4.setup specification
//       1. spec format and location
//       2. templates format and location
//       3. what to generate
//    2. parse specification
//     1. choose and load parser format
//     2. parse into array/load
//     3. format check
//   3.a. new - writing
//     1. using spec data, write C files
//     2. using spec data, write test files
//     3. using spec data, write doc files
//   3.b. update - reading/writing
//     1. read in data, compare to spec data, write C files
//     2. read in data, compare to spec data, write test files
//     3. read in data, compare to spec data, write doc files
}