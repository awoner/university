package mvc;

public class Regex {
    public static String name = "^[A-Z][a-z]{1,20}";
    public static String surName = "^[A-Z][a-z]{1,20}([-][A-Z][a-z]{1,20})?";
    public static String patronimic = "^[A-Z][a-z]{1,20}";
    public static String userName = "^[\\w]+";
    public static String comment = "^.+";
    public static String groups = "^[\\w^[0-9]])+";
    public static String setHomeNumber = "^[1-9]{3}[\\-]?[\\d]{2}[\\-]?[\\d]{2}";
    public static String phoneNumber = "^(([\\+]?38)?(([\\(]0[1-9]{2}[\\)])|(0[1-9]{2}))[\\d]{7})";
    public static String skype = "^[\\w\\-]+";
    public static String index = "^[\\d]{5}";
    public static String city = "^[A-Z][a-z]{1,20}([-][A-Z][a-z]{1,20})?";
    public static String street = "^(st\\.)?[\\s]?[A-Z][a-z]+";
    public static String roomNumber = "^[\\d]+";
    public static String date = "^((0[1-9])|([12][0-9])|(3[01]))(\\.)((0[1-9])|(1[012]))(\\.)((19|20)[\\d][\\d])";
    public static String emeil = "^[\\w]{1,20}[\\@][A-Za-z]{1,20}[\\.](com|ru|ua)";

}
