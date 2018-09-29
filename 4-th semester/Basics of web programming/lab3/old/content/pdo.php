<?php

class PDOWrapper{
    private static $instance = null;
    private $dbh = null;
    private $db_name;

    private function __construct(){}
    private function __clone(){}            //щоб не можна будо клонувати об"єкти
    public function __invoke(){}            //як перевантаження оператору () в С++
    public function __get($name){}

    public static function setInstance(){   //метод який створює о"єкт класу
        if (null === self::$instance){      //якщо нема ще об"єктів тоді створити
            self::$instance = new self();
        }
        return self::$instance;             //якщо є - повернути існуючий
    }

//    public function debuging($debug){
//        $this->$debug = $debug;
//    }

    public function connect( $db_name, $driver = 'mysql', $host = 'localhost',
                             $charset = 'utf8', $db_user = 'root', $db_pass = '',
                             $options = [PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION], $debug = false){
        try {
            if($debug == false) {
                $this->db_name = $db_name;
                $this->dbh = new PDO("$driver:host=$host;dbname=$db_name;charset=$charset", $db_user, $db_pass, $options);
            }else{
                var_dump($db_name, $driver, $host,
                    $charset, $db_user, $db_pass,
                    $options);
                $this->dbh = new PDO("$driver:host=$host;dbname=$db_name;charset=$charset", $db_user, $db_pass, $options);
            }
        }catch(PDOException $exception){
            die('Не удалось подключиться к базе данных :(' . '<br>' . $exception->getMessage());
        }
    }

//    public function SQL($fields, $tables, $conditions = 1){
//        try {
//            if($debug == false) {
//                $dbh->prepare('SELECT ? FROM ? WHERE ?')
//                    ->execute([$fields, $tables, $conditions])
//                    ->fetchAll(PDO::FETCH_ASSOC);
//            }else{
//                var_dump($fields, $tables, $conditions);
//                $dbh->prepare('SELECT ? FROM ? WHERE ?')
//                    ->execute([$fields, $tables, $conditions])
//                    ->fetchAll(PDO::FETCH_ASSOC);
//            }
//        }catch(PDOException $exception){
//            echo 'Ошибка!' . $exception->getMessage();
//        }
//    }

    public function SQL($query, $placeholders = [], $debug = false){
        try {
            if($debug == false) {
                $result = $this->dbh->prepare($query);

                $executed = $result->execute($placeholders);

                if($executed) {
                    return $result->fetchAll(PDO::FETCH_ASSOC);
                }
            }else{
                var_dump($query);
                echo '<br>';

                var_dump($placeholders);
                echo '<br>';

                $result = $this->dbh->prepare($query);
                var_dump($result);
                echo '<br>';

                $executed = $result->execute($placeholders);
                var_dump($executed);
                echo '<br>';

                if($executed) {
                    return $result->fetchAll(PDO::FETCH_ASSOC);
                }
            }
        }catch(PDOException $exception){
            echo 'Ошибка!' . $exception->getMessage();
        }
    }

//    public function DSQL($fields, $tables, $conditions = 1){
//        try {
//            $result = $dbh->prepare('SELECT :fields FROM :tables WHERE :conditions')
//            ->execute(['fields' => $fields, 'tables' => $tables, 'conditions' => $conditions])
//            ->fetchAll(PDO::FETCH_ASSOC);
//            echo '<ul>';
//            foreach ($result as $i=>$val){
//                echo '<li>'. $i . '|' . $result[$i] .'</li>';
//            }
//            echo '</ul>';
//        } catch (PDOException $exception) {
//            echo 'Ошибка!' . $exception->getMessage();
//        }
//    }

    public function DSQL($query, $placeholders = []){
        try {
            $result = $this->dbh->prepare($query);

            $executed = $result->execute($placeholders);

            if($executed) {
                echo "<ul>";
                while ($row = $result->fetch(PDO::FETCH_ASSOC)) {
                    foreach ($row as $i => $val) {
                        echo "<li>|\t" . $i . "|\t" . $val . "|</li><br>";
                    }
                }
                echo "</ul>";
            }
        } catch (PDOException $exception) {
            echo 'Ошибка!' . $exception->getMessage();
        }
    }

    public function disconnect(){
        if($this->dbh != null){
            $dbh = null;
        }else{
            echo 'Невозможно отключится. Вы еще не подключились к БД!';
        }
    }
}