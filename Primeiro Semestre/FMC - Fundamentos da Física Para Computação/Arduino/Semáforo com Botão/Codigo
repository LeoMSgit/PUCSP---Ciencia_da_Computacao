int Botao= 8;
int LEDvr= 2;
int LEDam= 3;
int LEDvd=4;
int LEDver=5;
int LEDved=6;

unsigned long previousMillis = 0;
const long interval = 3000;

void setup(){
  Serial.begin(9600);
  pinMode(LEDvr, OUTPUT);
  pinMode(LEDam, OUTPUT);
  pinMode(LEDvd, OUTPUT);
  pinMode(LEDver, OUTPUT);
  pinMode(LEDved, OUTPUT);
  pinMode(Botao, INPUT_PULLUP);
}

void loop(){
  unsigned long currentMillis = millis();
  
  if(digitalRead(Botao) == LOW) {
    if(currentMillis - previousMillis >= interval){
    	previousMillis = currentMillis;
      //Fase I, vermelho ligado
      digitalWrite(LEDvr, HIGH);
	  digitalWrite(LEDam, LOW);
	  digitalWrite(LEDvd, LOW);
      digitalWrite(LEDver, LOW);
      digitalWrite(LEDved, HIGH);
      delay(10000);
    }
  }else{
    digitalWrite(LEDvr, HIGH);
	digitalWrite(LEDam, LOW);
	digitalWrite(LEDvd, LOW);
    digitalWrite(LEDver, LOW);
    digitalWrite(LEDved, HIGH);
    delay(3000);
    
    if (digitalRead(Botao) == LOW){
      return;
    }
    
    //Fase II, verde ligado
    digitalWrite(LEDvr, LOW);
	digitalWrite(LEDam, LOW);
	digitalWrite(LEDvd, HIGH);
    digitalWrite(LEDver, HIGH);
    digitalWrite(LEDved, LOW);
    delay(5000);
    
    if(digitalRead(Botao) == LOW){
      return;
    }
       
    //Fase II, amarelo ligado
    digitalWrite(LEDvr, LOW);
	digitalWrite(LEDam, HIGH);
	digitalWrite(LEDvd, LOW);
    digitalWrite(LEDver, HIGH);
    digitalWrite(LEDved, LOW);
    delay(3000);
  }
}
