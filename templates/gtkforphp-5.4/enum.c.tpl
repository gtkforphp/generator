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

<?php foreach($enums as $name => $value):?>
zend_class_entry *ce_<?= $module?>_<?= strtolower($name)?>;
<?php endforeach?>

/* ----------------------------------------------------------------
    All <?= $module_uc?> enums Definition and registration
------------------------------------------------------------------*/

PHP_MINIT_FUNCTION(<?= $module?>_Enums)
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
	ce_<?= $module?>_<?= $lname?> = zend_register_internal_class_ex(&<?= $lname?>_ce, ce_glib_enum, NULL TSRMLS_CC);

<?php foreach($values as $enum_name => $value):?>
	REGISTER_ENUM_CONST("<?= strtoupper($enum_name) ?>", <?= $value?>, ce_<?= $module?>_<?= $lname?>);
<?php endforeach?>

<?php endforeach?>

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