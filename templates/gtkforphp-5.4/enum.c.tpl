<?php include 'header.tpl'?>

#include "php_<?= $module_lc ?>.h"

<?php foreach($enums as $name => $value):?>
zend_class_entry *ce_<?= $module_lc?>_<?= strtolower($name)?>;
<?php endforeach?>

/* ----------------------------------------------------------------
    All <?= $module_uc?> enums Definition and registration
------------------------------------------------------------------*/

PHP_MINIT_FUNCTION(<?= $module_lc?>_Enums)
{
<?php $lower_enums = array_keys($enums);
      $lower_enums = array_map('strtolower', $lower_enums);
      $lower_enums = array_chunk($lower_enums, 5);
    foreach($lower_enums as $chunk) {
        $line = array();
        foreach($chunk as $name) {
            $line[] = $name . '_ce';
        } ?>
	zend_class_entry <?= implode(', ', $line)?>;
<?php } ?>

<?php foreach($enums as $name => $values): $lname = strtolower($name)?>
	INIT_NS_CLASS_ENTRY(<?= $lname?>_ce, <?= $module_uc?>_NAMESPACE, "<?= $name?>", NULL);
	ce_<?= $module_lc?>_<?= $lname?> = zend_register_internal_class_ex(&<?= $lname?>_ce, ce_glib_enum, NULL TSRMLS_CC);

<?php foreach($values as $enum_name => $value):?>
	REGISTER_ENUM_CONST("<?= strtoupper($enum_name) ?>", <?= $value?>, ce_<?= $module_lc?>_<?= $lname?>);
<?php endforeach?>

<?php endforeach?>

	return SUCCESS;
}

<?php include 'footer.tpl'?>