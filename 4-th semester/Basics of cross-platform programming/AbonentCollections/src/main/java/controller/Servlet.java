package controller;

import controller.command.Command;
import controller.command.Signup;
import controller.command.Sort;

import javax.servlet.http.*;
import javax.servlet.*;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

public class Servlet extends HttpServlet {
    private Map<String, Command> commands = new HashMap<>();

    @Override
    public void init() throws ServletException {
        commands.put("signup", new Signup());
        commands.put("sort", new Sort());
    }

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
             throws ServletException, IOException {
       processRequest(request, response);
    }

    private void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        String path = request.getRequestURI();
        System.out.println(path);
        path = path.replaceAll(".*/app/" , "");
        System.out.println(path);
        Command command = commands.getOrDefault(path ,
                (r)->"/index.jsp");
        String page = command.execute(request);
        if(page.contains("redirect")){
            response.sendRedirect(page.replace("redirect:", "/app"));
        }else {
            request.getRequestDispatcher(page).forward(request, response);
        }
    }
}
