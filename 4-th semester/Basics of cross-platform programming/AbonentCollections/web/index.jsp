<%@ page import="model.entities.Abonent" %>
<%@ page import="java.util.Map" %>
<%@ page import="java.util.HashMap" %>
<%@ page import="java.util.List" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>

<style>
    <%@include file='resources/styles.css' %>
</style>

<html>
  <head>
      <title>Abonents</title>
  </head>
  <body>
  <div id="main">
<%
    Map<Integer,Abonent> abonentsMap = (HashMap<Integer,Abonent>)request.getSession().getAttribute("abonentsMap");
    List<Map.Entry<Integer, Abonent>> abonentsList = (List<Map.Entry<Integer,Abonent>>) request.getSession().getAttribute("abonentsList");
    if(abonentsMap == null){
    %><jsp:forward page="${pageContext.request.contextPath}/app/signup"/><%
    }else {
        for (Map.Entry<Integer,Abonent> abonent : ((abonentsList == null) ? abonentsMap.entrySet() : abonentsList)) {  %>
            <div id="info">
                <div id="text"><%
                    out.println("Name:______" + abonent.getValue().getName() + "<br>");
                    out.println("Surname:___" + abonent.getValue().getSurname() + "<br>");
                    out.println("Patron:_____" + abonent.getValue().getPatronymic() + "<br>");
                    out.println("Address:____" + abonent.getValue().getAddress() + "<br>");
                    out.println("Telephone:__" + abonent.getKey());%>
                </div>
            </div><%
        }
        request.getSession().setAttribute("abonentsList", null);
}%>
<form>
    <a href="${pageContext.request.contextPath}/app/signup">Добавить абонента</a>
    <a href="${pageContext.request.contextPath}/app/sort">Сортировать</a>
</form>
  </div>
  </body>
</html>