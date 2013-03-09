<?php include 'header.tpl'?>

#ifndef PHP_<?= $module_uc?>_PRIVATE_H
#define PHP_<?= $module_uc?>_PRIVATE_H

#include <ext/standard/info.h>
#include <zend_exceptions.h>
#include <ext/spl/spl_exceptions.h>

<?php foreach($headers as $file):?>
#include <<?=$file?>>
<?php unset($file); endforeach?>

<?php foreach($structs as $name): ?>
typedef struct _<?= $name?> <?= $name?>;
<?php unset($name); endforeach?>

#define PHP_GLIB_EXCEPTIONS \
zend_error_handling error_handling; \
zend_replace_error_handling(EH_THROW, spl_ce_InvalidArgumentException, &error_handling TSRMLS_CC);

#define PHP_GLIB_RESTORE_ERRORS \
zend_restore_error_handling(&error_handling TSRMLS_CC);

#endif

<?php include 'footer.tpl'?>