<?php
include_once "app/models/student.php";
include_once "app/views/view.php";
class StudentController{
    public function student($id){
        $st = new Student();
        $st = $st->findId($id);
        return Tpl::output('students', ['student' => $st]);
    }
}