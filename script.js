// Variáveis de controle
let temporizador = null;
let modoAtual = 'lento';   // padrão
let estado = 'desligado';  // 'verde', 'amarelo', 'vermelho' ou 'desligado'

// Mapeamento dos tempos (em ms)
const tempos = {
  rapido: { base: 4000, amarelo: 2000 },
  medio:  { base: 6000, amarelo: 3000 },
  lento:  { base: 8000, amarelo: 4000 }
};

// Função para enviar comando ao Arduino
function enviar(acao) {
  fetch('action.php?acao=' + acao)
    .then(response => response.text())
    .then(data => {
      console.log("Resposta do Arduino: " + data);
    });

  // Ações locais na interface
  if (acao === 'desligar') {
    pararCiclo();
    apagarTodasLuzes();
    estado = 'desligado';
  } else {
    // 'rapido', 'medio' ou 'lento'
    iniciarModo(acao);
  }
}

// Inicia o ciclo de luzes para o modo escolhido
function iniciarModo(modo) {
  // Se já estiver rodando um ciclo, para
  pararCiclo();
  
  modoAtual = modo;
  estado = 'verde';  // começa pelo verde
  acenderLuz('verde');
  
  // Inicia o temporizador para alternar as luzes
  temporizador = setInterval(proximaLuz, obterTempoAtual());
}

// Função chamada a cada mudança de estado
function proximaLuz() {
  // Limpa o intervalo atual
  clearInterval(temporizador);
  
  // Define o próximo estado
  if (estado === 'verde') {
    estado = 'amarelo';
    acenderLuz('amarelo');
    temporizador = setInterval(proximaLuz, tempos[modoAtual].amarelo);
  } else if (estado === 'amarelo') {
    estado = 'vermelho';
    acenderLuz('vermelho');
    temporizador = setInterval(proximaLuz, tempos[modoAtual].base);
  } else if (estado === 'vermelho') {
    estado = 'verde';
    acenderLuz('verde');
    temporizador = setInterval(proximaLuz, tempos[modoAtual].base);
  }
}

// Retorna o tempo atual baseado no estado e modo
function obterTempoAtual() {
  if (estado === 'verde' || estado === 'vermelho') {
    return tempos[modoAtual].base;
  } else if (estado === 'amarelo') {
    return tempos[modoAtual].amarelo;
  }
  return 0;
}

// Acende a luz especificada e apaga as outras
function acenderLuz(cor) {
  const vermelho = document.getElementById('vermelho');
  const amarelo = document.getElementById('amarelo');
  const verde = document.getElementById('verde');
  
  // Remove todas as classes de cor
  vermelho.classList.remove('vermelho');
  amarelo.classList.remove('amarelo');
  verde.classList.remove('verde');
  
  // Adiciona a classe correspondente
  if (cor === 'vermelho') vermelho.classList.add('vermelho');
  if (cor === 'amarelo') amarelo.classList.add('amarelo');
  if (cor === 'verde') verde.classList.add('verde');
}

// Apaga todas as luzes
function apagarTodasLuzes() {
  document.getElementById('vermelho').classList.remove('vermelho');
  document.getElementById('amarelo').classList.remove('amarelo');
  document.getElementById('verde').classList.remove('verde');
}

// Para o ciclo atual
function pararCiclo() {
  if (temporizador) {
    clearInterval(temporizador);
    temporizador = null;
  }
}