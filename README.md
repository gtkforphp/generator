G\Generator
=============
This is a collection of scripts for generating or updating a PHP extension to wrap a C library

You can send comments, patches, questions [here on github](https://github.com/gtkforphp/generator/issues)

This is still an experimental extension.

Features
===
The generator is designed to be configurable and extendible.  To create an extension you need two things,
a specification for the extension in a format for which the generator has a parser, and a configuration file
for the extension in a format the generator can read.

There is a template system for C files for generation differences, the default template generates
only for PHP 5.4 at present - additional templates are welcome.

G\Generator can support multiple formats for available for extension specification.  Currently the only
specification available requires the [G\Introspection](https://github.com/gtkforphp/gintrospection) extension 
which can read typelib files created by Gobject Introspection tools.  Additional parsers for specifications are
welcome.

G\Generator can currently read configuration files in .ini format.  Additional parsers for configuration files
are welcome.

G\Generator is designed to generate C files and headers, tests, and even docbook documentation.

G\Generator supports version based declaration and deprecation, and ignoring
items. G\Generator also supports custom function declarations as "overrides" at
generation time, but leaves changes alone during library updates. Besides
initial generation it also supports updating a previously compiled extension
with new or missing definitions.

Usage
=====
ggen is a PHP 5.4 cli application

```
ggen 1.0.0-dev, Copyright (c) 2012 Elizabeth M Smith

Usage:

ggen [-h] [-v] [-q] [-l] [-u] [-n]
  [--extension] [--test] [--docbook] [--stubs] config.filetype

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
  --extension       update or generate only extension files
  --stubs           only generate stubs, do not fill out anything
  --test            file contains prototypes of functions to create
  --docbook         generate xml documentation to be added to phpdoc-cvs
```