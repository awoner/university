package mvc.Model;

import java.util.ArrayList;

public class Model {
    private Notebook notebook;
    private Note note;
    private Note tempNote;

    public Model(){
        notebook = new Notebook();
        tempNote = new Note();
    }

    public void setNote(){
        this.note = tempNote;
        tempNote = null;
        notebook.addNote(this.note);
    }

    public Note getTempNote(){ return tempNote; }
    public ArrayList<Note> getAllNotes(){ return notebook.getNotes(); }
}