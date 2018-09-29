<?php
require_once 'pdo.php';
class SqlBuilder{
    private $dbh;
    private $table = null;
    private $query = null;

    public function __construct($db = 0){
        $this->dbh = PDOWrapper::setInstance();
    }

    public function connect($db){
        $this->dbh->connect($db);
    }

    /**
     * @return null
     */
    public function table($name_of_table){
        return $this->table = $name_of_table;
    }

    public function select(string...$fields){
        if($fields != null) {
            $this->query = "SELECT `" . $fields = implode("`,`", $fields) . "` FROM `" . $this->table . "`";
            return $this;
        }else{
            $this->query = "SELECT * FROM `" . $this->table . "`";
            return $this;
        }
    }

    public function where(string $field1, string $operator = '=', string $value){
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

    public function insert(){
            $this->query = "INSERT ";
            return $this;
    }

    public function into(string $table, string $field, string...$otherFields){
       $this->query = $this->query . " INTO `" . $table . "`(`" . $field . "`,`"
           . $otherFields = implode("`,`", $otherFields) . "`)";
        return $this;
    }

    public function values(string $placeholder1, string...$otherPlaceholders){
        //var_dump($placeholder1, $otherPlaceholders);
        $this->query = $this->query . " VALUES(" . $placeholder1 . "," .
            $otherPlaceholders = implode(",", $otherPlaceholders) . ")";
        var_dump($this->query);
        return $this;
    }

    public function execute($placeholders = []){
        return $this->dbh->SQL($this->query, $placeholders);
    }

    public function get(){
        return $this->dbh->SQL($this->query);
    }

    /**
     * @return null|PDOWrapper
     */
    public function getDbh(): PDOWrapper{
        return $this->dbh;
    }
}