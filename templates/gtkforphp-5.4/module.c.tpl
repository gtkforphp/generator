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
<?php
	foreach($authors as $name => $email) {
		$string = $name . ' <' . $email . '>';
		$line = $string . str_repeat(' ', 61 - strlen($string)); ?>
  | Author: <?= $line?>|
<?php } ?>
  +----------------------------------------------------------------------+
*/

#include "php_<?= $module?>.h"

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(<?= $module?>)
{
<?php foreach($classes as $name):?>
	PHP_MINIT(<?= $module?>_<?= $name?>)(INIT_FUNC_ARGS_PASSTHRU);
<?php endforeach?>

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(<?= $module?>)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "<?= $module_pretty?> extension", "enabled");
	php_info_print_table_row(2, "Extension Version", PHP_<?= $module_uc?>_VERSION);
	php_info_print_table_row(2, "Generated with G\Generator on <?php echo date('Y-m-d')?>", "<?php echo $generator_version?>");
	php_info_print_table_end();
}
/* }}} */

/* {{{ <?= $module?>_module_entry */
zend_module_entry <?= $module?>_module_entry = {
	STANDARD_MODULE_HEADER,
	"<?= $module?>",
	NULL,
	PHP_MINIT(<?= $module?>),
	NULL,
	NULL,
	NULL,
	PHP_MINFO(<?= $module?>),
	PHP_<?= $module_uc?>_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_<?= $module_uc?> 
ZEND_GET_MODULE(<?= $module?>)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */