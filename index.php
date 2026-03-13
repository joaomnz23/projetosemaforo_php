<?php

require "arduino.php";

$semaforo = new Semaforo("COM6");
?>

<!DOCTYPE html>
<html lang="pt-br">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Semáforo</title>
</head>

<body>
    <div class="semaforo">
        <div id="vermelho" class="luz"></div>
        <div id="amarelo" class="luz"></div>
        <div id="verde" class="luz"></div>
    </div>

    <button id="Desligar" onclick="<?php $semaforo->desligar(); ?>">Desligar</button>

    <button id="lento" onclick="<?php $semaforo->lento() ?>">Lento</button>
    <button id="normal" onclick="<?php $semaforo->medio() ?>">Normal</button>
    <button id="rapido" onclick="<?php $semaforo->rapido() ?>">Rápido</button>

    <script src="tresF.js"></script>

</body>

</html>