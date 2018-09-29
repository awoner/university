package model;

import com.sun.corba.se.impl.encoding.OSFCodeSetRegistry;
import com.sun.xml.internal.bind.v2.util.QNameMap;
import model.entities.Abonent;

import javax.persistence.criteria.CriteriaBuilder;
import java.util.*;

public class Model {
    private static Model instance = null;
    private Map<Integer,Abonent> abonents = new HashMap<>();


    public void addAbonents(Integer telephone, Abonent abonent){
        this.abonents.put(telephone, abonent);
    }

    public Abonent createAbonent(String name, String surname, String patronymic, String address){
        return new Abonent(name, surname, patronymic, address);
    }

    public static Model getInstance(){
        if (instance == null){
            instance = new Model();
        }
        return instance;
    }

    public Map<Integer, Abonent> getAbonents() {
        return abonents;
    }

//    public Map<Integer, Abonent> setAbonents() {
//        return abonents;
//    }

    public List<Map.Entry<Integer, Abonent>> sort(){
        List<Map.Entry<Integer, Abonent>> entryList = new ArrayList<>(abonents.entrySet());
        System.out.println("IN BEFORE MODEL.SORT():::>>>>" + abonents.toString());
//        Collections.sort(entryList, new Comparator<Map.Entry<Integer, Abonent>>() {
//            @Override
//            public int compare(Map.Entry<Integer, Abonent> e1, Map.Entry<Integer, Abonent> e2) {
//                return e1.getKey().compareTo(e2.getKey());
//            }
//        } );
       entryList.sort(new Comparator<Map.Entry<Integer, Abonent>>() {
            @Override
            public int compare(Map.Entry<Integer, Abonent> e1, Map.Entry<Integer, Abonent> e2) {
                return e2.getKey() - e1.getKey();
            }
        } );

        //abonents = new HashMap<Integer, Abonent>();

//        for( Map.Entry<Integer,Abonent> me : entryList)
//            abonents.put(me.getKey(), me.getValue());
        return entryList;
        }
}
