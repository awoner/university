<?php
include_once 'LehaFramework/sql.php';

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
            ->where('student_id', '=', $id)->get();
        $fields = $fields[0];
        foreach ($fields as $key => $value) {
            $this->$key = $value;
        }
    }

    public function read($fields = null){
        $fields = SqlBuilder::table('students')->select($fields)->get();
        $fields = $fields[0];
        var_dump($fields);
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
	public function create($fields){
        SqlBuilder::table('students')->insert($fields)
            ->values($fields)->send();
    }

    public function update($field, $value){
        $this->$field = $value;
        SqlBuilder::table('students')->update($field, $value)
            ->where('student_id','=', $this->student_id)->send();
    }

    public function delete(){
        SqlBuilder::table('students')->delete()->where('student_id','=', $this->student_id)
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
        $fp = SqlBuilder::table('fp')->select()->where('fp_id', '=', $fp_id)->get();
        $fp = $fp[0];
        SqlBuilder::table('students')->update('fp_name', $fp['fp_name'])
            ->where('student_id','=', $this->student_id)->send();
        $this->fp_name = $fp['fp_name'];
    }

    public function passed_exam($exam_id){
        $exam = SqlBuilder::table('exams')->select()->where('exam_id', '=', $exam_id)->get();
        $exam = $exam[0];
        SqlBuilder::table('students')->update('exam_name', $exam['exam_name'])
            ->where('student_id','=', $this->student_id)->send();
        $this->exam_name = $exam['exam_name'];
    }
}