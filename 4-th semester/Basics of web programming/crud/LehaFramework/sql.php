<?php
require_once 'pdo.php';
class SqlBuilder{
    private $dbh;
    private static $table = null;
    private $query = null;

    public function __construct(){
        $this->dbh = PDOWrapper::setInstance();
    }

    public function connect($db){
        $this->dbh->connect($db);
    }

    public static function table($name){
        SqlBuilder::$table = $name;
        return new static;
    }

    public function select($fields = null){
        if($fields != null) {
            $keys = key($fields);
            next($fields);
            while(current($fields) != null){
                $keys = $keys . ", " . key($fields);
                next($fields);
            }
            $keys = str_replace(":", "", $keys);
            $this->query = "SELECT `" . $keys . "` FROM `" . SqlBuilder::$table . "`";
            return $this;
        }else{
            $this->query = "SELECT * FROM `" . SqlBuilder::$table . "`";
            return $this;
        }
    }

    public function where(string $field1, string $operator, string $value){
        if($this->query != null) {
            $this->query = $this->query . " WHERE " . $field1 . " " . $operator . " '" . $value . "'";
            return $this;
        }else{
            echo 'Для начала выберете таблицу(ы).';
        }
    }

    public function and(string $field1, string $operator = '=', string $value){
        $this->query = $this->query . " AND ". $field1 . " " . $operator . " '" . $value . "'";
        return $this;
    }

    public function orderBy(string $field){
        $this->query = $this->query . " ORDER BY " . $field;
        return $this;
    }

//    public function insert(string $field, string...$otherFields){
//        $this->query = "INSERT INTO `" . SqlBuilder::$table . "`(`" . $field . "`,`"
//            . $otherFields = implode("`,`", $otherFields) . "`)";
//        return $this;
//    }

    public function insert($fields){
        $keys = key($fields);
        next($fields);
        while(current($fields) != null){
            $keys = $keys . ", " . key($fields);
            next($fields);
        }
        $keys = str_replace(":", "", $keys);
        $this->query = "INSERT INTO " . SqlBuilder::$table . "(" . $keys . ")";
        return $this;
    }

//    public function values(string $placeholder1, string...$otherPlaceholders){
//        $this->query = $this->query . " VALUES('" . $placeholder1 . "','" .
//            $otherPlaceholders = implode("','", $otherPlaceholders) . "');";
//        var_dump($this->query);
//        return $this;
//    }

    public function values($fields){
        $values = key($fields);
        next($fields);
        while(current($fields) != null){
            $values = $values . ", " . key($fields);
            next($fields);
        }
        $this->query = $this->query . " VALUES(" . $values . ");";
        return $this;
    }

    public function update($field, $value){
        $this->query = "UPDATE " . SqlBuilder::$table . " SET " . $field . "='" . $value . "'";
        return $this;
    }

    public function delete(){
        $this->query = "DELETE FROM `" . SqlBuilder::$table . "`";
        return $this;
    }

    public function get($placeholders = []){
        return $this->dbh->SQL($this->query, $placeholders);
    }

    public function dGet($placeholders = []){
        return $this->dbh->SQL($this->query, $placeholders, true);
    }

    public function send($placeholders = []){
        $this->dbh->SSQL($this->query, $placeholders);
    }

    public function dSend($placeholders = []){
        $this->dbh->SSQL($this->query, $placeholders, true);
    }
}