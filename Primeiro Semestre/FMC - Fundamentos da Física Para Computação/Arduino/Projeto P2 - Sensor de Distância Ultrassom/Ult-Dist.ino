//Os Leds só devem acender quando o obejto entrar em seu range, eles continuam acessos quando o objeto se aproxima mais. Eles sempre devem piscar. A distancia começa a piscas o LED 2 a 2 metros, o LED 3 a 1,5 metros, o LED 4 a 1 metro, o LED 5 a 30cm, o LED 6 a 15 cm e o LED 7 a 5 ou menos centímetros
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define TRIG_PIN 10
#define ECHO_PIN 9

long duration;
int distance;
LiquidCrystal_I2C lcd_1(0x27, 16, 2); // Endereço I2C do LCD: 0x27, 16 colunas e 2 linhas
int cm;
int inches;

long readUltrasonicDistance(int trigPin, int echoPin) {
    pinMode(trigPin, OUTPUT);
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    pinMode(echoPin, INPUT);
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
    pinMode(8, OUTPUT); // Pino do piezo

    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    lcd_1.init(); // Inicializa o LCD
    lcd_1.backlight(); // Liga a luz de fundo do LCD
    lcd_1.begin(16, 2); // Inicializa o LCD com 16 colunas e 2 linhas
    lcd_1.print("Distancia: "); // Imprime o texto inicial no LCD
}

void loop() {
    cm = 0.01723 * readUltrasonicDistance(TRIG_PIN, ECHO_PIN); // Mede a distância em centímetros
    inches = (cm / 2.54); // Converte para polegadas
    Serial.print("Distancia medida: ");
    Serial.print(cm);
    Serial.println(" cm");

    // Exibe a distância medida no LCD
    lcd_1.setCursor(0, 1); // Define a posição do cursor no LCD
    lcd_1.print(cm); // Imprime a distância medida no LCD
    lcd_1.print("cm       "); // Preenche o restante da linha no LCD

    // Controla os LEDs e o piezo com base na distância medida
    if (cm <= 200) { // A partir de 2 metros
        digitalWrite(2, HIGH); // Liga o LED 2
        tone(8, 1000, 100); // Emite um som (bip) mais lento
    }
    if (cm <= 150) { // A partir de 1,5 metros
        digitalWrite(3, HIGH); // Liga o LED 3
        tone(8, 1000, 75); // Emite um som (bip) mais rápido
    }
    if (cm <= 100) { // A partir de 1 metro
        digitalWrite(4, HIGH); // Liga o LED 4
        tone(8, 1000, 50); // Emite um som (bip) ainda mais rápido
    }
    if (cm <= 30) { // A partir de 30 cm
        digitalWrite(5, HIGH); // Liga o LED 5
        tone(8, 1000, 40); // Emite um som (bip) mais rápido ainda
    }
    if (cm <= 15) { // A partir de 15 cm
        digitalWrite(6, HIGH); // Liga o LED 6
        tone(8, 1000, 30); // Emite um som (bip) mais rápido
    }
    if (cm <= 5) { // 5 cm ou menos
        digitalWrite(7, HIGH); // Liga o LED 7
        tone(8, 1000, 20); // Emite um som (bip) muito rápido
    }

    // Aguarda um curto período para o LED permanecer aceso
    delay(100);

    // Desliga todos os LEDs
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    noTone(8); // Para o som

    // Aguarda um curto período antes de repetir
    delay(100);
}
