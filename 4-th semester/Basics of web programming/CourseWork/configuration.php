<?php
require_once "core/sql.php";
require_once "app/views/view.php";
$APP_NAME = __DIR__;

$db = new SqlBuilder();
$tpl = new Tpl();
$errorBuilder = Error1::setInstance();

$db->connect('guitar_shop');

