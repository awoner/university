package model;

import model.entities.Note;
import model.entities.Notebook;

import java.util.*;

public class Model {
    private static Model instance = null;
    private Notebook notebook = new Notebook();
    private Note note = new Note();
    private Note tempNote = new Note();

    public void setNote() {
        this.note = tempNote;
        tempNote = new Note();
        notebook.addNote(this.note);
    }

    public Note getTempNote() {
        return tempNote;
    }

    public ArrayList<Note> getAllNotes() {
        return notebook.getNotes();
    }

    public static Model getInstance() {
        if (instance == null) {
            instance = new Model();
        }
        return instance;
    }
}