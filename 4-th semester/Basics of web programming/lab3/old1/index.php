<!DOCTYPE html>
<html>
<head>
    <title> PhpLab3.com </title>
    <meta http-equiv="content-type" content=" text/html; charset=utf-8"/>
    <meta name="description" content="description"/>
    <meta name="keywords" content="keywords, key, words"/>
    <meta name="viewport" content="width: device-width, initial-scale=1.0">
    <link rel="stylesheet" type="text/css" href="/old/content/style.css">
</head>
<body>
<?php
session_start();
if(!isset($_SESSION['count'])) {
    $_SESSION['count'] = 0;
}
if(empty($_COOKIE['username'])) {
    echo 'Count of sessions: ' . $_SESSION['count'];
    ?>
    <ul>
        <li><a href="/old/content/signup.php">Регистрация</a></li>
        <li><a href="/old/content/signin.php">Вход</a></li>
    </ul>
    <?php
}
else {
    echo 'Count of sessions: ' . $_SESSION['count'];
    ?>
    <a href="exit.php">Выйти</a> <?php echo '(' . $_COOKIE['username'] . ')'; ?>
    <?php
}
?>
</body>
</html>