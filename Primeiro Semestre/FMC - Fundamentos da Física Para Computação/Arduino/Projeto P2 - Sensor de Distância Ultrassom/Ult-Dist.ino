#include <Adafruit_LiquidCrystal.h>

#define trigPin 2
#define echoPin 3

long duration;
int distance;
Adafruit_LiquidCrystal lcd_1(0);
int cm;
int inches;

int maxDistanceThreshold = 100; // Distância máxima de ativação dos LEDs (em centímetros)

long readUltrasonicDistance(int signalPin) {
    pinMode(signalPin, OUTPUT);
    digitalWrite(signalPin, LOW);
    delayMicroseconds(2);
    digitalWrite(signalPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(signalPin, LOW);
    pinMode(signalPin, INPUT);
    return pulseIn(signalPin, HIGH);
}

void setup() {
    Serial.begin(9600);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT); // Pino do piezo

    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

    lcd_1.begin(16, 2); // Inicializa o LCD com 16 colunas e 2 linhas
    lcd_1.print("Distancia: "); // Imprime o texto inicial no LCD
}

void loop() {
    int signalPin = 9; // Pino do sinal para o sensor ultrassônico

    cm = 0.01723 * readUltrasonicDistance(signalPin); // Mede a distância em centímetros
    inches = (cm / 2.54);                            // Converte para polegadas
    Serial.print("Distancia medida: ");
    Serial.print(cm);
    Serial.println(" cm");

    // Exibe a distância medida no LCD
    lcd_1.setCursor(0, 1); // Define a posição do cursor no LCD
    lcd_1.print(cm);       // Imprime a distância medida no LCD
    lcd_1.print("cm       "); // Preenche o restante da linha no LCD

    // Controla os LEDs com base na distância medida
    if (cm >= maxDistanceThreshold) {
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        noTone(8); // Para o som
    } else {
        // Ativa os LEDs conforme a distância diminui
        if (cm <= maxDistanceThreshold && cm > maxDistanceThreshold - 20) {
            digitalWrite(2, HIGH);
            digitalWrite(3, LOW);
            digitalWrite(4, LOW);
            digitalWrite(5, LOW);
            digitalWrite(6, LOW);
            digitalWrite(7, LOW);
        } else if (cm <= maxDistanceThreshold - 20 && cm > maxDistanceThreshold - 40) {
            digitalWrite(2, HIGH);
            digitalWrite(3, HIGH);
            digitalWrite(4, LOW);
            digitalWrite(5, LOW);
            digitalWrite(6, LOW);
            digitalWrite(7, LOW);
        } else if (cm <= maxDistanceThreshold - 40 && cm > maxDistanceThreshold - 60) {
            digitalWrite(2, HIGH);
            digitalWrite(3, HIGH);
            digitalWrite(4, HIGH);
            digitalWrite(5, LOW);
            digitalWrite(6, LOW);
            digitalWrite(7, LOW);
        } else if (cm <= maxDistanceThreshold - 60 && cm > maxDistanceThreshold - 80) {
            digitalWrite(2, HIGH);
            digitalWrite(3, HIGH);
            digitalWrite(4, HIGH);
            digitalWrite(5, HIGH);
            digitalWrite(6, LOW);
            digitalWrite(7, LOW);
        } else if (cm <= maxDistanceThreshold - 80 && cm > maxDistanceThreshold - 95) {
            digitalWrite(2, HIGH);
            digitalWrite(3, HIGH);
            digitalWrite(4, HIGH);
            digitalWrite(5, HIGH);
            digitalWrite(6, HIGH);
            digitalWrite(7, LOW);
        } else {
            digitalWrite(2, HIGH);
            digitalWrite(3, HIGH);
            digitalWrite(4, HIGH);
            digitalWrite(5, HIGH);
            digitalWrite(6, HIGH);
            digitalWrite(7, HIGH);
        }

        // Calcula o intervalo do buzzer baseado na distância medida
        int beepInterval = map(cm, 0, maxDistanceThreshold, 100, 1000); // Intervalo de 100ms a 1000ms
        tone(8, 2000); // Emite um som de frequência constante
        delay(100);    // Duração do beep
        noTone(8);     // Para o som
        delay(beepInterval - 100); // Aguarda o tempo restante do intervalo
    }

    delay(200); // Aguarda 2 segundos antes de repetir
}
