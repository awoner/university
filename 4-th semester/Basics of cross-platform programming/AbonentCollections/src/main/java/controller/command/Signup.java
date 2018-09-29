package controller.command;

import model.Model;

import javax.servlet.RequestDispatcher;
import javax.servlet.http.HttpServletRequest;
import java.util.Scanner;

public class Signup implements Command{
    @Override
    public String execute(HttpServletRequest request) {
        //Integer tel = Integer.valueOf();
        if(request.getParameter("telephone") != null){
        model.addAbonents(Integer.parseInt(request.getParameter("telephone")),
                model.createAbonent(request.getParameter("name"),
                        request.getParameter("surname"),
                        request.getParameter("patronymic"),
                        request.getParameter("address")));
        request.getSession().setAttribute("abonentsMap", model.getAbonents());
            return "/index.jsp";
        }else{
            return "/signup.jsp";
        }
    }
}
