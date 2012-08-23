<?php include 'header.tpl'?>

#include "php_<?= $module_lc?>.h"

zend_class_entry *ce_<?= $module_lc?>_<?= $class_lc?>;

/* ----------------------------------------------------------------
    <?= $class?> class API
------------------------------------------------------------------*/

/* ----------------------------------------------------------------
    <?= $class?> Definition and registration
------------------------------------------------------------------*/

/* {{{ class methods */
static const zend_function_entry <?= $module_lc?>_<?= $class_lc?>_methods[] = {
	ZEND_FE_END
};
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(<?= $module_lc?>_<?= $class?>)
{
	zend_class_entry ce;
	INIT_NS_CLASS_ENTRY(ce, <?= $module_uc?>_NAMESPACE, "<?= $class?>"), <?= $module_lc?>_<?= $class_lc?>_methods);
	ce_<?= $module_lc?>_<?= $class_lc?> = zend_register_internal_class(&ce TSRMLS_CC);

	return SUCCESS;
}
/* }}} */

<?php include 'footer.tpl'?>