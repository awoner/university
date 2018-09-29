<%@ page import="java.util.ArrayList" %>
<%@ page import="model.entities.Note" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>

<style>
    <%@include file='resources/styles.css' %>
</style>

<html>
  <head>
      <title>Notes</title>
  </head>
  <body>
  <div id="main">
<%if(request.getSession().getAttribute("notes") == null){
    %><jsp:forward page="${pageContext.request.contextPath}/app/signup"/>
          <%
}else {
    ArrayList<Note> notes = new ArrayList<Note>((ArrayList<Note>)request.getSession().getAttribute("notes"));
  for( Note note : notes) {
    %><div id="info">
      <div id="text"><%
          out.println("Name:    " + note.getSubShortName() + "<br>");
          out.println("Nickname:    " + note.getNickname() + "<br>");
          out.println("Comment:    " + note.getComment() + "<br>");
          out.println("Group:    " + note.getGroup() + "<br>");
          out.println("Home phone:    " + note.getHomePhone() + "<br>");
          out.println("1-st mobilephone:    " + note.getFirstMobilePhone() + "<br>");
          out.println("2-nd mobilephone:    " + note.getSecondMobilePhone() + "<br>");
          out.println("Email:    " + note.getEmail() + "<br>");
          out.println("Skype:    " + note.getSkype() + "<br>");
          out.println("Address:    " + note.getFullAddress() + "<br>");
          out.println("Creating date:    " + note.getCreatingDate() + "<br>");
          out.println("Modification date:    " + note.getModificationDate() + "<br>");
      %></div>
        </div><%
  }
}%>
<form>
    <a href="${pageContext.request.contextPath}/app/signup">Добавить запись</a>
</form>
  </div>
  </body>
</html>