package MVC;

import java.io.IOException;
import java.util.HashMap;
import MVC.Model.*;

import javax.servlet.RequestDispatcher;

public class MyServlet extends javax.servlet.http.HttpServlet {
    protected void doPost(javax.servlet.http.HttpServletRequest request,
                          javax.servlet.http.HttpServletResponse response)
            throws javax.servlet.ServletException, IOException {

        final String id = request.getParameter("name");
        System.out.println(id);

        Model model = Model.getInstance();
        HashMap<String,Abonent> names = new HashMap<String, Abonent>();
        names.put(request.getParameter("telephone"), model.addAbonent());
        request.setAttribute("userNames", names);
        for (Abonent value : names.values()) {
            System.out.println(value.toString());
        }
        //RequestDispatcher requestDispatcher = request.getRequestDispatcher("views/list.jsp");
        //requestDispatcher.forward(request, response);
    }

    protected void doGet(javax.servlet.http.HttpServletRequest request,
                         javax.servlet.http.HttpServletResponse response)
            throws javax.servlet.ServletException, IOException {

    }
}