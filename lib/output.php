<?php
/**
* output.php - G\Generator\Output class
*
* This is released under the MIT, see LICENSE for details
*
* @author Elizabeth M Smith <auroraeosrose@gmail.com>
* @copyright Elizabeth M Smith (c) 2012-2013
* @link http://gtkforphp.net
* @license http://www.opensource.org/licenses/mit-license.php MIT
* @since Php 5.4.0
* @package G\Generator
* @subpackage lib
*/

/**
* Namespace for the tool
*/
namespace G\Generator;
use G\Generator\Extension;
use G\Generator\Objects\Module;

/**
* Takes information about a module and writes it out using the template
* chosen
*/
class Output {

    /**
    * cache year
    * @var string
    */
    protected $year;

    /**
    * Checks for the extension and attempts to require the proper typelib
    *
    * @return void
    */
    public function __construct($config, $configpath) {

        // template location
        if (!isset($config['templates'])) {
           trigger_error('Template location missing in configuration file', E_USER_ERROR);
        }

        // is templates an absolute path?
        if (!file_exists($config['templates'])) {
            // not an absolute path, look in config directory
            $temp1 = $configpath . DIRECTORY_SEPARATOR . $config['templates'];
            if (!file_exists($temp1)) {
                // still not a good path, look in shipped templates directory
                $temp2 = G_GEN_LIBPATH . 'templates'
                    . DIRECTORY_SEPARATOR . $config['templates'];
                if (!file_exists($temp2)) {
                    trigger_error('Templates not in ' . $config['templates'] . ' or ' . $temp1 . ' or ' . $temp2, E_USER_ERROR);
                } else {
                    $templates = $temp2;
                }
            } else {
                $templates = $temp1;
            }
        } else {
            $templates = $config['templates'];
        }
        $this->templates = $templates . DIRECTORY_SEPARATOR;

        // output location
        if (!isset($config['location'])) {
           trigger_error('Output location missing in configuration file', E_USER_ERROR);
        }

        // is location an absolute path?
        if (!file_exists($config['location'])) {
            // not an absolute path, look in config directory
            $temp1 = $configpath . DIRECTORY_SEPARATOR . $config['location'];
            if (!file_exists($temp1)) {
                // still not a good path, look libpath?
                $temp2 = G_GEN_LIBPATH . $config['location'];
                if (!file_exists($temp2)) {
                    trigger_error('No directory for writing in ' . $config['location'] . ' or ' . $temp1 . ' or ' . $temp2, E_USER_ERROR);
                } else {
                    $location = $temp2;
                }
            } else {
                $location = $temp1;
            }
        } else {
            $location = $config['location'];
        }

        $this->deleteDir($location);
        mkdir($location);

        // for now we always generate new
        trigger_error('Output will write to ' . $location, E_USER_WARNING);

        $this->location = $location . DIRECTORY_SEPARATOR;

        // we use a date everywhere
        $this->year = date('Y');
    }

    /**
    * Writes out our module
    *
    * @return void
    */
    public function writeNewExtension($module) {

        $this->writeModuleFile($module);

        /*
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
        $this->writeModuleFile($classes); */
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
    protected function writeModuleFile(Module $module) {
        $vars = ['generator_version' => Extension::VERSION,
                 'year' => $this->year,
                 'classes' => array(),
                 'authors' => $module->authors,
                 'module' => $module->name,
                 'module_uc' => strtoupper($module->name),
                 'module_lc' => strtolower($module->name),
                 'includes' => $module->headers];

        return $this->generate($vars,
            $this->templates . 'module.c.tpl',
            $this->location . 'php_'. $vars['module_lc'] . '.c');
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
    * Generate the file - note we use funny double underscored
    * variable names to prevent collisions, we also extract
    * with block overwrite on to keep from $this being overwritten
    *
    * @params array $vars to extract for template
    * @params string $template absolute path to template
    * @params string $filename absolute path to filename
    * @return boolean
    */
    protected function generate($__vars, $__template, $__filename) {
        extract($__vars, EXTR_SKIP);

        ob_start();
        include $__template;
        $__file = ob_get_clean();

        return file_put_contents($__filename, $__file);
    }
}