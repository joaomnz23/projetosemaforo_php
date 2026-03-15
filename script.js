function enviar(acao) {
    fetch('action.php?acao=' + acao)
        .then(response => response.text())
        .then(data => {
            console.log("Resposta do Arduino: " + data);
        });
}