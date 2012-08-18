#GIG - Gobject Introspection Generator
##Introduction
A collection of scripts for generating or updating a PHP extension from a specification in multiple formats

##Features
Gig is highly configuratble and extensible.  An extension will need a configuration file and specification
information.  There is a template system for C files for generation differences, the default template generates
only for PHP 5.4 at present.  GIG supports multiple formats available for extension specification
including Gobject Introspection xml, and Gobject Introspection compiled.  Gig supports multiple formats for
extension configuration.  Gig will generate appropriate build information, files, tests and 
docbook documentation.  Gig supports version based declaration and deprecation.  Gig also upports custom function
declarations as "overrides" at generation time, but leaves changes alone during library updates.
Besides initial generation gig also supports updating a previously compiled extension.

##Usage
Gig is a PHP 5.4 cli application.  Besides the basic extensions it requires  

{
gig 1.0.0-dev, Copyright (c) 2012 Elizabeth M Smith

Usage:

gig [-h] [-v] [-q] [--lint] [--extname=name] [--proto=file] [--skel=dir] [--stubs=file] 
  [--no-help] [--xml[=file]] [--full-xml] [--function=proto] [config.type]

  -h|--help          this message
  -v|--version       show version info
  -q|--quiet         suppress all output

  the following options are related to module information
  -l|--lint          check the configuration and specification syntax
  -u|--update        update the extension, do not overwrite existing files
                     this is implicit if the location specified in the config
                     is not empty
  -n|--new           ignore existing files and create a new extension
                     this is implicit if the location specified in the config
                     is empty

  the following options control what is generated or updated
  --extname=module   module is the name of your extension 
  --test       file contains prototypes of functions to create
  --docbook              generate xml documentation to be added to phpdoc-cvs
}

##Configuration Format
By default Gig expects an array of information for configuration of the extension.  Because the base format
is a simple array, adding any kind of parser can be added for configuration files.  Configuration parsers
are chosen by 