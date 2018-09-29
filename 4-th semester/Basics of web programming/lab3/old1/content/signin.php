<?php
session_start();

require_once 'sql.php';
$dbh = new SQLBuilder('php_db');
if(!isset($_COOKIE['user_id']) && isset($_POST['submit'])){
        $dbh = $dbh->table('registred_users', 'name')->where('login', '=', $_POST['login'])
            ->and('user_password', '=', $_POST['password'])->get();
        if(!empty($dbh)){
            $_SESSION['count']++;
            setcookie('username', $_POST['login'], 1000);
            $home_url = 'http://localhost/' . $_SERVER['HTTP_HOST'];
            header('Location: /old/index.php');
        }
        else{
            echo 'Неправильный логин или пароль! Введите снова.';
        }
    }
?>
<!DOCTYPE html>
<html>
<head>
    <title> Вход | PhpLab3.com </title>
    <meta http-equiv="content-type" content=" text/html; charset=utf-8"/>
    <meta name="description" content="description"/>
    <meta name="keywords" content="keywords, key, words"/>
    <meta name="viewport" content="width: device-width, initial-scale=1.0">
    <link rel="stylesheet" type="text/css" href="style.css">
</head>
<body>
    <form method="post" action="<?php echo $_SERVER['PHP_SELF']; ?>">
        <label for="login">Логин:</label>
        <input type="text" name="login">
        <br><br>
        <label for="password">Пароль:</label>
        <input type="password" name="password">
        <br><br>
        <p>
            <button type="submit" name="submit">Войти</button>
        </p>
        <a href="signup.php">Зарегистрируйтесь</a>
        </form>
</body>
</html>