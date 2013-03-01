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
use XMLReader;
use Iterator;
use SimpleXMLElement;

/**
* Uses xml format for Gobject Introspection to parse stuff
*/
class Gir implements Iterator {

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
     * Iteration implementation detail, do not use
    *  @var string
     */
    private $itemName;
    private $read;
    private $counter = 0;
    private $current;

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
    }

    function rewind() {
        $this->reader->open($this->file);
        $this->counter = $this->read = 0;
        $this->current = NULL;
        $this->next();
    }

    function current() {
        return $this->current;
    }

    function key() {
        return $this->counter;
    }

    function next() {
        if (!$this->itemName) {
            $this->reader->read(); // root element?
            do {
                $this->reader->read(); // item
                $this->itemName = $this->xmlReader->name;
             
            } while ($this->itemName === '#text' && $this->itemName);
        }
         
        if ($this->current) {
            $this->reader->next($this->itemName);
        }
         
        if ($element = $this->reader->readOuterXML()) {
            $this->read += strlen($element);
            $this->current = new SimpleXmlElement($element);
         
        } else {
            $this->current = NULL;
        }
         
        $this->counter++;
        return $this->current;
    }

    function valid() {
        return $this->current !== NULL;
    }
}