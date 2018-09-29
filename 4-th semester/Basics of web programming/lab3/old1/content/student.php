<?php
include_once 'SQLbuilder.php';

class Student{
    private $id = null;
    private $name = null;
    private $surname = null;
    private $patronyc = null;
    private $age = null;

    public function __construct(){}

    public function __get($field){
        return $this->$field;
    }
	
    public function findId($id){
        $db = new SqlBuilder('php_lab');

        $fields =$db->table('students')->select()->where('id', '=', $id)->get();
        var_dump($fields);
    }
	
	
}