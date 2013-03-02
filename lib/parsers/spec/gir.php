<?php
/**
* gir.php - G\Generator\Spec\Gir xml
*
* This is released under the MIT, see LICENSE for details
*
* @author Elizabeth M Smith <auroraeosrose@gmail.com>
* @copyright Elizabeth M Smith (c) 2012-2013
* @link http://gtkforphp.net
* @license http://www.opensource.org/licenses/mit-license.php MIT
* @since Php 5.4.0
* @package G\Generator
* @subpackage spec_parser
*/

/**
* Namespace for the tool
*/
namespace G\Generator\Spec;
use G\Generator\Objects\Module;
use G\Generator\Objects\Package;
use G\Generator\Objects\Constant;
use XMLReader;
use SimpleXMLElement;

/**
* Uses xml format for Gobject Introspection to parse stuff
*/
class Gir {

    /**
    * gir file for the project
    * @var string
    */
    protected $file;

    /**
    * We use xmlreader for pull parsing because these can be
    * large files and we DEFINITELY don't want to load it all
    * into memory like dom and simplexml
    *
    * @var object
    */
    protected $reader;

    /**
    * cache for name and version of php module/extension from config
    *
    * @var strings
    */
    protected $name;
    protected $version;

    /**
    * Checks for the file existing and stores it
    *
    * @return void
    */
    public function __construct($config, $configpath) {

        // first let's look for our file
        if (!isset($config['filename'])) {
            trigger_error('Gir spec parser requires a filename', E_USER_ERROR);
        }

        // we're going to file_exists for absolute or relative paths
        if(!file_exists($config['filename'])) {
            $check = $configpath . DIRECTORY_SEPARATOR . $config['filename'];
            if(!file_exists($check)) {
                trigger_error('Could not locate filename at '
                              . $config['filename'] . ' or ' . $check , E_USER_ERROR);
            } else {
                $this->file = $check;
            }
        } else {
            $this->file = $config['filename'];
        }

        $reader = $this->reader = new XMLReader();
        $reader->open($this->file);
        $this->module = $config['module'];
        $this->version = $config['version'];
    }

    /**
    * Clean up reader, avoid gc complications
    *
    * @return void
    */
    public function __destruct() {
        if($this->reader) {
            $this->reader->close();
            $this->reader = null;
        }
    }

    /**
    * Returns an array? of information about the extension specification?
    *
    * @return void
    */
    public function parse() {
        // we'll be using these a lot, aliasing it in makes it a wee bit faster
        $reader = $this->reader;
        $cache = $this->cache;

        $module = new Module;
        $module->name = $this->module;
        $module->version = $this->version;

        // Loop our data and fill our objects
        while($reader->read()) {

            // c:include element
            if($reader->nodeType == XMLReader::ELEMENT && $reader->name == 'c:include') {
                $module->headers[] = $reader->getAttribute('name');
            }

            // include element - module deps
            elseif ($reader->nodeType == XMLReader::ELEMENT && $reader->name == 'include') {
                $module->dep[$reader->getAttribute('name')] = $reader->getAttribute('version');
            }

            // namespace element
            elseif ($reader->nodeType == XMLReader::ELEMENT && $reader->name == 'namespace') {
                $module->namespaces[] = $package = new Package;
                $package->name = $reader->getAttribute('name');
                $package->version = $reader->getAttribute('version');

                // oddly enough, shared-library info is here in namespace, not in overall module
                $temp = $reader->getAttribute('shared-library');
                $temp = explode(',', $temp);
                $module->libs += $temp;
            }

            // constant element
            elseif ($reader->nodeType == XMLReader::ELEMENT && $reader->name == 'constant') {
                $package->constant[] = $constant = new Constant;
                $constant->name = $reader->getAttribute('name');
                $constant->def = $reader->getAttribute('c:type');

                do {
                    if($reader->nodeType == XMLReader::ELEMENT && $reader->name == 'type') {
                        $constant->type = $reader->getAttribute('c:type');
                        break;
                    }
                } while($reader->read());
            }
        }

        return $module;
    }
}