/* {{{ <?= $module_lc?>_<?= $class_lc?>_object_free */
static void <?= $module_lc?>_<?= $class_lc?>_object_free(void *object TSRMLS_DC)
{
	<?= $module_lc?>_<?= $class_lc?>_object *<?= $class_lc?>_object = (<?= $module_lc?>_<?= $class_lc?>_object *)object;

	zend_object_std_dtor(&<?= $class_lc?>_object->std TSRMLS_CC);
	<?= $class_lc?>_object->is_constructed = FALSE;
<?php if(!empty($class->freeHandler)):?>
	<?= $class->freeHandler?>(<?= $class_lc?>_object->data);
<?php else:?>
	<?= $class_lc?>_object->data = NULL;
<?php endif?>

	efree(<?= $class_lc?>_object);
}
/* }}} */

/* {{{ <?= $module_lc?>_<?= $class_lc?>_object_create */
static zend_object_value <?= $module_lc?>_<?= $class_lc?>_object_create(zend_class_entry *ce TSRMLS_DC)
{
	zend_object_value retval;
	<?= $module_lc?>_<?= $class_lc?>_object *object;

	object = ecalloc(1, sizeof(<?= $module_lc?>_<?= $class_lc?>_object));
	zend_object_std_init((zend_object *) object, ce TSRMLS_CC);
	object->is_constructed = FALSE;
<?php if(!empty($class->createHandler)):?>
	object->data = <?= $class->createHandler?>();
<?php else:?>
	object->data = NULL;
<?php endif?>

	object_properties_init(&object->std, ce);

	retval.handle = zend_objects_store_put(object, (zend_objects_store_dtor_t) zend_objects_destroy_object,
	(zend_objects_free_object_storage_t) <?= $module_lc?>_<?= $class_lc?>_object_free,
	NULL TSRMLS_CC);

	retval.handlers = &<?= $module_lc?>_<?= $class_lc?>_handlers;
	return retval;
}
/* }}} */