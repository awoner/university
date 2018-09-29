package controller.command;

import model.Model;

import javax.servlet.RequestDispatcher;
import javax.servlet.http.HttpServletRequest;

public class Signup implements Command{
    @Override
    public String execute(HttpServletRequest request) {
        //Integer tel = Integer.valueOf();
        String name = request.getParameter("name");
        if(name != null){
//            setName(request.getParameter("name"));
//            setSurname(request.getParameter("surname"));
//            setPatronymic(request.getParameter("patronymic"));
//            setNickname(request.getParameter("nickname"));
//            setComment(request.getParameter("comment"));
//            setGroup(request.getParameter("group"));
//            setHomePhone(request.getParameter("homephone"));
//            setFirstMobilePhone(request.getParameter("mobilephone1"));
//            setSecondMobilePhone(request.getParameter("mobilephone2"));
//            setEmail(request.getParameter("email"));
//            setSkype(request.getParameter("skype"));
//            setAddressIndex(request.getParameter("adressindex"));
//            setAddressCity(request.getParameter("addresscity"));
//            setAddressStreet(request.getParameter("addresstreet"));
//            setAddressHouseNumber(request.getParameter("addresshousenumber"));
//            setAddressApartmentNumber(request.getParameter("addressapartmentnumber"));
//            setCreatingDate(request.getParameter("creatingdate"));
//            setModificationDate(request.getParameter("modificationdate"));

            model.getTempNote().setSubName(name);
            model.getTempNote().setSubSurname(request.getParameter("surname"));
            model.getTempNote().setSubPatronymic(request.getParameter("patronymic"));
            model.getTempNote().setSubShortName();
            model.getTempNote().setNickname(request.getParameter("nickname"));
            model.getTempNote().setComment(request.getParameter("comment"));
            model.getTempNote().setGroup(request.getParameter("group"));
            model.getTempNote().setHomePhone(request.getParameter("homephone"));
            model.getTempNote().setFirstMobilePhone(request.getParameter("mobilephone1"));
            model.getTempNote().setSecondMobilePhone(request.getParameter("mobilephone2"));
            model.getTempNote().setEmail(request.getParameter("email"));
            model.getTempNote().setSkype(request.getParameter("skype"));
            model.getTempNote().setAddressIndex(request.getParameter("addressindex"));
            model.getTempNote().setAddressCity(request.getParameter("addresscity"));
            model.getTempNote().setAddressStreet(request.getParameter("addressstreet"));
            model.getTempNote().setAddressHouseNumber(request.getParameter("addresshousenumber"));
            model.getTempNote().setAddressApartmentNumber(request.getParameter("addressapartmentnumber"));
            model.getTempNote().setFullAddress();
            model.getTempNote().setCreatingDate(request.getParameter("creatingdate"));
            model.getTempNote().setModificationDate(request.getParameter("modificationdate"));

            model.setNote();
            System.out.println( model.getAllNotes().toString());
            request.getSession().setAttribute("notes", model.getAllNotes());
            return "/index.jsp";
        }else{
            return "/signup.jsp";
        }

    }

//    public String setName(String inputStr){
//        if (!inputStr.matches("([A-Z][a-z]{1,20})|([А-Я][а-я]{1,20})")){
//            return "/error.jsp";
//        }
//        model.getTempNote().setSubName(inputStr);
//        return null;
//    }
//
//    public String setSurname(String inputStr){
//        if (!inputStr.matches(
//                "([A-Z][a-z]{1,20}([-][A-Z][a-z]{1,20})?)|([А-Я][а-я]{1,20}([-][А-Я][а-я]{1,20})?)")){
//            return "/error.jsp";
//        }
//        model.getTempNote().setSubSurname(inputStr);
//        return null;
//    }
//
//    public String setPatronymic(String inputStr){
//        if (!inputStr.matches("([A-Z][a-z]{1,20})|([А-Я][а-я]{1,20})")){
//            return "/error.jsp";
//        }
//        model.getTempNote().setSubPatronymic(inputStr);
//        model.getTempNote().setSubShortName();
//        return null;
//    }
//
//    public String setNickname(String inputStr){
//        if (!inputStr.matches("[\\w]+")){
//            return "/error.jsp";
//        }
//        model.getTempNote().setNickname(inputStr);
//        return null;
//    }
//
//    public String setComment(String inputStr){
//        if (!inputStr.matches(".+")){
//            return "/error.jsp";
//        }
//        model.getTempNote().setComment(inputStr);
//        return null;
//    }
//
//    public String setGroup(String inputStr){
//        if (!inputStr.matches("([\\w^[0-9]])+|([А-Яа-я_])+")){
//            return "/error.jsp";
//        }
//        model.getTempNote().setGroup(inputStr);
//        return "/index.jsp";
//    }
//
//    public String setHomePhone(String inputStr){
//        if (!inputStr.matches("[1-9]{3}[\\-]?[\\d]{2}[\\-]?[\\d]{2}")){
//            return "/error.jsp";
//        }
//        model.getTempNote().setHomePhone(inputStr);
//        return null;
//    }
//
//    public String setFirstMobilePhone(String inputStr){
//        if (!inputStr.matches("([\\+]?38)?(([\\(]0[1-9]{2}[\\)])|(0[1-9]{2}))[\\d]{7}")){
//            return "/error.jsp";
//        }
//        model.getTempNote().setFirstMobilePhone(inputStr);
//        return null;
//    }
//
//    public String setSecondMobilePhone(String inputStr){
//        if (!inputStr.matches("([\\+]?38)?(([\\(]0[1-9]{2}[\\)])|(0[1-9]{2}))[\\d]{7}")){
//            return "/error.jsp";
//        }
//        model.getTempNote().setSecondMobilePhone(inputStr);
//        return null;
//    }
//
//    public String setEmail(String inputStr){
//        if (!inputStr.matches("[\\w]{1,20}[\\@][A-Za-z]{1,20}[\\.](com|ru|ua)")){
//            return "/error.jsp";
//        }
//        model.getTempNote().setEmail(inputStr);
//        return null;
//    }
//
//    public String setSkype(String inputStr){
//        if (!inputStr.matches("[\\w\\-]+")){
//            return "/error.jsp";
//        }
//        model.getTempNote().setSkype(inputStr);
//        return null;
//    }
//
//    public String setAddressIndex(String inputStr){
//        if (!inputStr.matches("[\\d]{5}")){
//            return "/error.jsp";
//        }
//        model.getTempNote().setAddressIndex(inputStr);
//        return null;
//    }
//
//    public String setAddressCity(String inputStr){
//        if (!inputStr.matches(
//                "([A-Z][a-z]{1,20}([-][A-Z][a-z]{1,20})?)|([А-Я][а-я]{1,20}([-][А-Я][а-я]{1,20})?)")){
//            return "/error.jsp";
//        }
//        model.getTempNote().setAddressCity(inputStr);
//        return null;
//    }
//
//    public String setAddressStreet(String inputStr){
//        if (!inputStr.matches("((st\\.)?[\\s]?[A-Z][a-z]+)|((ул\\.)?[\\s]?[А-Я][а-я]+)")){
//            return "/error.jsp";
//        }
//        model.getTempNote().setAddressStreet(inputStr);
//        return null;
//    }
//
//    public String setAddressHouseNumber(String inputStr){
//        if (!inputStr.matches("[\\d]+")){
//            return "/error.jsp";
//        }
//        model.getTempNote().setAddressHouseNumber(inputStr);
//        return null;
//    }
//
//    public String setAddressApartmentNumber(String inputStr){
//        if (!inputStr.matches("[\\d]+")){
//            return "/error.jsp";
//        }
//        model.getTempNote().setAddressApartmentNumber(inputStr);
//        model.getTempNote().setFullAddress();
//        return null;
//    }
//
//    public String setCreatingDate(String inputStr){
//        if (!inputStr.matches(
//                "((0[1-9])|([12][0-9])|(3[01]))(\\.)((0[1-9])|(1[012]))(\\.)((19|20)[\\d][\\d])")){
//            return "/error.jsp";
//        }
//        model.getTempNote().setCreatingDate(inputStr);
//        return null;
//    }
//
//    public String setModificationDate(String inputStr){
//        if (!inputStr.matches(
//                "((0[1-9])|([12][0-9])|(3[01]))(\\.)((0[1-9])|(1[012]))(\\.)((19|20)[\\d][\\d])")){
//            return "/error.jsp";
//        }
//        model.getTempNote().setModificationDate(inputStr);
//        return null;
//    }
}
