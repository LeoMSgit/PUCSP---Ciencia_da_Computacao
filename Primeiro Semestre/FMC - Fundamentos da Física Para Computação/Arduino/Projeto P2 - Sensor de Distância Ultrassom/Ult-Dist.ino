int distanceThreshold = 5; // Distância mínima de ativação dos LEDs (em centímetros)
int cm = 0; // Distância em centímetros medida pelo sensor ultrassônico
int inches = 0; // Distância em polegadas

long readUltrasonicDistance(int triggerPin, int echoPin) {
  pinMode(triggerPin, OUTPUT); // Limpa o pino de trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Define o pino de trigger como HIGH por 10 microssegundos
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Lê o pino de echo e retorna o tempo de viagem da onda sonora em microssegundos
  return pulseIn(echoPin, HIGH);
}

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  int triggerPin = 10; // Pino de trigger
  int echoPin = 8; // Pino de echo
  
  distanceThreshold = 5; // Distância mínima de ativação dos LEDs (em centímetros)
  cm = 0.01723 * readUltrasonicDistance(triggerPin, echoPin); // Mede a distância em centímetros
  inches = (cm / 2.54); // Converte para polegadas
  Serial.print("Distância medida: ");
  Serial.print(cm);
  Serial.println(" cm");

  // Controla os LEDs com base na distância medida
  if (cm <= distanceThreshold) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    tone(8, 4000); // Emite um som de alta frequência (4000 Hz)
  } else {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    noTone(8); // Para o som
  }

  delay(100); // Aguarda 100 milissegundos antes de repetir
}
