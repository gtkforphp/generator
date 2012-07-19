dnl config.m4 for <?= $extension; ?> extension

PHP_ARG_WITH(<?= $extension; ?> , <?= $description; ?> ,
[ --with-<?= $extension; ?> Enable <?= $extension; ?> support], yes)

if test "$PHP_<?= $extension_uc?>" != "no"; then
    PHP_NEW_EXTENSION(<?= $extension; ?>, <?= $files; ?>, $ext_shared)
fi