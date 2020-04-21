#include <SoftwareSerial.h>

int inputPin = 4;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status
int gatePin = 1;
int potPin = 3;
int sleepDelay = 50;

void setup() {
  
  pinMode(inputPin, INPUT);     // declare sensor as input
  pinMode(gatePin, OUTPUT);
  pinMode(potPin, INPUT);
  digitalWrite(gatePin, LOW);
}
 
void loop(){
  val = digitalRead(inputPin);  // read input value
  
  
  if (val == HIGH && pirState == LOW)  // check if the input is HIGH
  {            
      for(int i=0; i<255; i++){
        analogWrite(gatePin, i);
        delay(5);
      }
  
      digitalWrite(gatePin, HIGH);
      pirState = HIGH;
      sleepDelay = analogRead(potPin);
      delay(sleepDelay*30);
  }

  else if (val == LOW && pirState == HIGH)
  // TURN OFF
  {
      for (int i=254; i>0; i--) {
        analogWrite(gatePin, i);
        delay(5);
      }
      digitalWrite(gatePin, LOW);
      pirState = LOW;
    }

  //delay(1000);
}
