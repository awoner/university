package model.entities;

import java.util.ArrayList;

public class Notebook {
    private ArrayList<Note> Notes;
    public Notebook (){
        Notes = new ArrayList<>();
    }

    public void addNote(Note newNote){
        Notes.add(newNote);
    }

    public ArrayList<Note> getNotes(){ return Notes; }
}
