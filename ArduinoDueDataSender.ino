// C++ code
#include <Wire.h>
#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);


float tmmp = 0.0F;
char tmpBuff[7];

bool onSound = false;

int wLED = 9;
int lightLevel = 0;
int LDR = A0;
//int TMP = A1;
int rLED = 6;
int bLED = 7;
int gLED = 8;
int sensorPin = A1;
const int pinButton = 13;
int soLED = 12 ;
float temp;

void setup() {
  delay(500);
  Wire.begin(8); // any 7-bit Slave address
  Wire.onRequest(requestEvent); //Interrupt for handling incomming requests
  
  Serial.begin(9600);
  Serial.println(F("DHT11 test!"));
  dht.begin();
  pinMode(wLED, OUTPUT);
  pinMode(rLED, OUTPUT);
  pinMode(bLED, OUTPUT);
  pinMode(gLED, OUTPUT);
  pinMode(pinButton, INPUT);
  pinMode(soLED, OUTPUT);
}

void loop() {

  float temperatureC = dht.readTemperature();     // read temperature
  temp = temperatureC;
// start working...
  Serial.println("=================================");
  Serial.println("Sample DHT11 & PhotoResistor...");
  
  Serial.print(temperatureC);
  Serial.println(F("°C Temperature"));
  
  lightLevel = analogRead(LDR);  
  Serial.print(lightLevel);  Serial.println(" Light level");
  
  if (lightLevel < 10) {
    digitalWrite(wLED, HIGH);
  } else {
    digitalWrite(wLED, LOW);
  }
  
    
  int stateButton = digitalRead(pinButton);
  if(stateButton == HIGH) {
     Serial.println("PRESSED");
    if(onSound == true){
      onSound=false;
    }
    else{
      onSound=true;
    }
  }
       
  
  if(onSound == true){
    digitalWrite(soLED, HIGH);
  }else{
    digitalWrite(soLED, LOW);
  }
  
   
  if ((int)temperatureC < 0 && (int)temperatureC > -20) {
    digitalWrite(rLED, LOW);
    digitalWrite(gLED, LOW);
    digitalWrite(bLED, HIGH);
    
    
  } else if ((int)temperatureC >= 0 && (int)temperatureC < 15){
    digitalWrite(bLED, LOW);
    digitalWrite(rLED, LOW);
    digitalWrite(gLED, HIGH);
    noTone(10);
    
  } else if((int)temperatureC >= 15 && (int)temperatureC < 25) {
    digitalWrite(rLED, LOW);
    digitalWrite(bLED, LOW);
    digitalWrite(gLED, HIGH);
    noTone(10); 
    
  }else if((int)temperatureC >= 25 && (int)temperatureC < 36) {
    digitalWrite(rLED, LOW);
    digitalWrite(bLED, LOW);
    digitalWrite(gLED, HIGH);
    noTone(10);
  
  }
  else if((int)temperatureC <= -20){
    digitalWrite(rLED, LOW);
    digitalWrite(gLED, LOW);
    digitalWrite(bLED, HIGH);
   
    if(onSound != true){
       tone(10,500);
    }
    else{
      noTone(10);
    }
        
  }
  
  else if((int)temperatureC > 35){
    digitalWrite(rLED, HIGH);
    digitalWrite(bLED, LOW);
    digitalWrite(gLED, LOW);
   
   
    if(onSound != true){
        tone(10,600);
   }
   else{
      noTone(10);
    }
      
  }
  
  
  delay(500);
  
}

void requestEvent() {
  
  dtostrf(temp,7,2, tmpBuff);
  Wire.write(tmpBuff);


}
