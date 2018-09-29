package model.entities;

public class
Note {
    private String subName;
    private String subSurname;
    private String subPatronymic;
    private String subShortName;
    private String nickname;
    private String comment;
    private String group;
    private String homePhone;
    private String firstMobilePhone;
    private String secondMobilePhone;
    private String email;
    private String skype;
    private String addressIndex;
    private String addressCity;
    private String addressStreet;
    private String addressHouseNumber;
    private String addressApartmentNumber;
    private String fullAddress;
    private String creatingDate;
    private String modificationDate;

    public void setSubName(String subName){ this.subName = subName; }
    public void setSubSurname(String subSurname){ this.subSurname = subSurname; }
    public void setSubPatronymic(String subPatronymic){ this.subPatronymic = subPatronymic; }
    public void setNickname(String nickname){ this.nickname = nickname; }
    public void setComment(String comment){ this.comment = comment; }
    public void setHomePhone(String homePhone){ this.homePhone = homePhone; }
    public void setFirstMobilePhone(String firstMobilePhone){ this.firstMobilePhone = firstMobilePhone; }
    public void setSecondMobilePhone(String secondMobilePhone){ this.secondMobilePhone = secondMobilePhone; }
    public void setEmail(String email){ this.email = email; }
    public void setSkype(String skype){ this.skype = skype; }
    public void setAddressIndex(String addressIndex){ this.addressIndex = addressIndex; }
    public void setAddressCity(String addressCity){ this.addressCity = addressCity; }
    public void setAddressStreet(String addressStreet){ this.addressStreet = addressStreet; }
    public void setAddressHouseNumber(String addressHouseNumber){ this.addressHouseNumber = addressHouseNumber; }
    public void setAddressApartmentNumber(String addressApartmentNumber){ this.addressApartmentNumber = addressApartmentNumber; }
    public void setCreatingDate(String creatingDate){ this.creatingDate = creatingDate; }
    public void setModificationDate(String modificationDate){ this.modificationDate = modificationDate; }
    public void setGroup(String group) { this.group = group; }
    public void setSubShortName(){
        try {
            this.subShortName =
                    this.subSurname + " " + this.subName.substring(0,1) + ".";
        } catch (StringIndexOutOfBoundsException | NullPointerException ex){
            System.out.println(ex.getMessage());
        }
    }
    public void setFullAddress(){
        try {
            this.fullAddress =
                   "[" + this.addressIndex + "] " + this.addressCity + ", " +
                           this.addressStreet + ", " + this.addressHouseNumber + "-" + this.addressApartmentNumber;
        } catch (NullPointerException ex){
            System.out.println(ex.getMessage());
        }
    }

    public String getSubName() {
        return subName;
    }

    public String getSubSurname() {
        return subSurname;
    }

    public String getSubPatronymic() {
        return subPatronymic;
    }

    public String getSubShortName() {
        return subShortName;
    }

    public String getNickname() {
        return nickname;
    }

    public String getComment() {
        return comment;
    }

    public String getGroup() {
        return group;
    }

    public String getHomePhone() {
        return homePhone;
    }

    public String getFirstMobilePhone() {
        return firstMobilePhone;
    }

    public String getSecondMobilePhone() {
        return secondMobilePhone;
    }

    public String getEmail() {
        return email;
    }

    public String getSkype() {
        return skype;
    }

    public String getAddressIndex() {
        return addressIndex;
    }

    public String getAddressCity() {
        return addressCity;
    }

    public String getAddressStreet() {
        return addressStreet;
    }

    public String getAddressHouseNumber() {
        return addressHouseNumber;
    }

    public String getAddressApartmentNumber() {
        return addressApartmentNumber;
    }

    public String getFullAddress() {
        return fullAddress;
    }

    public String getCreatingDate() {
        return creatingDate;
    }

    public String getModificationDate() {
        return modificationDate;
    }


    //    @Override
//    public String toString(){
//        View view = new View();
//        StringBuffer stringBuffer = new StringBuffer();
//        stringBuffer.append(view.OUTPUT_SHORT_NAME).append(subShortName).append("\n")
//                .append(view.NICKNAME_INVITATION).append(nickname).append("\n")
//                .append(view.COMMENT_INVITATION).append(comment).append("\n")
//                .append(view.GROUP_INVITATION).append(group).append("\n")
//                .append(view.HOME_PHONE_INVITATION).append(homePhone).append("\n")
//                .append(view.FIRST_MOBILE_PHONE_INVITATION).append(firstMobilePhone).append("\n")
//                .append(view.SECOND_MOBILE_PHONE_INVITATION).append(secondMobilePhone).append("\n")
//                .append(view.EMAIL_INVITATION).append(email).append("\n")
//                .append(view.SKYPE_INVITATION).append(skype).append("\n")
//                .append(view.OUTPUT_FULL_ADDRESS).append(fullAddress).append("\n")
//                .append(view.CREATE_DATE_INVITATION).append(creatingDate).append("\n")
//                .append(view.MODIFICATION_DATE_INVITATION).append(modificationDate).append("\n");
//        return stringBuffer.toString();
//    }
}
