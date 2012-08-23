<?php
/**
* output.php - G\Generator\Output class
*
* This is released under the MIT, see LICENSE for details
*
* @author Elizabeth M Smith <auroraeosrose@php.net>
* @copyright Elizabeth M Smith (c) 2012
* @link http://gtkforphp.net
* @license http://www.opensource.org/licenses/mit-license.php MIT
* @since Php 5.4.0
* @package g\generator
* @subpackage lib
*/

/**
* Namespace for the tool
*/
namespace G\Generator;

/**
* Takes information about a module and writes it out using the template
* chosen
*/
class Output {

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
    * module name
    * @var string
    */
    protected $module;

    /**
    * authors
    * @var array
    */
    protected $authors = array();

    /**
    * Checks for the extension and attempts to require the proper typelib
    *
    * @return void
    */
    public function __construct($config) {

        // module name
        if (!isset($config['module'])) {
           trigger_error('Module name missing in configuration file', E_USER_ERROR);
        }
        $this->module = $config['module'];

        // template location
        if (!isset($config['templates'])) {
           trigger_error('Template location missing in configuration file', E_USER_ERROR);
        }
        $templates = realpath($config['templates']);
        if (!file_exists($templates)) {
           $templates = realpath(__DIR__ . '/../') . DIRECTORY_SEPARATOR . 'templates'
            . DIRECTORY_SEPARATOR . $config['templates'] . DIRECTORY_SEPARATOR;
            if (!file_exists($templates)) {
                trigger_error('Template ' . $templates . ' does not exist', E_USER_ERROR);
            }
        }
        $this->templates = $templates;

        // output location
        if (!isset($config['location'])) {
           trigger_error('Output location missing in configuration file', E_USER_ERROR);
        }
        $location = $config['location'];

        $this->deleteDir($location);
        mkdir($location);
        $location = realpath($location);
        // for now we always generate new
        trigger_error('Output will write to ' . $location, E_USER_WARNING);

        $this->location = $location . DIRECTORY_SEPARATOR;

        if (isset($config['authors'])) {
           $this->authors = $config['authors'];
        }
    }

    /**
    * Writes out our module
    *
    * @return void
    */
    public function writeModule($spec) {
        $classes = array();

        foreach($spec['classes'] as $name => $info) {
            $this->writeClassFile($name, $info);
            $classes[] = $name;
        }

        // check for enums
        if (isset($spec['enums'])) {
            $this->writeEnumFile($spec['enums']);
            $classes[] = 'Enums';
        }

        // finally write out module
        $this->writeModuleFile($classes);
    }

    /**
    * Class File
    *
    * @return void
    */
    protected function writeClassFile($name, $info) {
        $vars = array();

        $vars['class'] = $name;
        $vars['class_lc'] = strtolower($name);
        $vars['methods'] = $info['methods'];

        return $this->generate($vars,
                        $this->templates . 'class.c.tpl',
                        $this->location . strtolower($name) . '.c');
    }

    /**
    * Enum File
    *
    * @return void
    */
    protected function writeEnumFile($enums) {
        return $this->generate(array('enums' => $enums),
                        $this->templates . 'enum.c.tpl',
                        $filename = $this->location . 'enums.c');
    }

    /**
    * Module File
    *
    * @return void
    */
    protected function writeModuleFile($classes) {

        return $this->generate(
            array('generator_version' => \G\Generator\ExtWriter::VERSION,
                  'classes' => $classes),
            $this->templates . 'module.c.tpl',
            $this->location . 'php_'. strtolower($this->module) . '.c');
    }

    /**
    * Cleans up our environment
    *
    * @return void
    */
    protected function deleteDir($dir) {
        if (!file_exists($dir)) {
            return;
        }
        foreach(glob($dir . '/*') as $file) {
            if(is_dir($file)) {
                $this->deleteDir($file);
            } else {
                unlink($file);
            }
        }
        rmdir($dir);
    }

    /**
    * Returns array of basic args that is needed in all templates
    *
    * @return array
    */
    protected function getGlobals() {
        return array(
                'authors' => $this->authors,
                'module' => $this->module,
                'module_lc' => strtolower($this->module),
                'module_uc' => strtoupper($this->module),
                'year' => date('Y'),
                    );
    }


    /**
    * Generate the file
    *
    * @params array $vars to extract for template
    * @params string $template absolute path to template
    * @params string $filename absolute path to filename
    * @return boolean
    */
    protected function generate($vars, $template, $filename) {
        $vars += $this->getGlobals();
        extract($vars);

        ob_start();
        include $template;
        $file = ob_get_clean();

        return file_put_contents($filename, $file);
    }
}