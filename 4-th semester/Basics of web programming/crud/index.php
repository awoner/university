<?php
require_once 'LehaFramework/sql.php';
require_once 'student.php';

$db = new SqlBuilder();
$db->connect('mydb');

$fields = array(':name' => "Evgeniy",
                ':surname' => "Bajenov",
                ':patronymic' => "BadC",
                ':number' => "tm-4132",
                ':birth_date' => "22.04.1989",
                ':fp_name' => "swimming",
                ':exam_name' => "mathematics");

//$db::table('students')->insert($fields)->values($fields)->send($fields);
$lol = new Student();
$lol->create($fields);
$lol->findId(2);
echo '<br>';echo '<br>';

$lol->update('name', 'Leha');
$lol->findId(2);
echo '<br>';echo '<br>';

$lol->register_fp(2);
$lol->findId(2);
echo '<br>';echo '<br>';

$lol->passed_exam(2);
$lol->findId(2);

$lol->read();

//$kek = $db::table('students')->select()->get();
//var_dump($kek);
