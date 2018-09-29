<%--
  Created by IntelliJ IDEA.
  User: PC
  Date: 25.04.2018
  Time: 20:06
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<style>
    <%@include file='resources/styles.css' %>
</style>

<html>
<head>
    <title>SignUp</title>
</head>
<body>
<div id="content">
    <div id="reg-form">
<h1>Регистрация абонента</h1>
<form method="post" action="${pageContext.request.contextPath}/app/signup">
    <label>Введите ваше имя:</label>
    <input type="text" name="name" class="field">
    <br><br>
    <label>Введите вашу фамилию:</label>
    <input type="text" name="surname" class="field">
    <br><br>
    <label>Введите ваше отчество:</label>
    <input type="text" name="patronymic" class="field">
    <br><br>
    <label>Введите ваш адрес:</label>
    <input type="text" name="address" class="field">
    <br><br>
    <label>Введите ваш телефон:</label>
    <input type="number" name="telephone" class="field">
    <p>
        <button type="submit" name="submit">Добавить контакт</button>
    </p>
</form>
    </div>
</div>
</body>
</html>
