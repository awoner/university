<?php
interface CRUD{
    public static function create($fields);
    public function read();
    public function update($field);
    public function delete();
}