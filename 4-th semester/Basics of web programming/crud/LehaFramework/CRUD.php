<?php
interface CRUD{
    public function create($fields);
    public function read($fields);
    public function update($field, $value);
    public function delete();
}