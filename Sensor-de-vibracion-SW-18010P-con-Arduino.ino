/*
  Created by TEOS
  Domotic with Arduino https://goo.gl/btZpjs
  YouTube https://goo.gl/k7TUSZ
  Instagram https://goo.gl/zEIjia
  Facebook https://goo.gl/eivraR
  Twitter https://goo.gl/du5Wgn
  Github https://goo.gl/Xl5IiS
  Google Plus https://goo.gl/gBnUdh
  WEB https://goo.gl/jtiYJy
*/

const int sensorPinT = 2;
int timeStrokeT = 500;
int startT, durationT;
int strokeValT = HIGH;
boolean stateT = false;
unsigned long startStrokeT, finalStrokeT;

void setup () {
  Serial.begin(9600);
  pinMode(sensorPinT, INPUT) ;
}
void loop() {
  strokeValT = digitalRead(sensorPinT);
  if (strokeValT == LOW) {
    startStrokeT = millis();
    if (!stateT) {
      Serial.println("Vibracion detectada");
      startT = startStrokeT / 1000;
      stateT = true;
    }
  }
  else {
    if ((millis() - startStrokeT) > timeStrokeT && stateT) {
      finalStrokeT = millis();
      durationT = (finalStrokeT / 1000) - startT;
      Serial.print("La vibracion ha finalizado con ");
      Serial.print(durationT);
      Serial.println(" segundos de duracion\n");
      stateT = false;
    }
  }
}
