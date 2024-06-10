int distanceThreshold = 100; // Distância de ativação dos LEDs (em centímetros)
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
  distanceThreshold = 100; // Distância de ativação dos LEDs (em centímetros)
  cm = 0.01723 * readUltrasonicDistance(7, 7); // Mede a distância em centímetros
  inches = (cm / 2.54); // Converte para polegadas
  Serial.print(cm);
  Serial.print("cm,");
  Serial.print(inches);
  Serial.println("in");
  
  // Controla os LEDs com base na distância medida
  if (cm > distanceThreshold) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }
  else if (cm <= distanceThreshold && cm > distanceThreshold - 20) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }
  else if (cm <= distanceThreshold - 20 && cm > distanceThreshold - 40) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }
  else if (cm <= distanceThreshold - 40 && cm > distanceThreshold - 60) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }
  else if (cm <= distanceThreshold - 60 && cm > distanceThreshold - 80) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }
  else if (cm <= distanceThreshold - 80 && cm > distanceThreshold - 100) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
  }
  else {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
  }

  delay(100); // Aguarda 100 milissegundos antes de repetir
}
