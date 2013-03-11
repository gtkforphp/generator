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
use G\Generator\Objects\Klass;
use G\Generator\Objects\Method;
use G\Generator\Objects\Param;
use G\Generator\Objects\RetVal;
use XMLReader;
use Exception;

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
    protected $authors;

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
        $this->authors = $config['authors'];
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
    * Returns an object of information about the extension specification
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
        $module->authors = $this->authors;

        // Loop our data and fill our objects
        while($reader->read()) {

            // package element - for pkg config
            if($reader->nodeType == XMLReader::ELEMENT && $reader->name == 'package') {
                $module->pkgname = $reader->getAttribute('name');
            }

            // c:include element
            elseif($reader->nodeType == XMLReader::ELEMENT && $reader->name == 'c:include') {
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

            // Unions
            elseif ($reader->nodeType == XMLReader::ELEMENT && $reader->name == 'union' && $reader->isEmptyElement == false) {
                $this->parseUnion();
            }

            // Struct fake objects
            elseif ($reader->nodeType == XMLReader::ELEMENT && $reader->name == 'record' && $reader->isEmptyElement == false) {
                $package->classes[] = $this->parseStructClass();
            }
        }

        return $module;
    }

    /**
    * Parse through 
    *
    * @return void
    */
    protected function parseStructClass() {
        $reader = $this->reader; // alias in local

        $class = new Klass;
        $class->name = $reader->getAttribute('name');
        $class->type = $reader->getAttribute('c:type');
        if($reader->getAttribute('disguised') == 1) {
            //$class->type .= '*';
        }

        do {
            if($reader->nodeType == XMLReader::ELEMENT && $reader->name == 'function') {
                // try to parse the function as a normal one, otherwise use it for a createobject handler
                try {
                    $class->methods[] = $this->parseFunctionAsMethod($class);
                } catch (CreateObjectHandlerException $e) {
                    $class->createHandler = $e->method->identifier;
                }
            } elseif($reader->nodeType == XMLReader::ELEMENT && $reader->name == 'method') {
                // try to parse the function as a normal one, otherwise use it for a freeobject handler
                try {
                    $class->methods[] = $this->parseMethod($class->name);
                } catch (FreeObjectHandlerException $e) {
                    $class->freeHandler = $e->method->identifier;
                }
            // this will get a doc node if it exists
            } elseif($reader->nodeType == XMLReader::ELEMENT && $reader->name == 'doc') {
                $class->doc = $reader->readString();
            // this will ALWAYS stop our loop
            } elseif($reader->nodeType == XMLReader::END_ELEMENT && $reader->name == 'record') {
                break;
            }
        } while($reader->read());

        return $class;
    }

    /**
    * Grabs methods and their associated data
    *
    * @return void
    */
    protected function parseMethod() {
        $reader = $this->reader; // alias in local

        $method = new Method;
        $method->name = $this->mangleMethodName($reader->getAttribute('name'));
        $method->identifier = $reader->getAttribute('c:identifier');
        if($reader->getAttribute('throws')) {
            $method->throws = 1;
        }

        do {
            // parameter handling goes here
            if($reader->nodeType == XMLReader::ELEMENT && $reader->name == 'parameter') {
                $method->args[] = $this->parseParameter();
            // if return-type name == the class name this is a constructor
            } elseif($reader->nodeType == XMLReader::ELEMENT && $reader->name == 'return-value') {
                $method->returnValue = $this->parseReturn();
            // this will get a doc node if it exists
            } elseif($reader->nodeType == XMLReader::ELEMENT && $reader->name == 'doc') {
                $method->doc = $reader->readString();
            // this will ALWAYS stop our loop
            } elseif($reader->nodeType == XMLReader::END_ELEMENT && $reader->name == 'method') {
                break;
            }
        } while($reader->read());

        /* if the name of the method is ONLY free or destroy - this is a free */
        if (empty($method->args) && $method->name === 'free' || $method->name === 'destroy') {
            $e = new FreeObjectHandlerException();
            $e->method = $method;
            throw $e;
        }

        return $method;
    }

    /**
    * Functions might really be methods - which is annoying
    *
    * @return void
    */
    protected function parseFunctionAsMethod(Klass $class) {
        $reader = $this->reader; // alias in local

        $method = new Method;
        $method->name = $this->mangleMethodName($reader->getAttribute('name'));
        $method->identifier = $reader->getAttribute('c:identifier');

        do {
            // if return-type name == the class name this is a constructor
             if($reader->nodeType == XMLReader::ELEMENT && $reader->name == 'return-value') {
                $method->returnValue = $this->parseReturn();
                // constructor guessing - new, alloc
                if($class->hasConstructor == false && $class->name === $method->returnValue->type &&
                   (stripos($method->name, 'new') === 0 ||
                    stripos($method->name, 'alloc') === 0)) {
                    $method->isConstructor = true;
                    $method->name = '__construct';
                    $class->hasConstructor = true;
                }
            // parameter handling goes here
            } elseif($reader->nodeType == XMLReader::ELEMENT && $reader->name == 'parameter') {
                $method->args[] = $this->parseParameter();
            // this will get a doc node if it exists
             } elseif($reader->nodeType == XMLReader::ELEMENT && $reader->name == 'doc') {
                $method->doc = $reader->readString();
            // this will ALWAYS stop our loop
            } elseif($reader->nodeType == XMLReader::END_ELEMENT && $reader->name == 'function') {
                break;
            }
        } while($reader->read());

        /* There is a special case here, if the method is a constructor, and the constructor takes no arguments
         * then we want the construct to happen in the create object handler instead
         */
        if ($method->isConstructor && empty($method->args)) {
            $e = new CreateObjectHandlerException();
            $e->method = $method;
            throw $e;
        }

        return $method;
    }

    /**
    * Functions might really be methods - which is annoying
    *
    * @return void
    */
    protected function parseParameter() {
        $reader = $this->reader; // alias in local

        $param = new Param;
        $param->name = $reader->getAttribute('name');
        $param->transfer = $reader->getAttribute('transfer-ownership');
        // get rid of "floating" transfer
        if($param->transfer == 'floating') {
            $param->transfer == 'none';
        }
        if($dir = $reader->getAttribute('direction')) {
            $param->direction = $dir;
        }

        do {
            if($reader->nodeType == XMLReader::ELEMENT && $reader->name == 'array') {
                $param->container = $reader->getAttribute('c:type');
            } elseif($reader->nodeType == XMLReader::ELEMENT && $reader->name == 'type') {
                $param->nativeType = $reader->getAttribute('c:type');
                $param->type = $reader->getAttribute('name');
                $this->mapType($param);
             } elseif($reader->nodeType == XMLReader::ELEMENT && $reader->name == 'doc') {
                $param->doc = $reader->readString();
            // this will ALWAYS stop our loop
            } elseif($reader->nodeType == XMLReader::END_ELEMENT && $reader->name == 'parameter') {
                break;
            }
        } while($reader->read());

        return $param;
    }

    /**
    * Return value information
    *
    * @return void
    */
    protected function parseReturn() {
        $reader = $this->reader; // alias in local

        $retval = new RetVal;

        do {
            if($reader->nodeType == XMLReader::ELEMENT && $reader->name == 'type') {
                $retval->nativeType = $reader->getAttribute('c:type');
                $retval->type = $reader->getAttribute('name');
            /*} elseif($reader->nodeType == XMLReader::ELEMENT && $reader->name == 'array') {
                $retval->nativeType = $reader->getAttribute('c:type');
                $retval->type = $reader->getAttribute('name');
                do {
                    if($reader->nodeType == XMLReader::END_ELEMENT && $reader->name == 'array') {
                        break;
                    }
                } while($reader->read()); */
             } elseif($reader->nodeType == XMLReader::ELEMENT && $reader->name == 'doc') {
                $retval->doc .= $reader->readString();
            // this will ALWAYS stop our loop
            } elseif($reader->nodeType == XMLReader::END_ELEMENT && $reader->name == 'return-value') {
                break;
            }
        } while($reader->read());

        if($retval->type == 'none' && $retval->nativeType == 'void') {
            return null;
        }

        $this->mapReturn($retval);

        return $retval;
    }

    /**
    * I have no idea what I'm going to do with unions yet! but I need
    * to swallow them since they have records inside (silly xml)
    *
    * @return void
    */
    protected function parseUnion() {
        $reader = $this->reader; // alias in local

        do {
            // this will ALWAYS stop our loop
            if($reader->nodeType == XMLReader::END_ELEMENT && $reader->name == 'union') {
                break;
            }
        } while($reader->read());

        return;
    }

    /**
    * mangle glib/gobject/gtk method names so instead of blah_blah they are blahBlah
    *
    * @return string
    */
    protected function mangleMethodName($name) {
        // explode on _
        $parts = explode('_', $name);
        // beginning of name is lowercase
        $name = strtolower(array_shift($parts));
        // if our parts count is now 0, return
        if(count($parts) < 1) {
            return $name;
        }
        // strtolower the rest
        $parts = array_map('strtolower', $parts);
        // camelcase it
        $parts = array_map('ucfirst', $parts);
        return $name . implode($parts);
    }

    /**
    * Map a glib/gobject type to a PHP type for param
    *
    * @return array?
    */
    protected function mapType(Param $param) {
        switch($param->type) {
            case 'gboolean':
                $param->zppSpec = 'b';
                $param->zppType = 'zend_bool';
                $param->ztype = 'bool';
                return;
            case 'guint':
            case 'guint64': // NOTE: may need to do this as a string!
            case 'glong':
            case 'gsize':
            case 'guint8':
            case 'gssize':
            case 'gint64':
            case 'guint32':
            case 'gdouble':
            case 'gulong':
            case 'gint32':
            case 'gint':
                $param->zppSpec = 'l';
                $param->zppType = 'long';
                $param->ztype = 'int';
                return;
            case 'utf8':
            case 'gchar':
                $param->zppSpec = 's';
                $param->zppType = ['char *', 'int'];
                return;
            case 'gpointer':
                echo "have no idea what to do with gpointer omg\n";
                return;
            case 'DestroyNotify':
            case 'CompareFunc':
            case 'CompareDataFunc':
            case 'HRFunc':
            case 'HFunc':
            case 'HashFunc':
            case 'EqualFunc':
            case 'HookFindFunc':
            case 'HookCompareFunc':
            case 'HookMarshaller':
            case 'HookCheckMarshaller':
            case 'Func':
            case 'SourceFuncs':
            case 'SourceFunc':
            case 'PollFunc':
            case 'NodeForeachFunc':
            case 'CopyFunc':
            case 'NodeTraverseFunc':
            case 'ThreadFunc':
            case 'TranslateFunc':
            case 'OptionErrorFunc':
            case 'OptionParseFunc':
            case 'RegexEvalCallback':
            case 'SequenceIterCompareFunc':
            case 'SourceCallbackFuncs':
            case 'TraverseFunc':
            case 'Variant':
                echo "I believe this is a callback - that'll be fun\n";
                return;
            case 'TimeVal':
            case 'Bytes':
            case 'ChecksumType':
            case 'Mutex':
            case 'Date':
            case 'DateDay':
            case 'DateMonth':
            case 'DateYear':
            case 'Time':
            case 'DateWeekday':
            case 'TimeSpan':
            case 'DateTime':
            case 'TimeZone':
            case 'Quark':
            case 'GLib.HashTable':
            case 'Hook':
            case 'HookList':
            case 'String':
            case 'GLib.List':
            case 'MarkupParser':
            case 'Node':
            case 'OptionGroup':
            case 'OptionEntry':
            case 'PatternSpec':
            case 'MatchInfo':
            case 'GLib.SList':
            case 'ScannerConfig':
            case 'SequenceIter':
            case 'Source':
            case 'MainContext':
            case 'TestCase':
            case 'TestSuite':
            case 'TrashStack':
                echo "and I think this is an object\n";
                return;
            case 'filename':
                echo "no clue at all what THIS is\n";
                return;
            case 'gunichar':
                echo "hmm, this one is weird\n";
                return;
            case 'SeekType':
            case 'IOFlags':
            case 'KeyFileFlags':
            case 'PollFD':
            case 'Cond':
            case 'MarkupParseFlags':
            case 'TraverseFlags':
            case 'TraverseType':
            case 'RegexMatchFlags':
            case 'RegexCompileFlags':
            case 'TokenType':
            case 'TimeType':
            case 'VariantType':
                echo "this might be an enum!\n";
                return;
            case 'va_list':
                echo "this one is going to be fun *\n";
                return;
            default:
                throw new UnknownTypeException($param->type . $param->identifer);
        }
    }

    /**
    * Map a glib/gobject type to a PHP type for return
    *
    * @return array?
    */
    protected function mapReturn(Retval $retval) {
        switch($retval->type) {
            case 'gboolean':
                $retval->ztype = 'bool';
                return;
            case 'guint':
            case 'guint64': // NOTE: may need to do this as a string!
            case 'glong':
            case 'gsize':
            case 'guint8':
            case 'gssize':
            case 'gint64':
            case 'guint32':
            case 'gdouble':
            case 'gulong':
            case 'gint32':
            case 'gint':
                $retval->ztype = 'int';
                return;
            case 'utf8':
            case 'gchar':
                $retval->ztype = 'string';
                return;
            case 'gpointer':
                echo "have no idea what to do with gpointer omg\n";
                return;
            default:
                //var_dump($retval);
                //throw new UnknownTypeException($retval->type . $retval->nativeType);
        }
    }
}

/**
 * Custom Exceptions used to tell if function is really cdata manipulator
 */
class CreateObjectHandlerException extends Exception {}
class FreeObjectHandlerException extends Exception {}
class UnknownTypeException extends Exception {}