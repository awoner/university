package controller.command;

import javax.servlet.http.HttpServletRequest;

public class Sort implements Command {
    @Override
    public String execute(HttpServletRequest request) {

        request.getSession().setAttribute("abonentsList", model.sort());
        return "/index.jsp";
    }
}
