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

zend_class_entry *ce_glib_asciitype;
zend_class_entry *ce_glib_bookmarkfileerror;
zend_class_entry *ce_glib_checksumtype;
zend_class_entry *ce_glib_converterror;
zend_class_entry *ce_glib_datedmy;
zend_class_entry *ce_glib_datemonth;
zend_class_entry *ce_glib_dateweekday;
zend_class_entry *ce_glib_errortype;
zend_class_entry *ce_glib_fileerror;
zend_class_entry *ce_glib_filetest;
zend_class_entry *ce_glib_formatsizeflags;
zend_class_entry *ce_glib_hookflagmask;
zend_class_entry *ce_glib_iochannelerror;
zend_class_entry *ce_glib_iocondition;
zend_class_entry *ce_glib_ioerror;
zend_class_entry *ce_glib_ioflags;
zend_class_entry *ce_glib_iostatus;
zend_class_entry *ce_glib_keyfileerror;
zend_class_entry *ce_glib_keyfileflags;
zend_class_entry *ce_glib_loglevelflags;
zend_class_entry *ce_glib_markupcollecttype;
zend_class_entry *ce_glib_markuperror;
zend_class_entry *ce_glib_markupparseflags;
zend_class_entry *ce_glib_normalizemode;
zend_class_entry *ce_glib_oncestatus;
zend_class_entry *ce_glib_optionarg;
zend_class_entry *ce_glib_optionerror;
zend_class_entry *ce_glib_optionflags;
zend_class_entry *ce_glib_regexcompileflags;
zend_class_entry *ce_glib_regexerror;
zend_class_entry *ce_glib_regexmatchflags;
zend_class_entry *ce_glib_seektype;
zend_class_entry *ce_glib_shellerror;
zend_class_entry *ce_glib_sliceconfig;
zend_class_entry *ce_glib_spawnerror;
zend_class_entry *ce_glib_spawnflags;
zend_class_entry *ce_glib_testlogtype;
zend_class_entry *ce_glib_testtrapflags;
zend_class_entry *ce_glib_threaderror;
zend_class_entry *ce_glib_timetype;
zend_class_entry *ce_glib_tokentype;
zend_class_entry *ce_glib_traverseflags;
zend_class_entry *ce_glib_traversetype;
zend_class_entry *ce_glib_unicodebreaktype;
zend_class_entry *ce_glib_unicodescript;
zend_class_entry *ce_glib_unicodetype;
zend_class_entry *ce_glib_userdirectory;
zend_class_entry *ce_glib_variantclass;
zend_class_entry *ce_glib_variantparseerror;

/* ----------------------------------------------------------------
    All GLIB enums Definition and registration
------------------------------------------------------------------*/

PHP_MINIT_FUNCTION(glib_Enums)
{
	zend_class_entry asciitype_ce, bookmarkfileerror_ce, checksumtype_ce, converterror_ce, datedmy_ce;
	zend_class_entry datemonth_ce, dateweekday_ce, errortype_ce, fileerror_ce, filetest_ce;
	zend_class_entry formatsizeflags_ce, hookflagmask_ce, iochannelerror_ce, iocondition_ce, ioerror_ce;
	zend_class_entry ioflags_ce, iostatus_ce, keyfileerror_ce, keyfileflags_ce, loglevelflags_ce;
	zend_class_entry markupcollecttype_ce, markuperror_ce, markupparseflags_ce, normalizemode_ce, oncestatus_ce;
	zend_class_entry optionarg_ce, optionerror_ce, optionflags_ce, regexcompileflags_ce, regexerror_ce;
	zend_class_entry regexmatchflags_ce, seektype_ce, shellerror_ce, sliceconfig_ce, spawnerror_ce;
	zend_class_entry spawnflags_ce, testlogtype_ce, testtrapflags_ce, threaderror_ce, timetype_ce;
	zend_class_entry tokentype_ce, traverseflags_ce, traversetype_ce, unicodebreaktype_ce, unicodescript_ce;
	zend_class_entry unicodetype_ce, userdirectory_ce, variantclass_ce, variantparseerror_ce;

	INIT_NS_CLASS_ENTRY(asciitype_ce, GLIB_NAMESPACE, "AsciiType", NULL);
	ce_glib_asciitype = zend_register_internal_class_ex(&asciitype_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("ALNUM", G_ASCII_ALNUM, ce_glib_asciitype);
	REGISTER_ENUM_CONST("ALPHA", G_ASCII_ALPHA, ce_glib_asciitype);
	REGISTER_ENUM_CONST("CNTRL", G_ASCII_CNTRL, ce_glib_asciitype);
	REGISTER_ENUM_CONST("DIGIT", G_ASCII_DIGIT, ce_glib_asciitype);
	REGISTER_ENUM_CONST("GRAPH", G_ASCII_GRAPH, ce_glib_asciitype);
	REGISTER_ENUM_CONST("LOWER", G_ASCII_LOWER, ce_glib_asciitype);
	REGISTER_ENUM_CONST("PRINT", G_ASCII_PRINT, ce_glib_asciitype);
	REGISTER_ENUM_CONST("PUNCT", G_ASCII_PUNCT, ce_glib_asciitype);
	REGISTER_ENUM_CONST("SPACE", G_ASCII_SPACE, ce_glib_asciitype);
	REGISTER_ENUM_CONST("UPPER", G_ASCII_UPPER, ce_glib_asciitype);
	REGISTER_ENUM_CONST("XDIGIT", G_ASCII_XDIGIT, ce_glib_asciitype);

	INIT_NS_CLASS_ENTRY(bookmarkfileerror_ce, GLIB_NAMESPACE, "BookmarkFileError", NULL);
	ce_glib_bookmarkfileerror = zend_register_internal_class_ex(&bookmarkfileerror_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("INVALID_URI", G_BOOKMARK_FILE_ERROR_INVALID_URI, ce_glib_bookmarkfileerror);
	REGISTER_ENUM_CONST("INVALID_VALUE", G_BOOKMARK_FILE_ERROR_INVALID_VALUE, ce_glib_bookmarkfileerror);
	REGISTER_ENUM_CONST("APP_NOT_REGISTERED", G_BOOKMARK_FILE_ERROR_APP_NOT_REGISTERED, ce_glib_bookmarkfileerror);
	REGISTER_ENUM_CONST("URI_NOT_FOUND", G_BOOKMARK_FILE_ERROR_URI_NOT_FOUND, ce_glib_bookmarkfileerror);
	REGISTER_ENUM_CONST("READ", G_BOOKMARK_FILE_ERROR_READ, ce_glib_bookmarkfileerror);
	REGISTER_ENUM_CONST("UNKNOWN_ENCODING", G_BOOKMARK_FILE_ERROR_UNKNOWN_ENCODING, ce_glib_bookmarkfileerror);
	REGISTER_ENUM_CONST("WRITE", G_BOOKMARK_FILE_ERROR_WRITE, ce_glib_bookmarkfileerror);
	REGISTER_ENUM_CONST("FILE_NOT_FOUND", G_BOOKMARK_FILE_ERROR_FILE_NOT_FOUND, ce_glib_bookmarkfileerror);

	INIT_NS_CLASS_ENTRY(checksumtype_ce, GLIB_NAMESPACE, "ChecksumType", NULL);
	ce_glib_checksumtype = zend_register_internal_class_ex(&checksumtype_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("MD5", G_CHECKSUM_MD5, ce_glib_checksumtype);
	REGISTER_ENUM_CONST("SHA1", G_CHECKSUM_SHA1, ce_glib_checksumtype);
	REGISTER_ENUM_CONST("SHA256", G_CHECKSUM_SHA256, ce_glib_checksumtype);

	INIT_NS_CLASS_ENTRY(converterror_ce, GLIB_NAMESPACE, "ConvertError", NULL);
	ce_glib_converterror = zend_register_internal_class_ex(&converterror_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("NO_CONVERSION", G_CONVERT_ERROR_NO_CONVERSION, ce_glib_converterror);
	REGISTER_ENUM_CONST("ILLEGAL_SEQUENCE", G_CONVERT_ERROR_ILLEGAL_SEQUENCE, ce_glib_converterror);
	REGISTER_ENUM_CONST("FAILED", G_CONVERT_ERROR_FAILED, ce_glib_converterror);
	REGISTER_ENUM_CONST("PARTIAL_INPUT", G_CONVERT_ERROR_PARTIAL_INPUT, ce_glib_converterror);
	REGISTER_ENUM_CONST("BAD_URI", G_CONVERT_ERROR_BAD_URI, ce_glib_converterror);
	REGISTER_ENUM_CONST("NOT_ABSOLUTE_PATH", G_CONVERT_ERROR_NOT_ABSOLUTE_PATH, ce_glib_converterror);

	INIT_NS_CLASS_ENTRY(datedmy_ce, GLIB_NAMESPACE, "DateDMY", NULL);
	ce_glib_datedmy = zend_register_internal_class_ex(&datedmy_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("DAY", G_DATE_DAY, ce_glib_datedmy);
	REGISTER_ENUM_CONST("MONTH", G_DATE_MONTH, ce_glib_datedmy);
	REGISTER_ENUM_CONST("YEAR", G_DATE_YEAR, ce_glib_datedmy);

	INIT_NS_CLASS_ENTRY(datemonth_ce, GLIB_NAMESPACE, "DateMonth", NULL);
	ce_glib_datemonth = zend_register_internal_class_ex(&datemonth_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("BAD_MONTH", G_DATE_BAD_MONTH, ce_glib_datemonth);
	REGISTER_ENUM_CONST("JANUARY", G_DATE_JANUARY, ce_glib_datemonth);
	REGISTER_ENUM_CONST("FEBRUARY", G_DATE_FEBRUARY, ce_glib_datemonth);
	REGISTER_ENUM_CONST("MARCH", G_DATE_MARCH, ce_glib_datemonth);
	REGISTER_ENUM_CONST("APRIL", G_DATE_APRIL, ce_glib_datemonth);
	REGISTER_ENUM_CONST("MAY", G_DATE_MAY, ce_glib_datemonth);
	REGISTER_ENUM_CONST("JUNE", G_DATE_JUNE, ce_glib_datemonth);
	REGISTER_ENUM_CONST("JULY", G_DATE_JULY, ce_glib_datemonth);
	REGISTER_ENUM_CONST("AUGUST", G_DATE_AUGUST, ce_glib_datemonth);
	REGISTER_ENUM_CONST("SEPTEMBER", G_DATE_SEPTEMBER, ce_glib_datemonth);
	REGISTER_ENUM_CONST("OCTOBER", G_DATE_OCTOBER, ce_glib_datemonth);
	REGISTER_ENUM_CONST("NOVEMBER", G_DATE_NOVEMBER, ce_glib_datemonth);
	REGISTER_ENUM_CONST("DECEMBER", G_DATE_DECEMBER, ce_glib_datemonth);

	INIT_NS_CLASS_ENTRY(dateweekday_ce, GLIB_NAMESPACE, "DateWeekday", NULL);
	ce_glib_dateweekday = zend_register_internal_class_ex(&dateweekday_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("BAD_WEEKDAY", G_DATE_BAD_WEEKDAY, ce_glib_dateweekday);
	REGISTER_ENUM_CONST("MONDAY", G_DATE_MONDAY, ce_glib_dateweekday);
	REGISTER_ENUM_CONST("TUESDAY", G_DATE_TUESDAY, ce_glib_dateweekday);
	REGISTER_ENUM_CONST("WEDNESDAY", G_DATE_WEDNESDAY, ce_glib_dateweekday);
	REGISTER_ENUM_CONST("THURSDAY", G_DATE_THURSDAY, ce_glib_dateweekday);
	REGISTER_ENUM_CONST("FRIDAY", G_DATE_FRIDAY, ce_glib_dateweekday);
	REGISTER_ENUM_CONST("SATURDAY", G_DATE_SATURDAY, ce_glib_dateweekday);
	REGISTER_ENUM_CONST("SUNDAY", G_DATE_SUNDAY, ce_glib_dateweekday);

	INIT_NS_CLASS_ENTRY(errortype_ce, GLIB_NAMESPACE, "ErrorType", NULL);
	ce_glib_errortype = zend_register_internal_class_ex(&errortype_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("UNKNOWN", G_ERR_UNKNOWN, ce_glib_errortype);
	REGISTER_ENUM_CONST("UNEXP_EOF", G_ERR_UNEXP_EOF, ce_glib_errortype);
	REGISTER_ENUM_CONST("UNEXP_EOF_IN_STRING", G_ERR_UNEXP_EOF_IN_STRING, ce_glib_errortype);
	REGISTER_ENUM_CONST("UNEXP_EOF_IN_COMMENT", G_ERR_UNEXP_EOF_IN_COMMENT, ce_glib_errortype);
	REGISTER_ENUM_CONST("NON_DIGIT_IN_CONST", G_ERR_NON_DIGIT_IN_CONST, ce_glib_errortype);
	REGISTER_ENUM_CONST("DIGIT_RADIX", G_ERR_DIGIT_RADIX, ce_glib_errortype);
	REGISTER_ENUM_CONST("FLOAT_RADIX", G_ERR_FLOAT_RADIX, ce_glib_errortype);
	REGISTER_ENUM_CONST("FLOAT_MALFORMED", G_ERR_FLOAT_MALFORMED, ce_glib_errortype);

	INIT_NS_CLASS_ENTRY(fileerror_ce, GLIB_NAMESPACE, "FileError", NULL);
	ce_glib_fileerror = zend_register_internal_class_ex(&fileerror_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("EXIST", G_FILE_ERROR_EXIST, ce_glib_fileerror);
	REGISTER_ENUM_CONST("ISDIR", G_FILE_ERROR_ISDIR, ce_glib_fileerror);
	REGISTER_ENUM_CONST("ACCES", G_FILE_ERROR_ACCES, ce_glib_fileerror);
	REGISTER_ENUM_CONST("NAMETOOLONG", G_FILE_ERROR_NAMETOOLONG, ce_glib_fileerror);
	REGISTER_ENUM_CONST("NOENT", G_FILE_ERROR_NOENT, ce_glib_fileerror);
	REGISTER_ENUM_CONST("NOTDIR", G_FILE_ERROR_NOTDIR, ce_glib_fileerror);
	REGISTER_ENUM_CONST("NXIO", G_FILE_ERROR_NXIO, ce_glib_fileerror);
	REGISTER_ENUM_CONST("NODEV", G_FILE_ERROR_NODEV, ce_glib_fileerror);
	REGISTER_ENUM_CONST("ROFS", G_FILE_ERROR_ROFS, ce_glib_fileerror);
	REGISTER_ENUM_CONST("TXTBSY", G_FILE_ERROR_TXTBSY, ce_glib_fileerror);
	REGISTER_ENUM_CONST("FAULT", G_FILE_ERROR_FAULT, ce_glib_fileerror);
	REGISTER_ENUM_CONST("LOOP", G_FILE_ERROR_LOOP, ce_glib_fileerror);
	REGISTER_ENUM_CONST("NOSPC", G_FILE_ERROR_NOSPC, ce_glib_fileerror);
	REGISTER_ENUM_CONST("NOMEM", G_FILE_ERROR_NOMEM, ce_glib_fileerror);
	REGISTER_ENUM_CONST("MFILE", G_FILE_ERROR_MFILE, ce_glib_fileerror);
	REGISTER_ENUM_CONST("NFILE", G_FILE_ERROR_NFILE, ce_glib_fileerror);
	REGISTER_ENUM_CONST("BADF", G_FILE_ERROR_BADF, ce_glib_fileerror);
	REGISTER_ENUM_CONST("INVAL", G_FILE_ERROR_INVAL, ce_glib_fileerror);
	REGISTER_ENUM_CONST("PIPE", G_FILE_ERROR_PIPE, ce_glib_fileerror);
	REGISTER_ENUM_CONST("AGAIN", G_FILE_ERROR_AGAIN, ce_glib_fileerror);
	REGISTER_ENUM_CONST("INTR", G_FILE_ERROR_INTR, ce_glib_fileerror);
	REGISTER_ENUM_CONST("IO", G_FILE_ERROR_IO, ce_glib_fileerror);
	REGISTER_ENUM_CONST("PERM", G_FILE_ERROR_PERM, ce_glib_fileerror);
	REGISTER_ENUM_CONST("NOSYS", G_FILE_ERROR_NOSYS, ce_glib_fileerror);
	REGISTER_ENUM_CONST("FAILED", G_FILE_ERROR_FAILED, ce_glib_fileerror);

	INIT_NS_CLASS_ENTRY(filetest_ce, GLIB_NAMESPACE, "FileTest", NULL);
	ce_glib_filetest = zend_register_internal_class_ex(&filetest_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("IS_REGULAR", G_FILE_TEST_IS_REGULAR, ce_glib_filetest);
	REGISTER_ENUM_CONST("IS_SYMLINK", G_FILE_TEST_IS_SYMLINK, ce_glib_filetest);
	REGISTER_ENUM_CONST("IS_DIR", G_FILE_TEST_IS_DIR, ce_glib_filetest);
	REGISTER_ENUM_CONST("IS_EXECUTABLE", G_FILE_TEST_IS_EXECUTABLE, ce_glib_filetest);
	REGISTER_ENUM_CONST("EXISTS", G_FILE_TEST_EXISTS, ce_glib_filetest);

	INIT_NS_CLASS_ENTRY(formatsizeflags_ce, GLIB_NAMESPACE, "FormatSizeFlags", NULL);
	ce_glib_formatsizeflags = zend_register_internal_class_ex(&formatsizeflags_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("DEFAULT", G_FORMAT_SIZE_DEFAULT, ce_glib_formatsizeflags);
	REGISTER_ENUM_CONST("LONG_FORMAT", G_FORMAT_SIZE_LONG_FORMAT, ce_glib_formatsizeflags);
	REGISTER_ENUM_CONST("IEC_UNITS", G_FORMAT_SIZE_IEC_UNITS, ce_glib_formatsizeflags);

	INIT_NS_CLASS_ENTRY(hookflagmask_ce, GLIB_NAMESPACE, "HookFlagMask", NULL);
	ce_glib_hookflagmask = zend_register_internal_class_ex(&hookflagmask_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("ACTIVE", G_HOOK_FLAG_ACTIVE, ce_glib_hookflagmask);
	REGISTER_ENUM_CONST("IN_CALL", G_HOOK_FLAG_IN_CALL, ce_glib_hookflagmask);
	REGISTER_ENUM_CONST("MASK", G_HOOK_FLAG_MASK, ce_glib_hookflagmask);

	INIT_NS_CLASS_ENTRY(iochannelerror_ce, GLIB_NAMESPACE, "IOChannelError", NULL);
	ce_glib_iochannelerror = zend_register_internal_class_ex(&iochannelerror_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("FBIG", G_IO_CHANNEL_ERROR_FBIG, ce_glib_iochannelerror);
	REGISTER_ENUM_CONST("INVAL", G_IO_CHANNEL_ERROR_INVAL, ce_glib_iochannelerror);
	REGISTER_ENUM_CONST("IO", G_IO_CHANNEL_ERROR_IO, ce_glib_iochannelerror);
	REGISTER_ENUM_CONST("ISDIR", G_IO_CHANNEL_ERROR_ISDIR, ce_glib_iochannelerror);
	REGISTER_ENUM_CONST("NOSPC", G_IO_CHANNEL_ERROR_NOSPC, ce_glib_iochannelerror);
	REGISTER_ENUM_CONST("NXIO", G_IO_CHANNEL_ERROR_NXIO, ce_glib_iochannelerror);
	REGISTER_ENUM_CONST("OVERFLOW", G_IO_CHANNEL_ERROR_OVERFLOW, ce_glib_iochannelerror);
	REGISTER_ENUM_CONST("PIPE", G_IO_CHANNEL_ERROR_PIPE, ce_glib_iochannelerror);
	REGISTER_ENUM_CONST("FAILED", G_IO_CHANNEL_ERROR_FAILED, ce_glib_iochannelerror);

	INIT_NS_CLASS_ENTRY(iocondition_ce, GLIB_NAMESPACE, "IOCondition", NULL);
	ce_glib_iocondition = zend_register_internal_class_ex(&iocondition_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("IN", G_IO_IN, ce_glib_iocondition);
	REGISTER_ENUM_CONST("OUT", G_IO_OUT, ce_glib_iocondition);
	REGISTER_ENUM_CONST("PRI", G_IO_PRI, ce_glib_iocondition);
	REGISTER_ENUM_CONST("ERR", G_IO_ERR, ce_glib_iocondition);
	REGISTER_ENUM_CONST("HUP", G_IO_HUP, ce_glib_iocondition);
	REGISTER_ENUM_CONST("NVAL", G_IO_NVAL, ce_glib_iocondition);

	INIT_NS_CLASS_ENTRY(ioerror_ce, GLIB_NAMESPACE, "IOError", NULL);
	ce_glib_ioerror = zend_register_internal_class_ex(&ioerror_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("NONE", G_IO_ERROR_NONE, ce_glib_ioerror);
	REGISTER_ENUM_CONST("AGAIN", G_IO_ERROR_AGAIN, ce_glib_ioerror);
	REGISTER_ENUM_CONST("INVAL", G_IO_ERROR_INVAL, ce_glib_ioerror);
	REGISTER_ENUM_CONST("UNKNOWN", G_IO_ERROR_UNKNOWN, ce_glib_ioerror);

	INIT_NS_CLASS_ENTRY(ioflags_ce, GLIB_NAMESPACE, "IOFlags", NULL);
	ce_glib_ioflags = zend_register_internal_class_ex(&ioflags_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("APPEND", G_IO_FLAG_APPEND, ce_glib_ioflags);
	REGISTER_ENUM_CONST("NONBLOCK", G_IO_FLAG_NONBLOCK, ce_glib_ioflags);
	REGISTER_ENUM_CONST("IS_READABLE", G_IO_FLAG_IS_READABLE, ce_glib_ioflags);
	REGISTER_ENUM_CONST("IS_WRITABLE", G_IO_FLAG_IS_WRITABLE, ce_glib_ioflags);
	REGISTER_ENUM_CONST("IS_SEEKABLE", G_IO_FLAG_IS_SEEKABLE, ce_glib_ioflags);
	REGISTER_ENUM_CONST("MASK", G_IO_FLAG_MASK, ce_glib_ioflags);
	REGISTER_ENUM_CONST("GET_MASK", G_IO_FLAG_GET_MASK, ce_glib_ioflags);
	REGISTER_ENUM_CONST("SET_MASK", G_IO_FLAG_SET_MASK, ce_glib_ioflags);

	INIT_NS_CLASS_ENTRY(iostatus_ce, GLIB_NAMESPACE, "IOStatus", NULL);
	ce_glib_iostatus = zend_register_internal_class_ex(&iostatus_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("ERROR", G_IO_STATUS_ERROR, ce_glib_iostatus);
	REGISTER_ENUM_CONST("NORMAL", G_IO_STATUS_NORMAL, ce_glib_iostatus);
	REGISTER_ENUM_CONST("EOF", G_IO_STATUS_EOF, ce_glib_iostatus);
	REGISTER_ENUM_CONST("AGAIN", G_IO_STATUS_AGAIN, ce_glib_iostatus);

	INIT_NS_CLASS_ENTRY(keyfileerror_ce, GLIB_NAMESPACE, "KeyFileError", NULL);
	ce_glib_keyfileerror = zend_register_internal_class_ex(&keyfileerror_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("UNKNOWN_ENCODING", G_KEY_FILE_ERROR_UNKNOWN_ENCODING, ce_glib_keyfileerror);
	REGISTER_ENUM_CONST("PARSE", G_KEY_FILE_ERROR_PARSE, ce_glib_keyfileerror);
	REGISTER_ENUM_CONST("NOT_FOUND", G_KEY_FILE_ERROR_NOT_FOUND, ce_glib_keyfileerror);
	REGISTER_ENUM_CONST("KEY_NOT_FOUND", G_KEY_FILE_ERROR_KEY_NOT_FOUND, ce_glib_keyfileerror);
	REGISTER_ENUM_CONST("GROUP_NOT_FOUND", G_KEY_FILE_ERROR_GROUP_NOT_FOUND, ce_glib_keyfileerror);
	REGISTER_ENUM_CONST("INVALID_VALUE", G_KEY_FILE_ERROR_INVALID_VALUE, ce_glib_keyfileerror);

	INIT_NS_CLASS_ENTRY(keyfileflags_ce, GLIB_NAMESPACE, "KeyFileFlags", NULL);
	ce_glib_keyfileflags = zend_register_internal_class_ex(&keyfileflags_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("NONE", G_KEY_FILE_NONE, ce_glib_keyfileflags);
	REGISTER_ENUM_CONST("KEEP_COMMENTS", G_KEY_FILE_KEEP_COMMENTS, ce_glib_keyfileflags);
	REGISTER_ENUM_CONST("KEEP_TRANSLATIONS", G_KEY_FILE_KEEP_TRANSLATIONS, ce_glib_keyfileflags);

	INIT_NS_CLASS_ENTRY(loglevelflags_ce, GLIB_NAMESPACE, "LogLevelFlags", NULL);
	ce_glib_loglevelflags = zend_register_internal_class_ex(&loglevelflags_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("FLAG_RECURSION", G_LOG_FLAG_RECURSION, ce_glib_loglevelflags);
	REGISTER_ENUM_CONST("FLAG_FATAL", G_LOG_FLAG_FATAL, ce_glib_loglevelflags);
	REGISTER_ENUM_CONST("LEVEL_ERROR", G_LOG_LEVEL_ERROR, ce_glib_loglevelflags);
	REGISTER_ENUM_CONST("LEVEL_CRITICAL", G_LOG_LEVEL_CRITICAL, ce_glib_loglevelflags);
	REGISTER_ENUM_CONST("LEVEL_WARNING", G_LOG_LEVEL_WARNING, ce_glib_loglevelflags);
	REGISTER_ENUM_CONST("LEVEL_MESSAGE", G_LOG_LEVEL_MESSAGE, ce_glib_loglevelflags);
	REGISTER_ENUM_CONST("LEVEL_INFO", G_LOG_LEVEL_INFO, ce_glib_loglevelflags);
	REGISTER_ENUM_CONST("LEVEL_DEBUG", G_LOG_LEVEL_DEBUG, ce_glib_loglevelflags);
	REGISTER_ENUM_CONST("LEVEL_MASK", G_LOG_LEVEL_MASK, ce_glib_loglevelflags);

	INIT_NS_CLASS_ENTRY(markupcollecttype_ce, GLIB_NAMESPACE, "MarkupCollectType", NULL);
	ce_glib_markupcollecttype = zend_register_internal_class_ex(&markupcollecttype_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("INVALID", G_MARKUP_COLLECT_INVALID, ce_glib_markupcollecttype);
	REGISTER_ENUM_CONST("STRING", G_MARKUP_COLLECT_STRING, ce_glib_markupcollecttype);
	REGISTER_ENUM_CONST("STRDUP", G_MARKUP_COLLECT_STRDUP, ce_glib_markupcollecttype);
	REGISTER_ENUM_CONST("BOOLEAN", G_MARKUP_COLLECT_BOOLEAN, ce_glib_markupcollecttype);
	REGISTER_ENUM_CONST("TRISTATE", G_MARKUP_COLLECT_TRISTATE, ce_glib_markupcollecttype);
	REGISTER_ENUM_CONST("OPTIONAL", G_MARKUP_COLLECT_OPTIONAL, ce_glib_markupcollecttype);

	INIT_NS_CLASS_ENTRY(markuperror_ce, GLIB_NAMESPACE, "MarkupError", NULL);
	ce_glib_markuperror = zend_register_internal_class_ex(&markuperror_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("BAD_UTF8", G_MARKUP_ERROR_BAD_UTF8, ce_glib_markuperror);
	REGISTER_ENUM_CONST("EMPTY", G_MARKUP_ERROR_EMPTY, ce_glib_markuperror);
	REGISTER_ENUM_CONST("PARSE", G_MARKUP_ERROR_PARSE, ce_glib_markuperror);
	REGISTER_ENUM_CONST("UNKNOWN_ELEMENT", G_MARKUP_ERROR_UNKNOWN_ELEMENT, ce_glib_markuperror);
	REGISTER_ENUM_CONST("UNKNOWN_ATTRIBUTE", G_MARKUP_ERROR_UNKNOWN_ATTRIBUTE, ce_glib_markuperror);
	REGISTER_ENUM_CONST("INVALID_CONTENT", G_MARKUP_ERROR_INVALID_CONTENT, ce_glib_markuperror);
	REGISTER_ENUM_CONST("MISSING_ATTRIBUTE", G_MARKUP_ERROR_MISSING_ATTRIBUTE, ce_glib_markuperror);

	INIT_NS_CLASS_ENTRY(markupparseflags_ce, GLIB_NAMESPACE, "MarkupParseFlags", NULL);
	ce_glib_markupparseflags = zend_register_internal_class_ex(&markupparseflags_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("DO_NOT_USE_THIS_UNSUPPORTED_FLAG", G_MARKUP_DO_NOT_USE_THIS_UNSUPPORTED_FLAG, ce_glib_markupparseflags);
	REGISTER_ENUM_CONST("TREAT_CDATA_AS_TEXT", G_MARKUP_TREAT_CDATA_AS_TEXT, ce_glib_markupparseflags);
	REGISTER_ENUM_CONST("PREFIX_ERROR_POSITION", G_MARKUP_PREFIX_ERROR_POSITION, ce_glib_markupparseflags);

	INIT_NS_CLASS_ENTRY(normalizemode_ce, GLIB_NAMESPACE, "NormalizeMode", NULL);
	ce_glib_normalizemode = zend_register_internal_class_ex(&normalizemode_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("DEFAULT", G_NORMALIZE_DEFAULT, ce_glib_normalizemode);
	REGISTER_ENUM_CONST("NFD", G_NORMALIZE_NFD, ce_glib_normalizemode);
	REGISTER_ENUM_CONST("DEFAULT_COMPOSE", G_NORMALIZE_DEFAULT_COMPOSE, ce_glib_normalizemode);
	REGISTER_ENUM_CONST("NFC", G_NORMALIZE_NFC, ce_glib_normalizemode);
	REGISTER_ENUM_CONST("ALL", G_NORMALIZE_ALL, ce_glib_normalizemode);
	REGISTER_ENUM_CONST("NFKD", G_NORMALIZE_NFKD, ce_glib_normalizemode);
	REGISTER_ENUM_CONST("ALL_COMPOSE", G_NORMALIZE_ALL_COMPOSE, ce_glib_normalizemode);
	REGISTER_ENUM_CONST("NFKC", G_NORMALIZE_NFKC, ce_glib_normalizemode);

	INIT_NS_CLASS_ENTRY(oncestatus_ce, GLIB_NAMESPACE, "OnceStatus", NULL);
	ce_glib_oncestatus = zend_register_internal_class_ex(&oncestatus_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("NOTCALLED", G_ONCE_STATUS_NOTCALLED, ce_glib_oncestatus);
	REGISTER_ENUM_CONST("PROGRESS", G_ONCE_STATUS_PROGRESS, ce_glib_oncestatus);
	REGISTER_ENUM_CONST("READY", G_ONCE_STATUS_READY, ce_glib_oncestatus);

	INIT_NS_CLASS_ENTRY(optionarg_ce, GLIB_NAMESPACE, "OptionArg", NULL);
	ce_glib_optionarg = zend_register_internal_class_ex(&optionarg_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("NONE", G_OPTION_ARG_NONE, ce_glib_optionarg);
	REGISTER_ENUM_CONST("STRING", G_OPTION_ARG_STRING, ce_glib_optionarg);
	REGISTER_ENUM_CONST("INT", G_OPTION_ARG_INT, ce_glib_optionarg);
	REGISTER_ENUM_CONST("CALLBACK", G_OPTION_ARG_CALLBACK, ce_glib_optionarg);
	REGISTER_ENUM_CONST("FILENAME", G_OPTION_ARG_FILENAME, ce_glib_optionarg);
	REGISTER_ENUM_CONST("STRING_ARRAY", G_OPTION_ARG_STRING_ARRAY, ce_glib_optionarg);
	REGISTER_ENUM_CONST("FILENAME_ARRAY", G_OPTION_ARG_FILENAME_ARRAY, ce_glib_optionarg);
	REGISTER_ENUM_CONST("DOUBLE", G_OPTION_ARG_DOUBLE, ce_glib_optionarg);
	REGISTER_ENUM_CONST("INT64", G_OPTION_ARG_INT64, ce_glib_optionarg);

	INIT_NS_CLASS_ENTRY(optionerror_ce, GLIB_NAMESPACE, "OptionError", NULL);
	ce_glib_optionerror = zend_register_internal_class_ex(&optionerror_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("UNKNOWN_OPTION", G_OPTION_ERROR_UNKNOWN_OPTION, ce_glib_optionerror);
	REGISTER_ENUM_CONST("BAD_VALUE", G_OPTION_ERROR_BAD_VALUE, ce_glib_optionerror);
	REGISTER_ENUM_CONST("FAILED", G_OPTION_ERROR_FAILED, ce_glib_optionerror);

	INIT_NS_CLASS_ENTRY(optionflags_ce, GLIB_NAMESPACE, "OptionFlags", NULL);
	ce_glib_optionflags = zend_register_internal_class_ex(&optionflags_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("HIDDEN", G_OPTION_FLAG_HIDDEN, ce_glib_optionflags);
	REGISTER_ENUM_CONST("IN_MAIN", G_OPTION_FLAG_IN_MAIN, ce_glib_optionflags);
	REGISTER_ENUM_CONST("REVERSE", G_OPTION_FLAG_REVERSE, ce_glib_optionflags);
	REGISTER_ENUM_CONST("NO_ARG", G_OPTION_FLAG_NO_ARG, ce_glib_optionflags);
	REGISTER_ENUM_CONST("FILENAME", G_OPTION_FLAG_FILENAME, ce_glib_optionflags);
	REGISTER_ENUM_CONST("OPTIONAL_ARG", G_OPTION_FLAG_OPTIONAL_ARG, ce_glib_optionflags);
	REGISTER_ENUM_CONST("NOALIAS", G_OPTION_FLAG_NOALIAS, ce_glib_optionflags);

	INIT_NS_CLASS_ENTRY(regexcompileflags_ce, GLIB_NAMESPACE, "RegexCompileFlags", NULL);
	ce_glib_regexcompileflags = zend_register_internal_class_ex(&regexcompileflags_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("CASELESS", G_REGEX_CASELESS, ce_glib_regexcompileflags);
	REGISTER_ENUM_CONST("MULTILINE", G_REGEX_MULTILINE, ce_glib_regexcompileflags);
	REGISTER_ENUM_CONST("DOTALL", G_REGEX_DOTALL, ce_glib_regexcompileflags);
	REGISTER_ENUM_CONST("EXTENDED", G_REGEX_EXTENDED, ce_glib_regexcompileflags);
	REGISTER_ENUM_CONST("ANCHORED", G_REGEX_ANCHORED, ce_glib_regexcompileflags);
	REGISTER_ENUM_CONST("DOLLAR_ENDONLY", G_REGEX_DOLLAR_ENDONLY, ce_glib_regexcompileflags);
	REGISTER_ENUM_CONST("UNGREEDY", G_REGEX_UNGREEDY, ce_glib_regexcompileflags);
	REGISTER_ENUM_CONST("RAW", G_REGEX_RAW, ce_glib_regexcompileflags);
	REGISTER_ENUM_CONST("NO_AUTO_CAPTURE", G_REGEX_NO_AUTO_CAPTURE, ce_glib_regexcompileflags);
	REGISTER_ENUM_CONST("OPTIMIZE", G_REGEX_OPTIMIZE, ce_glib_regexcompileflags);
	REGISTER_ENUM_CONST("DUPNAMES", G_REGEX_DUPNAMES, ce_glib_regexcompileflags);
	REGISTER_ENUM_CONST("NEWLINE_CR", G_REGEX_NEWLINE_CR, ce_glib_regexcompileflags);
	REGISTER_ENUM_CONST("NEWLINE_LF", G_REGEX_NEWLINE_LF, ce_glib_regexcompileflags);
	REGISTER_ENUM_CONST("NEWLINE_CRLF", G_REGEX_NEWLINE_CRLF, ce_glib_regexcompileflags);

	INIT_NS_CLASS_ENTRY(regexerror_ce, GLIB_NAMESPACE, "RegexError", NULL);
	ce_glib_regexerror = zend_register_internal_class_ex(&regexerror_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("COMPILE", G_REGEX_ERROR_COMPILE, ce_glib_regexerror);
	REGISTER_ENUM_CONST("OPTIMIZE", G_REGEX_ERROR_OPTIMIZE, ce_glib_regexerror);
	REGISTER_ENUM_CONST("REPLACE", G_REGEX_ERROR_REPLACE, ce_glib_regexerror);
	REGISTER_ENUM_CONST("MATCH", G_REGEX_ERROR_MATCH, ce_glib_regexerror);
	REGISTER_ENUM_CONST("INTERNAL", G_REGEX_ERROR_INTERNAL, ce_glib_regexerror);
	REGISTER_ENUM_CONST("STRAY_BACKSLASH", G_REGEX_ERROR_STRAY_BACKSLASH, ce_glib_regexerror);
	REGISTER_ENUM_CONST("MISSING_CONTROL_CHAR", G_REGEX_ERROR_MISSING_CONTROL_CHAR, ce_glib_regexerror);
	REGISTER_ENUM_CONST("UNRECOGNIZED_ESCAPE", G_REGEX_ERROR_UNRECOGNIZED_ESCAPE, ce_glib_regexerror);
	REGISTER_ENUM_CONST("QUANTIFIERS_OUT_OF_ORDER", G_REGEX_ERROR_QUANTIFIERS_OUT_OF_ORDER, ce_glib_regexerror);
	REGISTER_ENUM_CONST("QUANTIFIER_TOO_BIG", G_REGEX_ERROR_QUANTIFIER_TOO_BIG, ce_glib_regexerror);
	REGISTER_ENUM_CONST("UNTERMINATED_CHARACTER_CLASS", G_REGEX_ERROR_UNTERMINATED_CHARACTER_CLASS, ce_glib_regexerror);
	REGISTER_ENUM_CONST("INVALID_ESCAPE_IN_CHARACTER_CLASS", G_REGEX_ERROR_INVALID_ESCAPE_IN_CHARACTER_CLASS, ce_glib_regexerror);
	REGISTER_ENUM_CONST("RANGE_OUT_OF_ORDER", G_REGEX_ERROR_RANGE_OUT_OF_ORDER, ce_glib_regexerror);
	REGISTER_ENUM_CONST("NOTHING_TO_REPEAT", G_REGEX_ERROR_NOTHING_TO_REPEAT, ce_glib_regexerror);
	REGISTER_ENUM_CONST("UNRECOGNIZED_CHARACTER", G_REGEX_ERROR_UNRECOGNIZED_CHARACTER, ce_glib_regexerror);
	REGISTER_ENUM_CONST("POSIX_NAMED_CLASS_OUTSIDE_CLASS", G_REGEX_ERROR_POSIX_NAMED_CLASS_OUTSIDE_CLASS, ce_glib_regexerror);
	REGISTER_ENUM_CONST("UNMATCHED_PARENTHESIS", G_REGEX_ERROR_UNMATCHED_PARENTHESIS, ce_glib_regexerror);
	REGISTER_ENUM_CONST("INEXISTENT_SUBPATTERN_REFERENCE", G_REGEX_ERROR_INEXISTENT_SUBPATTERN_REFERENCE, ce_glib_regexerror);
	REGISTER_ENUM_CONST("UNTERMINATED_COMMENT", G_REGEX_ERROR_UNTERMINATED_COMMENT, ce_glib_regexerror);
	REGISTER_ENUM_CONST("EXPRESSION_TOO_LARGE", G_REGEX_ERROR_EXPRESSION_TOO_LARGE, ce_glib_regexerror);
	REGISTER_ENUM_CONST("MEMORY_ERROR", G_REGEX_ERROR_MEMORY_ERROR, ce_glib_regexerror);
	REGISTER_ENUM_CONST("VARIABLE_LENGTH_LOOKBEHIND", G_REGEX_ERROR_VARIABLE_LENGTH_LOOKBEHIND, ce_glib_regexerror);
	REGISTER_ENUM_CONST("MALFORMED_CONDITION", G_REGEX_ERROR_MALFORMED_CONDITION, ce_glib_regexerror);
	REGISTER_ENUM_CONST("TOO_MANY_CONDITIONAL_BRANCHES", G_REGEX_ERROR_TOO_MANY_CONDITIONAL_BRANCHES, ce_glib_regexerror);
	REGISTER_ENUM_CONST("ASSERTION_EXPECTED", G_REGEX_ERROR_ASSERTION_EXPECTED, ce_glib_regexerror);
	REGISTER_ENUM_CONST("UNKNOWN_POSIX_CLASS_NAME", G_REGEX_ERROR_UNKNOWN_POSIX_CLASS_NAME, ce_glib_regexerror);
	REGISTER_ENUM_CONST("POSIX_COLLATING_ELEMENTS_NOT_SUPPORTED", G_REGEX_ERROR_POSIX_COLLATING_ELEMENTS_NOT_SUPPORTED, ce_glib_regexerror);
	REGISTER_ENUM_CONST("HEX_CODE_TOO_LARGE", G_REGEX_ERROR_HEX_CODE_TOO_LARGE, ce_glib_regexerror);
	REGISTER_ENUM_CONST("INVALID_CONDITION", G_REGEX_ERROR_INVALID_CONDITION, ce_glib_regexerror);
	REGISTER_ENUM_CONST("SINGLE_BYTE_MATCH_IN_LOOKBEHIND", G_REGEX_ERROR_SINGLE_BYTE_MATCH_IN_LOOKBEHIND, ce_glib_regexerror);
	REGISTER_ENUM_CONST("INFINITE_LOOP", G_REGEX_ERROR_INFINITE_LOOP, ce_glib_regexerror);
	REGISTER_ENUM_CONST("MISSING_SUBPATTERN_NAME_TERMINATOR", G_REGEX_ERROR_MISSING_SUBPATTERN_NAME_TERMINATOR, ce_glib_regexerror);
	REGISTER_ENUM_CONST("DUPLICATE_SUBPATTERN_NAME", G_REGEX_ERROR_DUPLICATE_SUBPATTERN_NAME, ce_glib_regexerror);
	REGISTER_ENUM_CONST("MALFORMED_PROPERTY", G_REGEX_ERROR_MALFORMED_PROPERTY, ce_glib_regexerror);
	REGISTER_ENUM_CONST("UNKNOWN_PROPERTY", G_REGEX_ERROR_UNKNOWN_PROPERTY, ce_glib_regexerror);
	REGISTER_ENUM_CONST("SUBPATTERN_NAME_TOO_LONG", G_REGEX_ERROR_SUBPATTERN_NAME_TOO_LONG, ce_glib_regexerror);
	REGISTER_ENUM_CONST("TOO_MANY_SUBPATTERNS", G_REGEX_ERROR_TOO_MANY_SUBPATTERNS, ce_glib_regexerror);
	REGISTER_ENUM_CONST("INVALID_OCTAL_VALUE", G_REGEX_ERROR_INVALID_OCTAL_VALUE, ce_glib_regexerror);
	REGISTER_ENUM_CONST("TOO_MANY_BRANCHES_IN_DEFINE", G_REGEX_ERROR_TOO_MANY_BRANCHES_IN_DEFINE, ce_glib_regexerror);
	REGISTER_ENUM_CONST("DEFINE_REPETION", G_REGEX_ERROR_DEFINE_REPETION, ce_glib_regexerror);
	REGISTER_ENUM_CONST("INCONSISTENT_NEWLINE_OPTIONS", G_REGEX_ERROR_INCONSISTENT_NEWLINE_OPTIONS, ce_glib_regexerror);
	REGISTER_ENUM_CONST("MISSING_BACK_REFERENCE", G_REGEX_ERROR_MISSING_BACK_REFERENCE, ce_glib_regexerror);

	INIT_NS_CLASS_ENTRY(regexmatchflags_ce, GLIB_NAMESPACE, "RegexMatchFlags", NULL);
	ce_glib_regexmatchflags = zend_register_internal_class_ex(&regexmatchflags_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("ANCHORED", G_REGEX_MATCH_ANCHORED, ce_glib_regexmatchflags);
	REGISTER_ENUM_CONST("NOTBOL", G_REGEX_MATCH_NOTBOL, ce_glib_regexmatchflags);
	REGISTER_ENUM_CONST("NOTEOL", G_REGEX_MATCH_NOTEOL, ce_glib_regexmatchflags);
	REGISTER_ENUM_CONST("NOTEMPTY", G_REGEX_MATCH_NOTEMPTY, ce_glib_regexmatchflags);
	REGISTER_ENUM_CONST("PARTIAL", G_REGEX_MATCH_PARTIAL, ce_glib_regexmatchflags);
	REGISTER_ENUM_CONST("NEWLINE_CR", G_REGEX_MATCH_NEWLINE_CR, ce_glib_regexmatchflags);
	REGISTER_ENUM_CONST("NEWLINE_LF", G_REGEX_MATCH_NEWLINE_LF, ce_glib_regexmatchflags);
	REGISTER_ENUM_CONST("NEWLINE_CRLF", G_REGEX_MATCH_NEWLINE_CRLF, ce_glib_regexmatchflags);
	REGISTER_ENUM_CONST("NEWLINE_ANY", G_REGEX_MATCH_NEWLINE_ANY, ce_glib_regexmatchflags);

	INIT_NS_CLASS_ENTRY(seektype_ce, GLIB_NAMESPACE, "SeekType", NULL);
	ce_glib_seektype = zend_register_internal_class_ex(&seektype_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("CUR", G_SEEK_CUR, ce_glib_seektype);
	REGISTER_ENUM_CONST("SET", G_SEEK_SET, ce_glib_seektype);
	REGISTER_ENUM_CONST("END", G_SEEK_END, ce_glib_seektype);

	INIT_NS_CLASS_ENTRY(shellerror_ce, GLIB_NAMESPACE, "ShellError", NULL);
	ce_glib_shellerror = zend_register_internal_class_ex(&shellerror_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("BAD_QUOTING", G_SHELL_ERROR_BAD_QUOTING, ce_glib_shellerror);
	REGISTER_ENUM_CONST("EMPTY_STRING", G_SHELL_ERROR_EMPTY_STRING, ce_glib_shellerror);
	REGISTER_ENUM_CONST("FAILED", G_SHELL_ERROR_FAILED, ce_glib_shellerror);

	INIT_NS_CLASS_ENTRY(sliceconfig_ce, GLIB_NAMESPACE, "SliceConfig", NULL);
	ce_glib_sliceconfig = zend_register_internal_class_ex(&sliceconfig_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("ALWAYS_MALLOC", G_SLICE_CONFIG_ALWAYS_MALLOC, ce_glib_sliceconfig);
	REGISTER_ENUM_CONST("BYPASS_MAGAZINES", G_SLICE_CONFIG_BYPASS_MAGAZINES, ce_glib_sliceconfig);
	REGISTER_ENUM_CONST("WORKING_SET_MSECS", G_SLICE_CONFIG_WORKING_SET_MSECS, ce_glib_sliceconfig);
	REGISTER_ENUM_CONST("COLOR_INCREMENT", G_SLICE_CONFIG_COLOR_INCREMENT, ce_glib_sliceconfig);
	REGISTER_ENUM_CONST("CHUNK_SIZES", G_SLICE_CONFIG_CHUNK_SIZES, ce_glib_sliceconfig);
	REGISTER_ENUM_CONST("CONTENTION_COUNTER", G_SLICE_CONFIG_CONTENTION_COUNTER, ce_glib_sliceconfig);

	INIT_NS_CLASS_ENTRY(spawnerror_ce, GLIB_NAMESPACE, "SpawnError", NULL);
	ce_glib_spawnerror = zend_register_internal_class_ex(&spawnerror_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("FORK", G_SPAWN_ERROR_FORK, ce_glib_spawnerror);
	REGISTER_ENUM_CONST("READ", G_SPAWN_ERROR_READ, ce_glib_spawnerror);
	REGISTER_ENUM_CONST("CHDIR", G_SPAWN_ERROR_CHDIR, ce_glib_spawnerror);
	REGISTER_ENUM_CONST("ACCES", G_SPAWN_ERROR_ACCES, ce_glib_spawnerror);
	REGISTER_ENUM_CONST("PERM", G_SPAWN_ERROR_PERM, ce_glib_spawnerror);
	REGISTER_ENUM_CONST("TOO_BIG", G_SPAWN_ERROR_TOO_BIG, ce_glib_spawnerror);
	REGISTER_ENUM_CONST("2BIG", G_SPAWN_ERROR_2BIG, ce_glib_spawnerror);
	REGISTER_ENUM_CONST("NOEXEC", G_SPAWN_ERROR_NOEXEC, ce_glib_spawnerror);
	REGISTER_ENUM_CONST("NAMETOOLONG", G_SPAWN_ERROR_NAMETOOLONG, ce_glib_spawnerror);
	REGISTER_ENUM_CONST("NOENT", G_SPAWN_ERROR_NOENT, ce_glib_spawnerror);
	REGISTER_ENUM_CONST("NOMEM", G_SPAWN_ERROR_NOMEM, ce_glib_spawnerror);
	REGISTER_ENUM_CONST("NOTDIR", G_SPAWN_ERROR_NOTDIR, ce_glib_spawnerror);
	REGISTER_ENUM_CONST("LOOP", G_SPAWN_ERROR_LOOP, ce_glib_spawnerror);
	REGISTER_ENUM_CONST("TXTBUSY", G_SPAWN_ERROR_TXTBUSY, ce_glib_spawnerror);
	REGISTER_ENUM_CONST("IO", G_SPAWN_ERROR_IO, ce_glib_spawnerror);
	REGISTER_ENUM_CONST("NFILE", G_SPAWN_ERROR_NFILE, ce_glib_spawnerror);
	REGISTER_ENUM_CONST("MFILE", G_SPAWN_ERROR_MFILE, ce_glib_spawnerror);
	REGISTER_ENUM_CONST("INVAL", G_SPAWN_ERROR_INVAL, ce_glib_spawnerror);
	REGISTER_ENUM_CONST("ISDIR", G_SPAWN_ERROR_ISDIR, ce_glib_spawnerror);
	REGISTER_ENUM_CONST("LIBBAD", G_SPAWN_ERROR_LIBBAD, ce_glib_spawnerror);
	REGISTER_ENUM_CONST("FAILED", G_SPAWN_ERROR_FAILED, ce_glib_spawnerror);

	INIT_NS_CLASS_ENTRY(spawnflags_ce, GLIB_NAMESPACE, "SpawnFlags", NULL);
	ce_glib_spawnflags = zend_register_internal_class_ex(&spawnflags_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("LEAVE_DESCRIPTORS_OPEN", G_SPAWN_LEAVE_DESCRIPTORS_OPEN, ce_glib_spawnflags);
	REGISTER_ENUM_CONST("DO_NOT_REAP_CHILD", G_SPAWN_DO_NOT_REAP_CHILD, ce_glib_spawnflags);
	REGISTER_ENUM_CONST("SEARCH_PATH", G_SPAWN_SEARCH_PATH, ce_glib_spawnflags);
	REGISTER_ENUM_CONST("STDOUT_TO_DEV_NULL", G_SPAWN_STDOUT_TO_DEV_NULL, ce_glib_spawnflags);
	REGISTER_ENUM_CONST("STDERR_TO_DEV_NULL", G_SPAWN_STDERR_TO_DEV_NULL, ce_glib_spawnflags);
	REGISTER_ENUM_CONST("CHILD_INHERITS_STDIN", G_SPAWN_CHILD_INHERITS_STDIN, ce_glib_spawnflags);
	REGISTER_ENUM_CONST("FILE_AND_ARGV_ZERO", G_SPAWN_FILE_AND_ARGV_ZERO, ce_glib_spawnflags);

	INIT_NS_CLASS_ENTRY(testlogtype_ce, GLIB_NAMESPACE, "TestLogType", NULL);
	ce_glib_testlogtype = zend_register_internal_class_ex(&testlogtype_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("NONE", G_TEST_LOG_NONE, ce_glib_testlogtype);
	REGISTER_ENUM_CONST("ERROR", G_TEST_LOG_ERROR, ce_glib_testlogtype);
	REGISTER_ENUM_CONST("START_BINARY", G_TEST_LOG_START_BINARY, ce_glib_testlogtype);
	REGISTER_ENUM_CONST("LIST_CASE", G_TEST_LOG_LIST_CASE, ce_glib_testlogtype);
	REGISTER_ENUM_CONST("SKIP_CASE", G_TEST_LOG_SKIP_CASE, ce_glib_testlogtype);
	REGISTER_ENUM_CONST("START_CASE", G_TEST_LOG_START_CASE, ce_glib_testlogtype);
	REGISTER_ENUM_CONST("STOP_CASE", G_TEST_LOG_STOP_CASE, ce_glib_testlogtype);
	REGISTER_ENUM_CONST("MIN_RESULT", G_TEST_LOG_MIN_RESULT, ce_glib_testlogtype);
	REGISTER_ENUM_CONST("MAX_RESULT", G_TEST_LOG_MAX_RESULT, ce_glib_testlogtype);
	REGISTER_ENUM_CONST("MESSAGE", G_TEST_LOG_MESSAGE, ce_glib_testlogtype);

	INIT_NS_CLASS_ENTRY(testtrapflags_ce, GLIB_NAMESPACE, "TestTrapFlags", NULL);
	ce_glib_testtrapflags = zend_register_internal_class_ex(&testtrapflags_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("SILENCE_STDOUT", G_TEST_TRAP_SILENCE_STDOUT, ce_glib_testtrapflags);
	REGISTER_ENUM_CONST("SILENCE_STDERR", G_TEST_TRAP_SILENCE_STDERR, ce_glib_testtrapflags);
	REGISTER_ENUM_CONST("INHERIT_STDIN", G_TEST_TRAP_INHERIT_STDIN, ce_glib_testtrapflags);

	INIT_NS_CLASS_ENTRY(threaderror_ce, GLIB_NAMESPACE, "ThreadError", NULL);
	ce_glib_threaderror = zend_register_internal_class_ex(&threaderror_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("THREAD_ERROR_AGAIN", G_THREAD_ERROR_AGAIN, ce_glib_threaderror);

	INIT_NS_CLASS_ENTRY(timetype_ce, GLIB_NAMESPACE, "TimeType", NULL);
	ce_glib_timetype = zend_register_internal_class_ex(&timetype_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("STANDARD", G_TIME_TYPE_STANDARD, ce_glib_timetype);
	REGISTER_ENUM_CONST("DAYLIGHT", G_TIME_TYPE_DAYLIGHT, ce_glib_timetype);
	REGISTER_ENUM_CONST("UNIVERSAL", G_TIME_TYPE_UNIVERSAL, ce_glib_timetype);

	INIT_NS_CLASS_ENTRY(tokentype_ce, GLIB_NAMESPACE, "TokenType", NULL);
	ce_glib_tokentype = zend_register_internal_class_ex(&tokentype_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("EOF", G_TOKEN_EOF, ce_glib_tokentype);
	REGISTER_ENUM_CONST("LEFT_PAREN", G_TOKEN_LEFT_PAREN, ce_glib_tokentype);
	REGISTER_ENUM_CONST("RIGHT_PAREN", G_TOKEN_RIGHT_PAREN, ce_glib_tokentype);
	REGISTER_ENUM_CONST("LEFT_CURLY", G_TOKEN_LEFT_CURLY, ce_glib_tokentype);
	REGISTER_ENUM_CONST("RIGHT_CURLY", G_TOKEN_RIGHT_CURLY, ce_glib_tokentype);
	REGISTER_ENUM_CONST("LEFT_BRACE", G_TOKEN_LEFT_BRACE, ce_glib_tokentype);
	REGISTER_ENUM_CONST("RIGHT_BRACE", G_TOKEN_RIGHT_BRACE, ce_glib_tokentype);
	REGISTER_ENUM_CONST("EQUAL_SIGN", G_TOKEN_EQUAL_SIGN, ce_glib_tokentype);
	REGISTER_ENUM_CONST("COMMA", G_TOKEN_COMMA, ce_glib_tokentype);
	REGISTER_ENUM_CONST("NONE", G_TOKEN_NONE, ce_glib_tokentype);
	REGISTER_ENUM_CONST("ERROR", G_TOKEN_ERROR, ce_glib_tokentype);
	REGISTER_ENUM_CONST("CHAR", G_TOKEN_CHAR, ce_glib_tokentype);
	REGISTER_ENUM_CONST("BINARY", G_TOKEN_BINARY, ce_glib_tokentype);
	REGISTER_ENUM_CONST("OCTAL", G_TOKEN_OCTAL, ce_glib_tokentype);
	REGISTER_ENUM_CONST("INT", G_TOKEN_INT, ce_glib_tokentype);
	REGISTER_ENUM_CONST("HEX", G_TOKEN_HEX, ce_glib_tokentype);
	REGISTER_ENUM_CONST("FLOAT", G_TOKEN_FLOAT, ce_glib_tokentype);
	REGISTER_ENUM_CONST("STRING", G_TOKEN_STRING, ce_glib_tokentype);
	REGISTER_ENUM_CONST("SYMBOL", G_TOKEN_SYMBOL, ce_glib_tokentype);
	REGISTER_ENUM_CONST("IDENTIFIER", G_TOKEN_IDENTIFIER, ce_glib_tokentype);
	REGISTER_ENUM_CONST("IDENTIFIER_NULL", G_TOKEN_IDENTIFIER_NULL, ce_glib_tokentype);
	REGISTER_ENUM_CONST("COMMENT_SINGLE", G_TOKEN_COMMENT_SINGLE, ce_glib_tokentype);
	REGISTER_ENUM_CONST("COMMENT_MULTI", G_TOKEN_COMMENT_MULTI, ce_glib_tokentype);

	INIT_NS_CLASS_ENTRY(traverseflags_ce, GLIB_NAMESPACE, "TraverseFlags", NULL);
	ce_glib_traverseflags = zend_register_internal_class_ex(&traverseflags_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("LEAVES", G_TRAVERSE_LEAVES, ce_glib_traverseflags);
	REGISTER_ENUM_CONST("NON_LEAVES", G_TRAVERSE_NON_LEAVES, ce_glib_traverseflags);
	REGISTER_ENUM_CONST("ALL", G_TRAVERSE_ALL, ce_glib_traverseflags);
	REGISTER_ENUM_CONST("MASK", G_TRAVERSE_MASK, ce_glib_traverseflags);
	REGISTER_ENUM_CONST("LEAFS", G_TRAVERSE_LEAFS, ce_glib_traverseflags);
	REGISTER_ENUM_CONST("NON_LEAFS", G_TRAVERSE_NON_LEAFS, ce_glib_traverseflags);

	INIT_NS_CLASS_ENTRY(traversetype_ce, GLIB_NAMESPACE, "TraverseType", NULL);
	ce_glib_traversetype = zend_register_internal_class_ex(&traversetype_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("IN_ORDER", G_IN_ORDER, ce_glib_traversetype);
	REGISTER_ENUM_CONST("PRE_ORDER", G_PRE_ORDER, ce_glib_traversetype);
	REGISTER_ENUM_CONST("POST_ORDER", G_POST_ORDER, ce_glib_traversetype);
	REGISTER_ENUM_CONST("LEVEL_ORDER", G_LEVEL_ORDER, ce_glib_traversetype);

	INIT_NS_CLASS_ENTRY(unicodebreaktype_ce, GLIB_NAMESPACE, "UnicodeBreakType", NULL);
	ce_glib_unicodebreaktype = zend_register_internal_class_ex(&unicodebreaktype_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("MANDATORY", G_UNICODE_BREAK_MANDATORY, ce_glib_unicodebreaktype);
	REGISTER_ENUM_CONST("CARRIAGE_RETURN", G_UNICODE_BREAK_CARRIAGE_RETURN, ce_glib_unicodebreaktype);
	REGISTER_ENUM_CONST("LINE_FEED", G_UNICODE_BREAK_LINE_FEED, ce_glib_unicodebreaktype);
	REGISTER_ENUM_CONST("COMBINING_MARK", G_UNICODE_BREAK_COMBINING_MARK, ce_glib_unicodebreaktype);
	REGISTER_ENUM_CONST("SURROGATE", G_UNICODE_BREAK_SURROGATE, ce_glib_unicodebreaktype);
	REGISTER_ENUM_CONST("ZERO_WIDTH_SPACE", G_UNICODE_BREAK_ZERO_WIDTH_SPACE, ce_glib_unicodebreaktype);
	REGISTER_ENUM_CONST("INSEPARABLE", G_UNICODE_BREAK_INSEPARABLE, ce_glib_unicodebreaktype);
	REGISTER_ENUM_CONST("NON_BREAKING_GLUE", G_UNICODE_BREAK_NON_BREAKING_GLUE, ce_glib_unicodebreaktype);
	REGISTER_ENUM_CONST("CONTINGENT", G_UNICODE_BREAK_CONTINGENT, ce_glib_unicodebreaktype);
	REGISTER_ENUM_CONST("SPACE", G_UNICODE_BREAK_SPACE, ce_glib_unicodebreaktype);
	REGISTER_ENUM_CONST("AFTER", G_UNICODE_BREAK_AFTER, ce_glib_unicodebreaktype);
	REGISTER_ENUM_CONST("BEFORE", G_UNICODE_BREAK_BEFORE, ce_glib_unicodebreaktype);
	REGISTER_ENUM_CONST("BEFORE_AND_AFTER", G_UNICODE_BREAK_BEFORE_AND_AFTER, ce_glib_unicodebreaktype);
	REGISTER_ENUM_CONST("HYPHEN", G_UNICODE_BREAK_HYPHEN, ce_glib_unicodebreaktype);
	REGISTER_ENUM_CONST("NON_STARTER", G_UNICODE_BREAK_NON_STARTER, ce_glib_unicodebreaktype);
	REGISTER_ENUM_CONST("OPEN_PUNCTUATION", G_UNICODE_BREAK_OPEN_PUNCTUATION, ce_glib_unicodebreaktype);
	REGISTER_ENUM_CONST("CLOSE_PUNCTUATION", G_UNICODE_BREAK_CLOSE_PUNCTUATION, ce_glib_unicodebreaktype);
	REGISTER_ENUM_CONST("QUOTATION", G_UNICODE_BREAK_QUOTATION, ce_glib_unicodebreaktype);
	REGISTER_ENUM_CONST("EXCLAMATION", G_UNICODE_BREAK_EXCLAMATION, ce_glib_unicodebreaktype);
	REGISTER_ENUM_CONST("IDEOGRAPHIC", G_UNICODE_BREAK_IDEOGRAPHIC, ce_glib_unicodebreaktype);
	REGISTER_ENUM_CONST("NUMERIC", G_UNICODE_BREAK_NUMERIC, ce_glib_unicodebreaktype);
	REGISTER_ENUM_CONST("INFIX_SEPARATOR", G_UNICODE_BREAK_INFIX_SEPARATOR, ce_glib_unicodebreaktype);
	REGISTER_ENUM_CONST("SYMBOL", G_UNICODE_BREAK_SYMBOL, ce_glib_unicodebreaktype);
	REGISTER_ENUM_CONST("ALPHABETIC", G_UNICODE_BREAK_ALPHABETIC, ce_glib_unicodebreaktype);
	REGISTER_ENUM_CONST("PREFIX", G_UNICODE_BREAK_PREFIX, ce_glib_unicodebreaktype);
	REGISTER_ENUM_CONST("POSTFIX", G_UNICODE_BREAK_POSTFIX, ce_glib_unicodebreaktype);
	REGISTER_ENUM_CONST("COMPLEX_CONTEXT", G_UNICODE_BREAK_COMPLEX_CONTEXT, ce_glib_unicodebreaktype);
	REGISTER_ENUM_CONST("AMBIGUOUS", G_UNICODE_BREAK_AMBIGUOUS, ce_glib_unicodebreaktype);
	REGISTER_ENUM_CONST("UNKNOWN", G_UNICODE_BREAK_UNKNOWN, ce_glib_unicodebreaktype);
	REGISTER_ENUM_CONST("NEXT_LINE", G_UNICODE_BREAK_NEXT_LINE, ce_glib_unicodebreaktype);
	REGISTER_ENUM_CONST("WORD_JOINER", G_UNICODE_BREAK_WORD_JOINER, ce_glib_unicodebreaktype);
	REGISTER_ENUM_CONST("HANGUL_L_JAMO", G_UNICODE_BREAK_HANGUL_L_JAMO, ce_glib_unicodebreaktype);
	REGISTER_ENUM_CONST("HANGUL_V_JAMO", G_UNICODE_BREAK_HANGUL_V_JAMO, ce_glib_unicodebreaktype);
	REGISTER_ENUM_CONST("HANGUL_T_JAMO", G_UNICODE_BREAK_HANGUL_T_JAMO, ce_glib_unicodebreaktype);
	REGISTER_ENUM_CONST("HANGUL_LV_SYLLABLE", G_UNICODE_BREAK_HANGUL_LV_SYLLABLE, ce_glib_unicodebreaktype);
	REGISTER_ENUM_CONST("HANGUL_LVT_SYLLABLE", G_UNICODE_BREAK_HANGUL_LVT_SYLLABLE, ce_glib_unicodebreaktype);
	REGISTER_ENUM_CONST("CLOSE_PARANTHESIS", G_UNICODE_BREAK_CLOSE_PARANTHESIS, ce_glib_unicodebreaktype);
	REGISTER_ENUM_CONST("CONDITIONAL_JAPANESE_STARTER", G_UNICODE_BREAK_CONDITIONAL_JAPANESE_STARTER, ce_glib_unicodebreaktype);
	REGISTER_ENUM_CONST("HEBREW_LETTER", G_UNICODE_BREAK_HEBREW_LETTER, ce_glib_unicodebreaktype);

	INIT_NS_CLASS_ENTRY(unicodescript_ce, GLIB_NAMESPACE, "UnicodeScript", NULL);
	ce_glib_unicodescript = zend_register_internal_class_ex(&unicodescript_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("INVALID_CODE", G_UNICODE_SCRIPT_INVALID_CODE, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("COMMON", G_UNICODE_SCRIPT_COMMON, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("INHERITED", G_UNICODE_SCRIPT_INHERITED, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("ARABIC", G_UNICODE_SCRIPT_ARABIC, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("ARMENIAN", G_UNICODE_SCRIPT_ARMENIAN, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("BENGALI", G_UNICODE_SCRIPT_BENGALI, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("BOPOMOFO", G_UNICODE_SCRIPT_BOPOMOFO, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("CHEROKEE", G_UNICODE_SCRIPT_CHEROKEE, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("COPTIC", G_UNICODE_SCRIPT_COPTIC, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("CYRILLIC", G_UNICODE_SCRIPT_CYRILLIC, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("DESERET", G_UNICODE_SCRIPT_DESERET, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("DEVANAGARI", G_UNICODE_SCRIPT_DEVANAGARI, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("ETHIOPIC", G_UNICODE_SCRIPT_ETHIOPIC, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("GEORGIAN", G_UNICODE_SCRIPT_GEORGIAN, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("GOTHIC", G_UNICODE_SCRIPT_GOTHIC, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("GREEK", G_UNICODE_SCRIPT_GREEK, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("GUJARATI", G_UNICODE_SCRIPT_GUJARATI, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("GURMUKHI", G_UNICODE_SCRIPT_GURMUKHI, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("HAN", G_UNICODE_SCRIPT_HAN, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("HANGUL", G_UNICODE_SCRIPT_HANGUL, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("HEBREW", G_UNICODE_SCRIPT_HEBREW, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("HIRAGANA", G_UNICODE_SCRIPT_HIRAGANA, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("KANNADA", G_UNICODE_SCRIPT_KANNADA, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("KATAKANA", G_UNICODE_SCRIPT_KATAKANA, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("KHMER", G_UNICODE_SCRIPT_KHMER, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("LAO", G_UNICODE_SCRIPT_LAO, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("LATIN", G_UNICODE_SCRIPT_LATIN, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("MALAYALAM", G_UNICODE_SCRIPT_MALAYALAM, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("MONGOLIAN", G_UNICODE_SCRIPT_MONGOLIAN, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("MYANMAR", G_UNICODE_SCRIPT_MYANMAR, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("OGHAM", G_UNICODE_SCRIPT_OGHAM, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("OLD_ITALIC", G_UNICODE_SCRIPT_OLD_ITALIC, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("ORIYA", G_UNICODE_SCRIPT_ORIYA, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("RUNIC", G_UNICODE_SCRIPT_RUNIC, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("SINHALA", G_UNICODE_SCRIPT_SINHALA, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("SYRIAC", G_UNICODE_SCRIPT_SYRIAC, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("TAMIL", G_UNICODE_SCRIPT_TAMIL, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("TELUGU", G_UNICODE_SCRIPT_TELUGU, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("THAANA", G_UNICODE_SCRIPT_THAANA, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("THAI", G_UNICODE_SCRIPT_THAI, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("TIBETAN", G_UNICODE_SCRIPT_TIBETAN, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("CANADIAN_ABORIGINAL", G_UNICODE_SCRIPT_CANADIAN_ABORIGINAL, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("YI", G_UNICODE_SCRIPT_YI, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("TAGALOG", G_UNICODE_SCRIPT_TAGALOG, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("HANUNOO", G_UNICODE_SCRIPT_HANUNOO, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("BUHID", G_UNICODE_SCRIPT_BUHID, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("TAGBANWA", G_UNICODE_SCRIPT_TAGBANWA, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("BRAILLE", G_UNICODE_SCRIPT_BRAILLE, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("CYPRIOT", G_UNICODE_SCRIPT_CYPRIOT, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("LIMBU", G_UNICODE_SCRIPT_LIMBU, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("OSMANYA", G_UNICODE_SCRIPT_OSMANYA, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("SHAVIAN", G_UNICODE_SCRIPT_SHAVIAN, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("LINEAR_B", G_UNICODE_SCRIPT_LINEAR_B, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("TAI_LE", G_UNICODE_SCRIPT_TAI_LE, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("UGARITIC", G_UNICODE_SCRIPT_UGARITIC, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("NEW_TAI_LUE", G_UNICODE_SCRIPT_NEW_TAI_LUE, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("BUGINESE", G_UNICODE_SCRIPT_BUGINESE, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("GLAGOLITIC", G_UNICODE_SCRIPT_GLAGOLITIC, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("TIFINAGH", G_UNICODE_SCRIPT_TIFINAGH, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("SYLOTI_NAGRI", G_UNICODE_SCRIPT_SYLOTI_NAGRI, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("OLD_PERSIAN", G_UNICODE_SCRIPT_OLD_PERSIAN, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("KHAROSHTHI", G_UNICODE_SCRIPT_KHAROSHTHI, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("UNKNOWN", G_UNICODE_SCRIPT_UNKNOWN, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("BALINESE", G_UNICODE_SCRIPT_BALINESE, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("CUNEIFORM", G_UNICODE_SCRIPT_CUNEIFORM, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("PHOENICIAN", G_UNICODE_SCRIPT_PHOENICIAN, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("PHAGS_PA", G_UNICODE_SCRIPT_PHAGS_PA, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("NKO", G_UNICODE_SCRIPT_NKO, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("KAYAH_LI", G_UNICODE_SCRIPT_KAYAH_LI, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("LEPCHA", G_UNICODE_SCRIPT_LEPCHA, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("REJANG", G_UNICODE_SCRIPT_REJANG, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("SUNDANESE", G_UNICODE_SCRIPT_SUNDANESE, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("SAURASHTRA", G_UNICODE_SCRIPT_SAURASHTRA, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("CHAM", G_UNICODE_SCRIPT_CHAM, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("OL_CHIKI", G_UNICODE_SCRIPT_OL_CHIKI, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("VAI", G_UNICODE_SCRIPT_VAI, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("CARIAN", G_UNICODE_SCRIPT_CARIAN, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("LYCIAN", G_UNICODE_SCRIPT_LYCIAN, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("LYDIAN", G_UNICODE_SCRIPT_LYDIAN, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("AVESTAN", G_UNICODE_SCRIPT_AVESTAN, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("BAMUM", G_UNICODE_SCRIPT_BAMUM, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("EGYPTIAN_HIEROGLYPHS", G_UNICODE_SCRIPT_EGYPTIAN_HIEROGLYPHS, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("IMPERIAL_ARAMAIC", G_UNICODE_SCRIPT_IMPERIAL_ARAMAIC, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("INSCRIPTIONAL_PAHLAVI", G_UNICODE_SCRIPT_INSCRIPTIONAL_PAHLAVI, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("INSCRIPTIONAL_PARTHIAN", G_UNICODE_SCRIPT_INSCRIPTIONAL_PARTHIAN, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("JAVANESE", G_UNICODE_SCRIPT_JAVANESE, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("KAITHI", G_UNICODE_SCRIPT_KAITHI, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("LISU", G_UNICODE_SCRIPT_LISU, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("MEETEI_MAYEK", G_UNICODE_SCRIPT_MEETEI_MAYEK, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("OLD_SOUTH_ARABIAN", G_UNICODE_SCRIPT_OLD_SOUTH_ARABIAN, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("OLD_TURKIC", G_UNICODE_SCRIPT_OLD_TURKIC, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("SAMARITAN", G_UNICODE_SCRIPT_SAMARITAN, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("TAI_THAM", G_UNICODE_SCRIPT_TAI_THAM, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("TAI_VIET", G_UNICODE_SCRIPT_TAI_VIET, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("BATAK", G_UNICODE_SCRIPT_BATAK, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("BRAHMI", G_UNICODE_SCRIPT_BRAHMI, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("MANDAIC", G_UNICODE_SCRIPT_MANDAIC, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("CHAKMA", G_UNICODE_SCRIPT_CHAKMA, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("MEROITIC_CURSIVE", G_UNICODE_SCRIPT_MEROITIC_CURSIVE, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("MEROITIC_HIEROGLYPHS", G_UNICODE_SCRIPT_MEROITIC_HIEROGLYPHS, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("MIAO", G_UNICODE_SCRIPT_MIAO, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("SHARADA", G_UNICODE_SCRIPT_SHARADA, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("SORA_SOMPENG", G_UNICODE_SCRIPT_SORA_SOMPENG, ce_glib_unicodescript);
	REGISTER_ENUM_CONST("TAKRI", G_UNICODE_SCRIPT_TAKRI, ce_glib_unicodescript);

	INIT_NS_CLASS_ENTRY(unicodetype_ce, GLIB_NAMESPACE, "UnicodeType", NULL);
	ce_glib_unicodetype = zend_register_internal_class_ex(&unicodetype_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("CONTROL", G_UNICODE_CONTROL, ce_glib_unicodetype);
	REGISTER_ENUM_CONST("FORMAT", G_UNICODE_FORMAT, ce_glib_unicodetype);
	REGISTER_ENUM_CONST("UNASSIGNED", G_UNICODE_UNASSIGNED, ce_glib_unicodetype);
	REGISTER_ENUM_CONST("PRIVATE_USE", G_UNICODE_PRIVATE_USE, ce_glib_unicodetype);
	REGISTER_ENUM_CONST("SURROGATE", G_UNICODE_SURROGATE, ce_glib_unicodetype);
	REGISTER_ENUM_CONST("LOWERCASE_LETTER", G_UNICODE_LOWERCASE_LETTER, ce_glib_unicodetype);
	REGISTER_ENUM_CONST("MODIFIER_LETTER", G_UNICODE_MODIFIER_LETTER, ce_glib_unicodetype);
	REGISTER_ENUM_CONST("OTHER_LETTER", G_UNICODE_OTHER_LETTER, ce_glib_unicodetype);
	REGISTER_ENUM_CONST("TITLECASE_LETTER", G_UNICODE_TITLECASE_LETTER, ce_glib_unicodetype);
	REGISTER_ENUM_CONST("UPPERCASE_LETTER", G_UNICODE_UPPERCASE_LETTER, ce_glib_unicodetype);
	REGISTER_ENUM_CONST("SPACING_MARK", G_UNICODE_SPACING_MARK, ce_glib_unicodetype);
	REGISTER_ENUM_CONST("ENCLOSING_MARK", G_UNICODE_ENCLOSING_MARK, ce_glib_unicodetype);
	REGISTER_ENUM_CONST("NON_SPACING_MARK", G_UNICODE_NON_SPACING_MARK, ce_glib_unicodetype);
	REGISTER_ENUM_CONST("DECIMAL_NUMBER", G_UNICODE_DECIMAL_NUMBER, ce_glib_unicodetype);
	REGISTER_ENUM_CONST("LETTER_NUMBER", G_UNICODE_LETTER_NUMBER, ce_glib_unicodetype);
	REGISTER_ENUM_CONST("OTHER_NUMBER", G_UNICODE_OTHER_NUMBER, ce_glib_unicodetype);
	REGISTER_ENUM_CONST("CONNECT_PUNCTUATION", G_UNICODE_CONNECT_PUNCTUATION, ce_glib_unicodetype);
	REGISTER_ENUM_CONST("DASH_PUNCTUATION", G_UNICODE_DASH_PUNCTUATION, ce_glib_unicodetype);
	REGISTER_ENUM_CONST("CLOSE_PUNCTUATION", G_UNICODE_CLOSE_PUNCTUATION, ce_glib_unicodetype);
	REGISTER_ENUM_CONST("FINAL_PUNCTUATION", G_UNICODE_FINAL_PUNCTUATION, ce_glib_unicodetype);
	REGISTER_ENUM_CONST("INITIAL_PUNCTUATION", G_UNICODE_INITIAL_PUNCTUATION, ce_glib_unicodetype);
	REGISTER_ENUM_CONST("OTHER_PUNCTUATION", G_UNICODE_OTHER_PUNCTUATION, ce_glib_unicodetype);
	REGISTER_ENUM_CONST("OPEN_PUNCTUATION", G_UNICODE_OPEN_PUNCTUATION, ce_glib_unicodetype);
	REGISTER_ENUM_CONST("CURRENCY_SYMBOL", G_UNICODE_CURRENCY_SYMBOL, ce_glib_unicodetype);
	REGISTER_ENUM_CONST("MODIFIER_SYMBOL", G_UNICODE_MODIFIER_SYMBOL, ce_glib_unicodetype);
	REGISTER_ENUM_CONST("MATH_SYMBOL", G_UNICODE_MATH_SYMBOL, ce_glib_unicodetype);
	REGISTER_ENUM_CONST("OTHER_SYMBOL", G_UNICODE_OTHER_SYMBOL, ce_glib_unicodetype);
	REGISTER_ENUM_CONST("LINE_SEPARATOR", G_UNICODE_LINE_SEPARATOR, ce_glib_unicodetype);
	REGISTER_ENUM_CONST("PARAGRAPH_SEPARATOR", G_UNICODE_PARAGRAPH_SEPARATOR, ce_glib_unicodetype);
	REGISTER_ENUM_CONST("SPACE_SEPARATOR", G_UNICODE_SPACE_SEPARATOR, ce_glib_unicodetype);

	INIT_NS_CLASS_ENTRY(userdirectory_ce, GLIB_NAMESPACE, "UserDirectory", NULL);
	ce_glib_userdirectory = zend_register_internal_class_ex(&userdirectory_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("DIRECTORY_DESKTOP", G_USER_DIRECTORY_DESKTOP, ce_glib_userdirectory);
	REGISTER_ENUM_CONST("DIRECTORY_DOCUMENTS", G_USER_DIRECTORY_DOCUMENTS, ce_glib_userdirectory);
	REGISTER_ENUM_CONST("DIRECTORY_DOWNLOAD", G_USER_DIRECTORY_DOWNLOAD, ce_glib_userdirectory);
	REGISTER_ENUM_CONST("DIRECTORY_MUSIC", G_USER_DIRECTORY_MUSIC, ce_glib_userdirectory);
	REGISTER_ENUM_CONST("DIRECTORY_PICTURES", G_USER_DIRECTORY_PICTURES, ce_glib_userdirectory);
	REGISTER_ENUM_CONST("DIRECTORY_PUBLIC_SHARE", G_USER_DIRECTORY_PUBLIC_SHARE, ce_glib_userdirectory);
	REGISTER_ENUM_CONST("DIRECTORY_TEMPLATES", G_USER_DIRECTORY_TEMPLATES, ce_glib_userdirectory);
	REGISTER_ENUM_CONST("DIRECTORY_VIDEOS", G_USER_DIRECTORY_VIDEOS, ce_glib_userdirectory);
	REGISTER_ENUM_CONST("N_DIRECTORIES", G_USER_N_DIRECTORIES, ce_glib_userdirectory);

	INIT_NS_CLASS_ENTRY(variantclass_ce, GLIB_NAMESPACE, "VariantClass", NULL);
	ce_glib_variantclass = zend_register_internal_class_ex(&variantclass_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("BOOLEAN", G_VARIANT_CLASS_BOOLEAN, ce_glib_variantclass);
	REGISTER_ENUM_CONST("BYTE", G_VARIANT_CLASS_BYTE, ce_glib_variantclass);
	REGISTER_ENUM_CONST("INT16", G_VARIANT_CLASS_INT16, ce_glib_variantclass);
	REGISTER_ENUM_CONST("UINT16", G_VARIANT_CLASS_UINT16, ce_glib_variantclass);
	REGISTER_ENUM_CONST("INT32", G_VARIANT_CLASS_INT32, ce_glib_variantclass);
	REGISTER_ENUM_CONST("UINT32", G_VARIANT_CLASS_UINT32, ce_glib_variantclass);
	REGISTER_ENUM_CONST("INT64", G_VARIANT_CLASS_INT64, ce_glib_variantclass);
	REGISTER_ENUM_CONST("UINT64", G_VARIANT_CLASS_UINT64, ce_glib_variantclass);
	REGISTER_ENUM_CONST("HANDLE", G_VARIANT_CLASS_HANDLE, ce_glib_variantclass);
	REGISTER_ENUM_CONST("DOUBLE", G_VARIANT_CLASS_DOUBLE, ce_glib_variantclass);
	REGISTER_ENUM_CONST("STRING", G_VARIANT_CLASS_STRING, ce_glib_variantclass);
	REGISTER_ENUM_CONST("OBJECT_PATH", G_VARIANT_CLASS_OBJECT_PATH, ce_glib_variantclass);
	REGISTER_ENUM_CONST("SIGNATURE", G_VARIANT_CLASS_SIGNATURE, ce_glib_variantclass);
	REGISTER_ENUM_CONST("VARIANT", G_VARIANT_CLASS_VARIANT, ce_glib_variantclass);
	REGISTER_ENUM_CONST("MAYBE", G_VARIANT_CLASS_MAYBE, ce_glib_variantclass);
	REGISTER_ENUM_CONST("ARRAY", G_VARIANT_CLASS_ARRAY, ce_glib_variantclass);
	REGISTER_ENUM_CONST("TUPLE", G_VARIANT_CLASS_TUPLE, ce_glib_variantclass);
	REGISTER_ENUM_CONST("DICT_ENTRY", G_VARIANT_CLASS_DICT_ENTRY, ce_glib_variantclass);

	INIT_NS_CLASS_ENTRY(variantparseerror_ce, GLIB_NAMESPACE, "VariantParseError", NULL);
	ce_glib_variantparseerror = zend_register_internal_class_ex(&variantparseerror_ce, ce_glib_enum, NULL TSRMLS_CC);

	REGISTER_ENUM_CONST("FAILED", G_VARIANT_PARSE_ERROR_FAILED, ce_glib_variantparseerror);
	REGISTER_ENUM_CONST("BASIC_TYPE_EXPECTED", G_VARIANT_PARSE_ERROR_BASIC_TYPE_EXPECTED, ce_glib_variantparseerror);
	REGISTER_ENUM_CONST("CANNOT_INFER_TYPE", G_VARIANT_PARSE_ERROR_CANNOT_INFER_TYPE, ce_glib_variantparseerror);
	REGISTER_ENUM_CONST("DEFINITE_TYPE_EXPECTED", G_VARIANT_PARSE_ERROR_DEFINITE_TYPE_EXPECTED, ce_glib_variantparseerror);
	REGISTER_ENUM_CONST("INPUT_NOT_AT_END", G_VARIANT_PARSE_ERROR_INPUT_NOT_AT_END, ce_glib_variantparseerror);
	REGISTER_ENUM_CONST("INVALID_CHARACTER", G_VARIANT_PARSE_ERROR_INVALID_CHARACTER, ce_glib_variantparseerror);
	REGISTER_ENUM_CONST("INVALID_FORMAT_STRING", G_VARIANT_PARSE_ERROR_INVALID_FORMAT_STRING, ce_glib_variantparseerror);
	REGISTER_ENUM_CONST("INVALID_OBJECT_PATH", G_VARIANT_PARSE_ERROR_INVALID_OBJECT_PATH, ce_glib_variantparseerror);
	REGISTER_ENUM_CONST("INVALID_SIGNATURE", G_VARIANT_PARSE_ERROR_INVALID_SIGNATURE, ce_glib_variantparseerror);
	REGISTER_ENUM_CONST("INVALID_TYPE_STRING", G_VARIANT_PARSE_ERROR_INVALID_TYPE_STRING, ce_glib_variantparseerror);
	REGISTER_ENUM_CONST("NO_COMMON_TYPE", G_VARIANT_PARSE_ERROR_NO_COMMON_TYPE, ce_glib_variantparseerror);
	REGISTER_ENUM_CONST("NUMBER_OUT_OF_RANGE", G_VARIANT_PARSE_ERROR_NUMBER_OUT_OF_RANGE, ce_glib_variantparseerror);
	REGISTER_ENUM_CONST("NUMBER_TOO_BIG", G_VARIANT_PARSE_ERROR_NUMBER_TOO_BIG, ce_glib_variantparseerror);
	REGISTER_ENUM_CONST("TYPE_ERROR", G_VARIANT_PARSE_ERROR_TYPE_ERROR, ce_glib_variantparseerror);
	REGISTER_ENUM_CONST("UNEXPECTED_TOKEN", G_VARIANT_PARSE_ERROR_UNEXPECTED_TOKEN, ce_glib_variantparseerror);
	REGISTER_ENUM_CONST("UNKNOWN_KEYWORD", G_VARIANT_PARSE_ERROR_UNKNOWN_KEYWORD, ce_glib_variantparseerror);
	REGISTER_ENUM_CONST("UNTERMINATED_STRING_CONSTANT", G_VARIANT_PARSE_ERROR_UNTERMINATED_STRING_CONSTANT, ce_glib_variantparseerror);
	REGISTER_ENUM_CONST("VALUE_EXPECTED", G_VARIANT_PARSE_ERROR_VALUE_EXPECTED, ce_glib_variantparseerror);


	return SUCCESS;
}

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */