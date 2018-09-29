<?php
define('DEFINE', 12); //дериктива(константа)

trait Example                               //це те саме що клас,
{                                           //створити екземпляр якого не можливо,
                                            //але можливо реалізувати множинне "успадковування"
    public static function ShowTrait()
    {
        echo 'This is trait!';
    }
}

interface iTemplate                         //те саме що абстрактний класс у С++
{
    public function showAnonFunc();
    public function func();
}

class A implements iTemplate
{
    public $var = 'Leha Garnich-Petych';
    public $pub = 'Public';                 //поле яке доступне за межами классу
    protected $protect = 'Protected';       //поле яке доступне у самому класі та у дочірніх від ньго класів
    private $prvt = 'Private';              //поле яке доступне лишу у цьому класі

    public function __set($name, $value)    //магічний метод який дозволяє задавати значення приватним полям
    {
        $this->prvt = $value;               //псевдозмінна на поле
    }

    public function __get($name)            //магічний метод за допомогою якого можливо викликати приватне поле
    {
        return $this->$name;                //посилання на викликаючий об"єкт
    }

    public function __construct()           //конструктор класу(викликається при створванні об"єкта цього класу)
    {
        echo 'constuctor of class A <br>';
    }

    public function showAnonFunc()
    {
        $this->var = function()             //анонімна функція
        {
            return 'kek';
        };
    }

    public function func()
    {
        if (isset($this)) {                 //чи об"явленний обьект класу
            echo '$this определена (';
            echo get_class($this);          //повертає ім"я класу
            echo ")<br>";
        } else {
            echo "\$this не определена.<br>";
        }
    }

    function __destruct() {                 //деструктор класу(викликаеться при видаленні об"єктів класу)
        echo $this->var . " is deleted" . "<br>";
    }
}

class B extends A                            //клас В є дочірнім класом А
{
    use Example;                             //використання трейтів
    public $bar = 'field';                   //метод і змінна з однією назвою
    const CONSTANT = 'value of Constant<br>';//константа

    public function __call($name, $arguments) {//при виклику неіснуючого методу
        echo "Calling method '$name' <br>";
    }

public static function __callStatic($name, $arguments) {
        echo "CAlling static method '$name' <br>";
    }

    static public function getNew()         //метод який створює новий об"єкт
    {
        return new static;
    }

    public function bar()                   //-------------------------------------------
    {
        return 'method';
    }

    public function func()
    {
        echo 'B call parent function<br>';
        parent::func();                     //виклик батьківсього методу
    }

    function showConstant() {
        echo  self::CONSTANT;               //виклик константи цього класу
    }
}

class Singleton                             //паттерн проектування Сінглтон
{                                           //можливість створювати лише один об"єкт класу
    private static $instance = null;

    private function __construct(){}
    private function __clone(){}            //щоб не можна будо клонувати об"єкти
    public function __invoke(){}            //як перевантаження оператору () в С++

    public static function setInstance()    //метод який створює о"єкт класу
    {
        if (null === self::$instance)       //якщо нема ще об"єктів тоді створити
        {
            self::$instance = new self();
        }
        return self::$instance;             //якщо є - повернути існуючий
    }

    public function test()                  //інформація про клас
    {
        var_dump($this);
    }
}

$a = new A();
echo $a->pub . '<br>';                      //виклик публічної змінної
$a->func();
echo $a->var;

$a->showAnonFunc();                         //демонстрування анонімної ф-ції
echo '<br>';
echo ($a->var)();                           //демонстрування анонімної ф-ції
echo '<br>';

$className = 'A';
$instance = new $className();               //створювання об"єкту класа А
$instance->var = 'KOKOKOKOKOKO';            //ініціалізація змінної
$assigned = $instance;                      //присвоювання копії об"єкта $instance

var_dump($instance);
echo "<br>";

$instance = null;
var_dump($instance);
echo "<br>";

var_dump($assigned);
echo "<br>";

$obj1 = new B();
$obj2 = new $obj1;
var_dump($obj1 !== $obj2);         //повертає тру якщо вони не рівні
echo "<br>";

$obj3 = B::getNew();                         //створювання об"єкту через метод getNew()
var_dump($obj3 instanceof A);      //повертає тру якщо $obj3 екземпляр або наслідник класу А
echo "<br>";

echo (new DateTime())->format('y-m-d h:i:s');//вивід дати
echo "<br>";

echo $obj3->bar, PHP_EOL, $obj3->bar(), PHP_EOL;//різниця між викликом методу та змінної
echo "<br>";

$obj3->func();

$obj3->showConstant();
echo 'Define ' . DEFINE . '<br>';

$arr = array(                                  //ініціалізація масиву
    "foo" => "bar",
    "bar" => "foo",
    1   => -100,
    2  => 100,
);
foreach ($arr as $key => $value)                //вивід елементів масиву на екран за допомогою цикла
    echo $value . ' ';
echo '<br>';

$s = Singleton::setInstance();                  //створювання об"єкту класа Синглтон
$s->test();
echo '<br>';

$a1 = new A();
$a1->prvt = 'lol';                              //присвоювання значення приватному полю
echo $a1->prvt . '<br>';                        //та виклик приватного поля
                                                // за допомогою магічного методу
$obj3->ShowTrait();                             //демонстрація роботи трейту
echo '<br>';

$obj3->PETYH();                                 //виклик неіснуючого методу

$str = array('ko','ko','ko','ko');

$g = implode(',' , $str);                  //поєднання єлементів массиву
                                                 //в одну строку з роз"єднувачем ","
echo $g;
echo '<br>';

$pie  = "piece1 piece2 leha garnik loh";
$pieces = explode(" ", $pie);           //розділення строки на елементи масиву
echo $pieces[2]; // шматок3
echo '<br>';
echo $pieces[3]; // шматок4
echo '<br>';
echo $pieces[4]; // шматок5
echo '<br>';

$name = 'Den';
$Den = 'Tryhan';
$$name == 'Tryhan' ? $name = 'Leha' : $name = 'Dimas'
echo 'Name is ' . $name;

for ($i = 10; $i >= 0; $i--)
{
    if ($i === 5)
        echo 'VAAAAAAAU Iteration ' . $i . ' in cycle for!!!!!!<br>';
    echo 'Iteration ' . $i . ' in cycle for<br>';
}

do{
    echo "Operation " . $z . " in cycle do while<br>";
    $z++;
}while($z < 10);