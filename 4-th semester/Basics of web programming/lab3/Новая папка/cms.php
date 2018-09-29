<?php
trait Singleton{
    private function __clone() {}
    private function __construct() {
        // parent::__construct($this->myName,$this->mySurname,$this->myYear);
    }
    private static $instance=Null;
    public static function getInstance(){
        if(Null===self::$instance){
            self::$instance = new self();}
        return self::$instance;
    }
}


class http{
    private $stringError="Wrong page";
    private $pages=array("main", "inform", "cont");
    use Singleton;

    public function getMethod($arg){
        if(empty($_GET["$arg"])) return $this->stringError;
        if($_GET["$arg"]!="main" && $_GET["$arg"]!="inform" && $_GET["$arg"]!="cont" ) return $this->stringError;
        if(isset($_GET["$arg"])) return $_GET["$arg"];
        //  if(empty($_GET["$arg"])) return $this->stringError;
    }

    public function postMethod($arg){
        if(isset($_POST["$arg"])) return $_POST["$arg"];
        else return $this->stringError;
    }
}

class CMS {
    function headHtml($arg){
        $arr[]="$arg";
        $arr[]="head.html";
        return implode("",$arr);
    }
    function contHtml($arg){
        $arr[]="$arg";
        $arr[]="page.html";
        return implode("",$arr);
    }
    public function buildPage ($arg){
        if($arg=="Wrong page") {echo "$arg"; return;}
        $head=$this->headHtml($arg);
        $page=$this->contHtml($arg);
        require_once "$head";
        require_once 'header.html';
        require_once "$page";
        require_once 'footer.html';

    }
}

$mySite= new CMS();
$obj = http::getInstance();
$result=$obj->getMethod("page");

$mySite->buildPage($result);