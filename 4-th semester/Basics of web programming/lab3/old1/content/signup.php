<?php
require_once 'sql.php';

$dbh = new SQLBuilder('php_db');
if(isset($_POST['submit'])) {
        $dbh = $dbh->table('registred_users')->where('login','=',$_POST['login'])
            ->and('user_password', '=', $_POST['password1']);
        if($dbh->get() == null){
            $placeholders = [
                    ':name' => $_POST['name'],
                    ':surname' => $_POST['surname'],
                    ':login' => $_POST['login'],
                    ':password' => $_POST['password1'],
            ];
            $dbh = $dbh->insert()
                ->into('registred_users','name', 'surname', 'login', 'user_password')
                ->values(':name', ':surname', ':login',':password')->execute($placeholders);
            echo 'Вы зарегестрированы!';
            $home_url = 'http://localhost/' . $_SERVER['HTTP_HOST'];
            header('Location: /old/index.php');
        }
        else{
            echo 'Логин уже существует.';
        }
}
?>
<!DOCTYPE html>
<html>
<head>
    <title> Регистрация | PhpLab3.com </title>
    <meta http-equiv="content-type" content=" text/html; charset=utf-8"/>
    <meta name="description" content="description"/>
    <meta name="keywords" content="keywords, key, words"/>
    <meta name="viewport" content="width: device-width, initial-scale=1.0">
    <link rel="stylesheet" type="text/css" href="style.css">
</head>
<body>
<form method="post" action="<?php echo $_SERVER['PHP_SELF']; ?>">
    <label for="name">Введите ваше имя:</label>
    <input type="text" name="name">
    <br><br>
    <label for="surname">Введите вашу фамилию:</label>
    <input type="text" name="surname">
    <br><br>
    <label for="login">Введите ваш логин:</label>
    <input type="text" name="login">
    <br><br>
    <label for="password">Введите ваш пароль:</label>
    <input type="password" name="password1">
    <br><br>
    <label for="password2">Введите ваш пароль еще раз:</label>
    <input type="password" name="password2">
    <p> <button type="submit" name="submit">Зарегистрироваться</button> </p>
</form>
</body>
</html>