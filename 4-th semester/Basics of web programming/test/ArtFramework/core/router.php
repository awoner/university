<?php
//namespace Core;
require_once 'app/models/student.php';
require_once 'app/controllers/StudController.php';
class Router{

    private $routes = [];

    public function addRoute($path, $func){
        $path = "^" . preg_replace("/{/", "(?<", $path) . "$";
        $path = preg_replace("/}/", ">\d+)", $path);
        $path = preg_replace("/\\//", "\\/", $path);
        $path = preg_replace("/\\^/", "/^\/", $path);
        $path = preg_replace("/\\$/", "\\/(\\?\S+?=\S+?)*?$/", $path);

        $this->routes[$path] = preg_split("/\\@/", $func);

        $args = $this->routes[$path][2] ?? null;
        if ($args) {
            $args = preg_replace("/(\\(|\\))/", "", $args);
            $this->routes[$path][2] = preg_split("/,/", $args);
        }
    }

    public function run(){
        $path_from_user = $_SERVER["REQUEST_URI"];

        foreach ($this->routes as $path => $handler) {
            $values_from_uri = [];
            $args_of_handler = [];

            if (preg_match($path, $path_from_user, $values_from_uri)) {

                if ($handler[2] ?? false)
                    $args_of_handler = $this->param_arr($handler[2], $values_from_uri);

                $request = call_user_func_array(array($handler[0], $handler[1]), $args_of_handler);
                echo $request;
            }
        }
    }

    private function param_arr($args_of_handler, $values_from_uri){
        $values = [];

        foreach ($args_of_handler as $arg)
            $values[] = $values_from_uri[$arg];

        return $values;
    }
}