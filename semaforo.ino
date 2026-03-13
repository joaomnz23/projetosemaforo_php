int vermelho = 11;
int amarelo = 10;
int verde = 9;
char modo;

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

  // MODO 1: LENTO
  if (modo == '1') {
    digitalWrite(verde, HIGH);    delay(20000); digitalWrite(verde, LOW);
    digitalWrite(amarelo, HIGH);  delay(10000); digitalWrite(amarelo, LOW);
    digitalWrite(vermelho, HIGH); delay(20000); digitalWrite(vermelho, LOW);
  }

  // MODO 2: MEDIO
  if (modo == '2') {
    digitalWrite(verde, HIGH);    delay(15000); digitalWrite(verde, LOW);
    digitalWrite(amarelo, HIGH);  delay(5000);  digitalWrite(amarelo, LOW);
    digitalWrite(vermelho, HIGH); delay(15000); digitalWrite(vermelho, LOW);
  }

  // MODO 3: RAPIDO
  if (modo == '3') {
    digitalWrite(verde, HIGH);    delay(10000); digitalWrite(verde, LOW);
    digitalWrite(amarelo, HIGH);  delay(3000);  digitalWrite(amarelo, LOW);
    digitalWrite(vermelho, HIGH); delay(10000); digitalWrite(vermelho, LOW);
  }

  // MODO P: RESET (DESLIGAR TUDO)
  if (modo == 'D') {
    digitalWrite(vermelho, LOW);
    digitalWrite(amarelo, LOW);
    digitalWrite(verde, LOW);
  }
}
