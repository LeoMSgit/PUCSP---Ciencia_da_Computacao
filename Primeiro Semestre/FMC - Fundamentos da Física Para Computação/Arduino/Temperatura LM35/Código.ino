void setup() {
Serial.begin(9600);
}
void loop() {
 int sensorValue = analogRead(A2);
 float voltage = sensorValue * (5.0 / 1023.0);
 Serial.print("Tensao = ");
 Serial.print(voltage);
 Serial.print(" V");
 Serial.println();
 delay(2000);
 float temp=(voltage)*100;
 Serial.print("Temperatura Celsius = ");
 Serial.print(temp);
 Serial.print("@C");
 Serial.println();
 float TF = (temp)*1.8 + 32;
 Serial.print("Temperatura Fahrenheit = ");
 Serial.print(TF);
 Serial.print("@F");
 Serial.println();
 delay(2000);
}
