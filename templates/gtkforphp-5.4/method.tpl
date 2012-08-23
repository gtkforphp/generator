/* {{{ proto void  namespace goes here?\<?= $class?>-><?= $method?>() */
PHP_METHOD(<?= $class?>, <?= $method?>)
{
	PHP_<?= $module_uc?>_EXCEPTIONS
	if (FAILURE == zend_parse_parameters_none()) {
		return;
	}
	PHP_<?= $module_uc?>_RESTORE_ERRORS
}
/* }}} */

