/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2012 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Elizabeth M Smith <auroraeosrose@gmail.com>                  |
  +----------------------------------------------------------------------+
*/

#include "php_glib.h"

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(glib)
{
	PHP_MINIT(glib_0)(INIT_FUNC_ARGS_PASSTHRU);

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(glib)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "glib extension", "enabled");
	php_info_print_table_row(2, "Extension Version", PHP_GLIB_VERSION);
	php_info_print_table_row(2, "Generated with G\Generator on 2012-08-23", "0.1.0-dev");
	php_info_print_table_end();
}
/* }}} */

/* {{{ glib_module_entry */
zend_module_entry glib_module_entry = {
	STANDARD_MODULE_HEADER,
	"glib",
	NULL,
	PHP_MINIT(glib),
	NULL,
	NULL,
	NULL,
	PHP_MINFO(glib),
	PHP_GLIB_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_GLIB 
ZEND_GET_MODULE(glib)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */