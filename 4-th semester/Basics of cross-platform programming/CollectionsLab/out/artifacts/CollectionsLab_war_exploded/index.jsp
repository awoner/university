<%--
  Created by IntelliJ IDEA.
  User: PC
  Date: 19.04.2018
  Time: 22:15
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<!DOCTYPE html>
<html lang="en">
<head>
    <title> Abonents </title>
    <meta http-equiv="content-type" content=" text/html; charset=utf-8"/>
    <meta name="description" content="description"/>
    <meta name="keywords" content="keywords, key, words"/>
    <meta name="viewport" content="width: device-width, initial-scale=1.0">
</head>

<body style="background: lightgray;">
<form method="post" action="/collectionslab">
    <label>Введите ваше имя:</label>
    <input type="text" name="name">
    <br><br>
    <label>Введите вашу фамилию:</label>
    <input type="text" name="surname">
    <br><br>
    <label>Введите ваше отчество:</label>
    <input type="text" name="patronymic">
    <br><br>
    <label>Введите ваш адрес:</label>
    <input type="text" name="adress">
    <br><br>
    <label>Введите ваш телефон:</label>
    <input type="text" name="telephone">
    <p> <button type="submit" name="submit">Зарегистрироваться</button> </p>
</form>
</body>
</html>
