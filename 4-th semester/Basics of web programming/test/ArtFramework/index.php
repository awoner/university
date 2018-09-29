<?php
require_once 'core/sql.php';
require_once 'core/router.php';
//require_once 'app/models/student.php';
//require_once 'app/controllers/StudController.php';

$db = new SqlBuilder();
$db->connect('php_db');

//$fields = array(':name' => "Evgeniy",
//                ':surname' => "Bajenov",
//                ':patronymic' => "BadC",
//                ':number' => "tm-4132",
//                ':birth_date' => "22.04.1989",
//                ':fp_name' => "swimming",
//                ':exam_name' => "mathematics");
//
////$db::table('students')->insert($fields)->values($fields)->send($fields);
//
//$db::table('students')->update(array(':name' => "Jeka"))->update(array(':surname' => "Kek"))->where(array(':student_id' => 55), '=')->send();

//var_dump($txt);
//$s = new Student();
//$s->findId(55);
//echo '<br>';echo '<br>';
//$s->read();
//$s->update(array(':name' => 'Deniska'));
//$s->read();
//////
//$s->register_fp(1);
//$s->read();
////
//$s->passed_exam(2);
//$s->read();


$r = new Router();
$r->addRoute("ArtFramework/{id}","StudentController@student@(id)");
$r->run();


//$st = new StudentController();
//echo $st->student(3);

//$kek = $db::table('students')->select()->get();
//var_dump($kek);