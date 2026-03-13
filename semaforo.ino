int vermelho = 11;
int amarelo = 10;
int verde = 9;
char modo = 'p';

void setup() {
  Serial.begin(9600);
  pinMode(vermelho, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(verde, OUTPUT);
}

void loop() {

  if (Serial.available() > 0) {
    modo = Serial.read();
  }

  // MODO 1
  if (modo == '1') {
    digitalWrite(verde, HIGH);
    if (esperar(20000)) return;
    digitalWrite(verde, LOW);

    digitalWrite(amarelo, HIGH);
    if (esperar(3000)) return;
    digitalWrite(amarelo, LOW);

    digitalWrite(vermelho, HIGH);
    if (esperar(20000)) return;
    digitalWrite(vermelho, LOW);

    modo = 'p';
  }

  // MODO 2
  if (modo == '2') {
    digitalWrite(verde, HIGH);
    if (esperar(15000)) return;
    digitalWrite(verde, LOW);

    digitalWrite(amarelo, HIGH);
    if (esperar(3000)) return;
    digitalWrite(amarelo, LOW);

    digitalWrite(vermelho, HIGH);
    if (esperar(15000)) return;
    digitalWrite(vermelho, LOW);

    modo = 'p';
  }

  // MODO 3
  if (modo == '3') {
    digitalWrite(verde, HIGH);
    if (esperar(10000)) return;
    digitalWrite(verde, LOW);

    digitalWrite(amarelo, HIGH);
    if (esperar(3000)) return;
    digitalWrite(amarelo, LOW);

    digitalWrite(vermelho, HIGH);
    if (esperar(10000)) return;
    digitalWrite(vermelho, LOW);

    modo = 'p';
  }

  // RESET
  if (modo == 'p') {
    digitalWrite(vermelho, LOW);
    digitalWrite(amarelo, LOW);
    digitalWrite(verde, LOW);
  }
}

bool esperar(long tempo) {
  long inicio = millis();

  while (millis() - inicio < tempo) {

    if (Serial.available() > 0) {
      char comando = Serial.read();
      if (comando == 'p') {
        modo = 'p';
        digitalWrite(vermelho, LOW);
        digitalWrite(amarelo, LOW);
        digitalWrite(verde, LOW);
        return true;
      }
    }
  }

  return false;
}
