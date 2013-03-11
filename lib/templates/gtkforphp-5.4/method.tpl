/* {{{ proto void <?= $namespace?>\<?= $class->name ?>-><?= $method->name?>(<?= $method->getProto()?>)
<?php if(!empty($method->doc)):?>
    <?= $method->doc?> 
<?php endif?>
*/
PHP_METHOD(<?= $namespace?>_<?= $class->name?>, <?= $method->name?>)
{
	<?= $module_lc ?>_<?= $class_lc ?>_object *object;
<?php
foreach($method->args as $arg):
	if($arg->direction == 'out'):?>
	<?= $arg->type ?> g_<?= $arg->name?>;
<?php else: ?>
	<?= $arg->zppType?> <?= $arg->name?>;
<?php endif; unset($arg); endforeach?>

<?php if(!empty($method->returnValue)):?>
	<?= $method->returnValue->nativeType?> g_return;
<?php endif?>

	PHP_<?= $module_uc?>_EXCEPTIONS
<?php if($method->hasParams()):?>
	if (FAILURE == zend_parse_parameters_ex(ZEND_PARSE_PARAMS_QUIET, ZEND_NUM_ARGS() TSRMLS_CC,"<?= $method->getZppSpec() ?>", <?= $method->getZppArgs()?>)) {
		return;
	}
<?php else:?>
	if (FAILURE == zend_parse_parameters_none()) {
		return;
	}
<?php endif?>
	PHP_<?= $module_uc?>_RESTORE_ERRORS

	object = (<?= $module_lc ?>_<?= $class_lc ?>_object *) zend_object_store_get_object(getThis() TSRMLS_CC);

<?php
if(!empty($method->returnValue)):?>
	g_return = <?php
else:?>	<?php
endif?><?= $method->identifier?>(object->data<?php
if($method->args){
	echo ', ' , $method->getArgs();
} ?>);
}
/* }}} */
