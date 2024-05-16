int ledPin = 10; // LED conectado ao pino digital 10
int botaoPin = 12; // botão conectado ao pino digital 12
int val = 0; // variável para guardar o valor lido da chave
void setup() {
pinMode(ledPin, OUTPUT); // configura o pino digital 10 como saída
pinMode(botaoPin, INPUT); // configura o pino digital 12 como entrada
}
void loop() {
val = digitalRead(botaoPin);// lê o pino de entrada onde está ligada a chave
if (val == HIGH) {
digitalWrite(ledPin, LOW); //Desliga LED
} else {
digitalWrite(ledPin, HIGH);//Liga LED
}
}
