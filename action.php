<?php
require "arduino.php";

$semaforo = new Arduino("COM3");

if (isset($_GET['acao'])) {
    if ($_GET['acao'] === 'desligar') {
        $semaforo->desligar();
        echo "DESLIGADO";
    } elseif ($_GET['acao'] === 'rapido') {
        $semaforo->rapido();
        echo "MODO RÁPIDO";
    } elseif ($_GET['acao'] === 'medio') {
        $semaforo->medio();
        echo "MODO MÉDIO";
    } elseif ($_GET['acao'] === 'lento') {
        $semaforo->lento();
        echo "MODO LENTO";
    } else {
        echo "AÇÃO INVÁLIDA";
    }
} else {
    echo "Nenhuma ação informada";
}
