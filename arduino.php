<?php
class Arduino
{
    private $porta;

    public function __construct($porta)
    {
        $this->porta = $porta;
    }

    private function enviarComando($comando)
    {
        // O '&' permite rodar dois comandos em sequência no Windows
        // Configuramos a porta e enviamos o comando logo em seguida
        $cmd = "mode " . $this->porta . " BAUD=9600 PARITY=N DATA=8 STOP=1 & echo " . $comando . " > " . $this->porta;
        exec($cmd);
    }

    public function desligar()
    {
        $this->enviarComando("d");
    }

    public function rapido()
    {
        $this->enviarComando("r");
    }

    public function medio()
    {
        $this->enviarComando("m");
    }

    public function lento()
    {
        $this->enviarComando("l");
    }
}
