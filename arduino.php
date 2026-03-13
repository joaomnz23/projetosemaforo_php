<?php
class Semaforo
{

    private $porta;

    public function __construct($porta)
    {
        $this->porta = $porta;
    }

    private function enviar($cmd)
    {

        exec("echo $cmd > {$this->porta}");
    }

    public function desligar()
    {
        $this->enviar("D");
    }

    public function lento()
    {
        $this->enviar("1");
    }

    public function medio()
    {
        $this->enviar("2");
    }

    public function rapido()
    {
        $this->enviar("3");
    }
}
