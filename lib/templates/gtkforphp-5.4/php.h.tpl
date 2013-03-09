<?php include 'header.tpl'?>

#ifndef PHP_<?= $module_uc?>_H
#define PHP_<?= $module_uc?>_H

extern zend_module_entry <?= $module_lc?>_module_entry;
#define phpext_<?= $module_lc?>_ptr &<?= $module_lc?>_module_entry;

#define PHP_<?= $module_uc?>_VERSION "<?= $version?>"
#define <?= $module_uc?>_NAMESPACE "<?= $namespace?>"

PHP_MINIT_FUNCTION(<?= $module_lc?>);
PHP_MINFO_FUNCTION(<?= $module_lc?>);

#endif

<?php include 'footer.tpl'?>