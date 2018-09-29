<?php
include_once 'core/sql.php';
include_once 'core/crud.php';

class Student implements CRUD {
    private $student_id = null;
    private $name = null;
    private $surname = null;
    private $patronymic = null;
    private $birth_date = null;
    private $fp_name = null;
    private $exam_name = null;

    public function __construct(){}

    public function __get($field){
        return $this->$field;
    }
	
    public function findId($id){
        $fields = SqlBuilder::table('students')->select()
            ->where(array(":student_id" => $id), '=')->get();
        $fields = $fields[0];
        foreach ($fields as $key => $value) {
            $this->$key = $value;
        }
        return $fields;
    }

    public function read(){
        $fields = SqlBuilder::table('students')->select()
            ->where(array(":student_id" => $this->student_id), '=')->get();
        $fields = $fields[0];
        echo '<table border="1">'
        . "<caption>Student</caption>"
        . "<tr>";
        while(current($fields) != null){
            echo "<th>" . key($fields) . "</th>";
            next($fields);
        }
        echo "</tr><tr>";

        foreach ($fields as $v){
            echo "<td>" . $v . "</td>";
        }
        echo "</tr>";
    }
	//$name, $surname, $patronymic, $birth_date, $fp_name
	public static function create($fields){
        SqlBuilder::table('students')->insert($fields)->send();
        return new static();
    }

    public function update($field){
        $key = str_replace(":", "", key($field));
        $this->$key = $field[key($field)];
        SqlBuilder::table('students')->update($field)
            ->where(array(':student_id' => $this->student_id),'=')->send();
    }

    public function delete(){
        SqlBuilder::table('students')->delete()->where(array(':student_id' => $this->student_id),'=')
            ->send();
        $this->student_id = null;
        $this->name = null;
        $this->surname = null;
        $this->patronymic = null;
        $this->birth_date = null;
        $this->fp_name = null;
        $this->exam_name = null;
    }

    public function register_fp($fp_id){
        $fp = SqlBuilder::table('fp')->select()->where(array(':fp_id' => $fp_id), '=')->get();
        $fp = $fp[0];
        SqlBuilder::table('students')->update(array(':fp_name' => $fp['fp_name']))
            ->where(array(':student_id' => $this->student_id),'=')->send();
        $this->fp_name = $fp['fp_name'];
    }

    public function passed_exam($exam_id){
        $exam = SqlBuilder::table('exams')->select()->where(array(':exam_id' => $exam_id), '=')->get();
        $exam = $exam[0];
        SqlBuilder::table('students')->update(array(':exam_name' => $exam['exam_name']))
            ->where(array(':student_id' => $this->student_id),'=')->send();
        $this->exam_name = $exam['exam_name'];
    }
}