/* {{{ proto void <?= $namespace?>\<?= $class->name ?>-><?= $method->name?>()
<?php if(!empty($class->doc)):?>
    <?= $class->doc?> 
<?php endif?>
*/
PHP_METHOD(<?= $namespace?>_<?= $class->name?>, <?= $method->name?>)
{
	PHP_<?= $module_uc?>_EXCEPTIONS
<?php if(!empty($method->args)):?>
<?php else:?>
	if (FAILURE == zend_parse_parameters_none()) {
		return;
	}
<?php endif?>
	PHP_<?= $module_uc?>_RESTORE_ERRORS
}
/* }}} */

