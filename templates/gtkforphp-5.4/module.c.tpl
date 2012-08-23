<?php include 'header.tpl'?>

#include "php_<?= $module_lc?>.h"

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(<?= $module_lc?>)
{
<?php foreach($classes as $name):?>
	PHP_MINIT(<?= $module_lc ?>_<?= $name?>)(INIT_FUNC_ARGS_PASSTHRU);
<?php endforeach?>

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(<?= $module_lc?>)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "<?= $module?> extension", "enabled");
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

<?php include 'footer.tpl'?>