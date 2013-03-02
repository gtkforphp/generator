/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-<?= $year?> The PHP Group                                |
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