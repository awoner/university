<?php
session_start();
unset($_COOKIE['username']);
setcookie('username', '', -1, '/');
$home_url = 'http://' . $_SERVER['HTTP_HOST'];
$_SESSION['count']--;
header('Location: ' . $home_url);