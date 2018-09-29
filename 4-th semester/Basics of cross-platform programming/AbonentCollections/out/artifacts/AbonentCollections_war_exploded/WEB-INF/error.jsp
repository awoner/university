<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">

<%@ page language="java" isErrorPage="true"  contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="java.util.*, java.text.*" %>
<style>
    body{
        font-family: "Roboto", sans-serif;
        background: azure;
    }

    h1, h2{
        color: #fe6637;
    }

    a{
        text-decoration: none;
        outline: none;
        background: white;
        display: inline-block;
        padding: 5px 15px;
        margin: 10px 20px;
        position: relative;
        overflow: hidden;
        border: 2px solid #fe6637;
        border-radius: 8px;
        font-family: 'Montserrat', sans-serif;
        color: #fe6637;
        transition: .2s ease-in-out;
    }

    a:hover {
        background: #fe6637;
        color: #fff;
    }

    #err{
        text-align: center;
        width: 80%;
        margin: 0 auto;
    }
</style>


<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <title>Error Page</title>
</head>
<body>
<div id="err">
<h1>
    Error;(<br/>
</h1>
<h2>
    <u>Error <%= exception %></u>
</h2>
<br/>
<a href="${pageContext.request.contextPath}/app/index.jsp">На главную</a>
</div>
</body>
</html>