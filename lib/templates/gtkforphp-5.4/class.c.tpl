<?php include 'header.tpl'?>

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

#include "php_<?= $module_lc?>.h"
#include "php_<?= $module_lc?>_private.h"

zend_class_entry *ce_<?= $module_lc?>_<?= $class_lc?>;
zend_object_handlers <?= $module_lc?>_<?= $class_lc?>_handlers;

/* struct for <?= $class->type ?> */
struct _<?= $module_lc?>_<?= $class_lc?>_object {
	zend_object std;
	zend_bool is_constructed;
	<?= $class->type ?>* data;
};

/* ----------------------------------------------------------------
    <?= $class->name ?> class API
<?php if(!empty($class->doc)):?>
    <?= $class->doc?> 
<?php endif?>
------------------------------------------------------------------*/

<?php foreach($class->methods as $method) {
	include('arg_info.tpl');
	echo PHP_EOL;
	unset($method);
} ?>

<?php foreach($class->methods as $method) {
	include('method.tpl');
	echo PHP_EOL;
	unset($method);
} ?>

/* ----------------------------------------------------------------
    <?= $class?> Object management
------------------------------------------------------------------*/
<?php include('create_object.tpl') ?> 

/* ----------------------------------------------------------------
    <?= $class?> Definition and registration
------------------------------------------------------------------*/

/* {{{ class methods */
static const zend_function_entry <?= $module_lc?>_<?= $class_lc?>_methods[] = {
<?php foreach($class->methods as $method):?>
	PHP_ME(<?= $namespace?>_<?= $class->name?>, <?= $method->name?>, arg_<?= $class_lc?>_<?= strtolower($method->name)?>, ZEND_ACC_PUBLIC<?= $method->isConstructor ? ' | ZEND_ACC_CTOR' : '' ?>)
<?php unset($method); endforeach?>
	ZEND_FE_END
};
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(<?= $module_lc?>_<?= $class_lc?>)
{
	zend_class_entry ce;
	INIT_NS_CLASS_ENTRY(ce, <?= $module_uc?>_NAMESPACE, "<?= $class->name?>", <?= $module_lc?>_<?= $class_lc?>_methods);
	ce_<?= $module_lc?>_<?= $class_lc?> = zend_register_internal_class(&ce TSRMLS_CC);

	ce_<?= $module_lc?>_<?= $class_lc?>->create_object = <?= $module_lc?>_<?= $class_lc?>_object_create;

	memcpy(&<?= $module_lc?>_<?= $class_lc?>_handlers, &std_object_handlers, sizeof(zend_object_handlers));
	<?= $module_lc?>_<?= $class_lc?>_handlers.clone_obj = NULL;

	return SUCCESS;
}
/* }}} */

<?php include 'footer.tpl'?>