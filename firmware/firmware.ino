/*
 * SEMÁFORO COM VELOCIDADE VARIÁVEL
 * 
 * Envie um caractere pela serial para:
 *   'r' - rápido (4s)
 *   'm' - médio (6s)
 *   'l' - lento (8s)
 *   'd' - desligar (todos os LEDs apagados)
 * 
 * O tempo do verde e vermelho é igual (valor escolhido).
 * O tempo do amarelo é a metade.
 * 
 * Conexões:
 *   Vermelho – pino 13
 *   Amarelo  – pino 12
 *   Verde    – pino 11
 * 
 * AGORA: Inicia desligado e só liga ao receber 'r', 'm' ou 'l'.
 */

int ledVermelho = 8;
int ledAmarelo = 9;
int ledVerde = 10;

unsigned long tempoBase = 8000;  // lento (8s) padrão
unsigned long tempoAmarelo;        // tempoBase / 2

int estado = 0;  // 0=verde, 1=amarelo, 2=vermelho
unsigned long tempoAnterior = 0;

bool ligado = false;  // começa desligado!

void setup() {
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);

  // Garantir que todos os LEDs comecem apagados
  digitalWrite(ledVermelho, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVerde, LOW);

  Serial.begin(9600);
  Serial.println("Controle do semáforo - Digite r, m, l ou d");

  tempoAmarelo = tempoBase / 2;
  // Não acende nada - aguarda comando
}

void loop() {
  // Verificar comandos
  if (Serial.available() > 0) {
    String linha = Serial.readStringUntil('\n');
    linha.trim();

    if (linha.length() > 0) {
      char comando = linha.charAt(0);

      if (comando == 'r' || comando == 'R') {
        tempoBase = 4000;
        tempoAmarelo = tempoBase / 2;
        Serial.println("Modo RÁPIDO (4s)");
        if (!ligado) {
          ligado = true;
          estado = 0;  // começa no verde
          digitalWrite(ledVerde, HIGH);
          tempoAnterior = millis();
        }
      } else if (comando == 'm' || comando == 'M') {
        tempoBase = 6000;
        tempoAmarelo = tempoBase / 2;
        Serial.println("Modo MÉDIO (6s)");
        if (!ligado) {
          ligado = true;
          estado = 0;
          digitalWrite(ledVerde, HIGH);
          tempoAnterior = millis();
        }
      } else if (comando == 'l' || comando == 'L') {
        tempoBase = 8000;
        tempoAmarelo = tempoBase / 2;
        Serial.println("Modo LENTO (8s)");
        if (!ligado) {
          ligado = true;
          estado = 0;
          digitalWrite(ledVerde, HIGH);
          tempoAnterior = millis();
        }
      } else if (comando == 'd' || comando == 'D') {
        ligado = false;
        digitalWrite(ledVermelho, LOW);
        digitalWrite(ledAmarelo, LOW);
        digitalWrite(ledVerde, LOW);
        Serial.println("Semáforo DESLIGADO");
      } else {
        Serial.println("Comando inválido! Use r, m, l ou d");
      }
    }
  }

  // Só executa o ciclo se estiver ligado
  if (ligado) {
    unsigned long agora = millis();

    if (estado == 0) {  // Verde
      if (agora - tempoAnterior >= tempoBase) {
        digitalWrite(ledVerde, LOW);
        digitalWrite(ledAmarelo, HIGH);
        estado = 1;
        tempoAnterior = agora;
      }
    } else if (estado == 1) {  // Amarelo
      if (agora - tempoAnterior >= tempoAmarelo) {
        digitalWrite(ledAmarelo, LOW);
        digitalWrite(ledVermelho, HIGH);
        estado = 2;
        tempoAnterior = agora;
      }
    } else if (estado == 2) {  // Vermelho
      if (agora - tempoAnterior >= tempoBase) {
        digitalWrite(ledVermelho, LOW);
        digitalWrite(ledVerde, HIGH);
        estado = 0;
        tempoAnterior = agora;
      }
    }
  }
}