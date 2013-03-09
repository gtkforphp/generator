dnl config.m4 for <?= $module_lc; ?> extension

PHP_ARG_WITH(<?= $module_lc; ?>, for <?= $module_name; ?> support,
[ --with-<?= $module_lc; ?> Enable <?= $module_name; ?> support], yes)

if test "$PHP_<?= $module_uc?>" != "no"; then
	PHP_NEW_EXTENSION(<?= $module_lc; ?>, <?= wordwrap(implode(' ', $files), 60, " \ \n\t"); ?>, $ext_shared)

	PHP_SUBST(<?= $module_uc?>_SHARED_LIBADD)

dnl Try to use pkg-config if it's available
	AC_MSG_CHECKING(for pkg-config)

	if test ! -f "$PKG_CONFIG"; then
		PKG_CONFIG=`which pkg-config`
	fi

	if test -f "$PKG_CONFIG"; then
		AC_MSG_RESULT(found)
		AC_MSG_CHECKING(for <?= $pkgname?>)

	if $PKG_CONFIG --exists <?= $pkgname?>; then
		version_full=`$PKG_CONFIG --modversion <?= $pkgname?>`
		AC_MSG_RESULT([found $version_full])
		<?= $module_uc?>_LIBS="$LDFLAGS `$PKG_CONFIG --libs <?= $pkgname?>`"
		<?= $module_uc?>_INCS="$CFLAGS `$PKG_CONFIG --cflags-only-I <?= $pkgname?>`"
		PHP_EVAL_INCLINE($<?= $module_uc?>_INCS)
		PHP_EVAL_LIBLINE($<?= $module_uc?>_LIBS, <?= $module_uc?>_SHARED_LIBADD)
		AC_DEFINE(HAVE_<?= $module_uc?>, 1, [whether <?= $pkgname?> exists in the system])
	else
		AC_MSG_RESULT(not found)
		AC_MSG_ERROR(Ooops ! no <?= $pkgname?> found or detected in the system)
	fi
	else
		AC_MSG_RESULT(not found)
		AC_MSG_ERROR(Ooops ! no pkg-config found .... )
	fi
fi