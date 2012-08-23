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
	PHP_MINIT(glib_Array)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_AsyncQueue)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_BookmarkFile)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_ByteArray)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_Bytes)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_Checksum)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_Cond)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_Data)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_Date)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_DateTime)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_DebugKey)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_Dir)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_DoubleIEEE754)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_Error)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_FloatIEEE754)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_HashTable)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_HashTableIter)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_Hmac)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_Hook)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_HookList)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_IConv)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_IOChannel)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_IOFuncs)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_KeyFile)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_List)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_MainContext)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_MainLoop)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_MappedFile)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_MarkupParseContext)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_MarkupParser)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_MatchInfo)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_MemVTable)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_Mutex)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_Node)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_Once)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_OptionContext)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_OptionEntry)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_OptionGroup)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_PatternSpec)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_PollFD)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_Private)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_PtrArray)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_Queue)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_RWLock)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_Rand)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_RecMutex)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_Regex)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_SList)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_Scanner)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_ScannerConfig)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_Sequence)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_SequenceIter)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_Source)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_SourceCallbackFuncs)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_SourceFuncs)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_SourcePrivate)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_StatBuf)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_String)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_StringChunk)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_TestCase)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_TestConfig)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_TestLogBuffer)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_TestLogMsg)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_TestSuite)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_Thread)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_ThreadPool)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_TimeVal)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_TimeZone)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_Timer)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_TokenValue)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_TrashStack)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_Tree)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_Variant)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_VariantBuilder)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_VariantType)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(glib_Enums)(INIT_FUNC_ARGS_PASSTHRU);

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