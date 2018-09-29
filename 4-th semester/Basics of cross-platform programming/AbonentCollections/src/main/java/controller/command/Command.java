package controller.command;

import model.Model;

import javax.servlet.http.HttpServletRequest;

public interface Command {
    Model model = Model.getInstance();
    String execute(HttpServletRequest request);
}
