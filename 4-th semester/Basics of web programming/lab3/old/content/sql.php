<?php
require_once 'pdo.php';
class SqlBuilder{
    private $dbh;
    private $query = null;

    public function __construct($db){
        $this->dbh = PDOWrapper::setInstance();
        $this->dbh->connect($db);
    }

//    public function table($table){
//        $this->query = "SELECT * FROM `".$table."`";
//        return $this->dbh->SQL($query);
//    }

    public function table(string $table, string...$fields){
        if($fields != null) {
            $this->query = "SELECT `" . $fields = implode("`,`", $fields) . "` FROM `" . $table . "`";
            return $this;
        }else{
            $this->query = "SELECT * FROM `" . $table . "`";
            return $this;
        }
    }

    public function where(string $field1, string $operator = '=', string $value){
        if($this->query != null) {
            $this->query = $this->query . "WHERE " . $field1 . " " . $operator . " '" . $value . "'";
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

    public function insert(string $field, string...$otherFields){
        if($otherFields != null) {
            $this->query = "INSERT `" . $field . "`," . $otherFields = implode("`,`", $otherFields) . "`";
            return $this;
        }else{
            $this->query = "INSERT `" . $field . "`";
            return $this;
        }
    }

    public function into(string $table){
        $this->query = $this->query . " INTO " . $table . "`";
    }

    public function values(string $placeholder1, string...$otherPlaceholders){
        $this->query = $this->query . " VALUES(" . $placeholder1 . "," .
            $otherPlaceholders = implode(",", $otherPlaceholders) . ")";
        return $this;
    }

    public function execute($placeholders = []){
        return $this->dbh->DSQL($this->query, $placeholders);
    }

    public function get(){
        return $this->dbh->DSQL($this->query);
    }
}