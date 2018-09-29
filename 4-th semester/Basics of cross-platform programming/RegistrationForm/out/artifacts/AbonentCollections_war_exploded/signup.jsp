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
    <input type="text" name="name" title="Ex:Anatoliy" pattern="([A-Z][a-z]{1,20})|([А-Я][а-я]{1,20})" class="field">
    <br><br>
    <label>Введите вашу фамилию:</label>
    <input type="text" name="surname" title="Ex:Zaseka" pattern="([A-Z][a-z]{1,20})|([А-Я][а-я]{1,20})" class="field">
    <br><br>
    <label>Введите ваше отчество:</label>
    <input type="text" name="patronymic" title="Ex:Igorovich" pattern="([A-Z][a-z]{1,20})|([А-Я][а-я]{1,20})" class="field">
    <br><br>
    <label>Введите вашу группу:</label>
    <input type="text" name="group" title="Ex:Programmer"  pattern="([\w^[0-9]])+|([А-Яа-я_])+" class="field">
    <br><br>
    <label>Введите ваш домашний телефон:</label>
    <input type="text" name="homephone" pattern="[1-9]{3}[\-]?[\d]{2}[\-]?[\d]{2}"  class="field">
    <br><br>
    <label>Введите ваш мобильный телефон(1):</label>
    <input type="text" name="mobilephone1" pattern="([\+]?38)?(([\(]0[1-9]{2}[\)])|(0[1-9]{2}))[\d]{7}"  class="field">
    <br><br>
    <label>Введите ваш мобильный телефон(2):</label>
    <input type="text" name="mobilephone2" pattern="([\+]?38)?(([\(]0[1-9]{2}[\)])|(0[1-9]{2}))[\d]{7}"  class="field">
    <br><br>
    <label>Введите ваш email:</label>
    <input type="text" name="email" pattern="[\w]{1,20}[\@][A-Za-z]{1,20}[\.](com|ru|ua)"  class="field">
    <br><br>
    <label>Введите ваш skype:</label>
    <input type="text" name="skype"  pattern="[\w\-]+" class="field">
    <br><br>
    <label>Введите ваш индекс:</label>
    <input type="text" name="addressindex" pattern="[\d]{5}"  class="field">
    <br><br>
    <label>Введите ваш город:</label>
    <input type="text" name="addresscity" pattern="([A-Z][a-z]{1,20}([-][A-Z][a-z]{1,20})?)|([А-Я][а-я]{1,20}([-][А-Я][а-я]{1,20})?)"  class="field">
    <br><br>
    <label>Введите вашу улицу:</label>
    <input type="text" name="addressstreet" pattern="((st\.)?[\s]?[A-Z][a-z]+)|((ул\.)?[\s]?[А-Я][а-я]+)"  class="field">
    <br><br>
    <label>Введите номер вашего дома:</label>
    <input type="text" name="addresshousenumber" pattern="[\d]+"  class="field">
    <br><br>
    <label>Введите номер вашей квартиры:</label>
    <input type="text" name="addressapartmentnumber" pattern="[\d]+"  class="field">
    <br><br>
    <label>Введите дату создания записи:</label>
    <input type="text" name="creatingdate" pattern="((0[1-9])|([12][0-9])|(3[01]))(\.)((0[1-9])|(1[012]))(\.)((19|20)[\d][\d])"  class="field">
    <br><br>
    <label>Введите дату обновления записи:</label>
    <input type="text" name="modificationdate" pattern="((0[1-9])|([12][0-9])|(3[01]))(\.)((0[1-9])|(1[012]))(\.)((19|20)[\d][\d])"  class="field">
    <br><br>
    <label>Введите ваш никнейм:</label>
    <input type="text" name="nickname" pattern="[\w]+" class="field">
    <br><br>
    <label>Введите ваш комментарий:</label>
    <textarea rows="10" cols="45" name="comment" class="field"></textarea>
    <br><br>
    <p>
        <button type="submit" name="submit">Добавить контакт</button>
    </p>
</form>
    </div>
</div>
</body>
</html>
