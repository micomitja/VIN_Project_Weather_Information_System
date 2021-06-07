// C++ code
#include <LiquidCrystal.h>
#include <Wire.h>

String data = "";

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup(){
  
  Wire.begin();                
  lcd.begin(16, 2);
  Serial.begin(9600);
  lcd.setCursor(0,0);
  lcd.print("Waiting for data..."); //this will work better when 20x4 lcd in
  lcd.setCursor(0,1);
  lcd.print("Please wait..."); 

  delay(3000);
  
  
}


void loop()
{
  delay(100);
  
  // put your main code here, to run repeatedly:

  String dataString = "";
  float tmmp = 0.0F;

  Wire.requestFrom(8, 7);

  while (Wire.available()) {
    char c = Wire.read();
    dataString = dataString + c;
  }

  tmmp = dataString.toFloat();
  Serial.println(tmmp);
  
  
  float temperatureC = tmmp;    // receive byte as an integer
  Serial.println(temperatureC);         // print the integer
   
  // converting that reading to voltage, for 3.3v arduino use 3.3
  //float voltage = x * 5.0;
  //voltage /= 1024.0; 
 
  // print out the voltage
  //Serial.print(voltage); Serial.println(" volts");
 
  // now print out the temperature
  //float temperatureC = (voltage - 0.5) * 100 ;  //converting from 10 mv per degree wit 500 mV offset
                                               //to degrees ((voltage - 500mV) times 100)
  Serial.print(temperatureC); Serial.println(" degrees C");
 
 
  lcd.clear();
  lcd.setCursor(0, 0);
  
  
  
  if (temperatureC < 0 && temperatureC > -20) {
   
    //Print to LCD
    lcd.print("Cold Weather");
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(temperatureC);
    lcd.print(" C");
    
  } else if (temperatureC >= 0 && temperatureC < 15){
    
    //Print to LCD
    lcd.setCursor(0, 0);
    lcd.print("Chill Weather");
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(temperatureC);
    lcd.print(" C");
    noTone(10);
    
  } else if(temperatureC >= 15 && temperatureC < 25) {
    
    //Print to LCD
    lcd.setCursor(0, 0);
    lcd.print("Warm Weather");
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(temperatureC);
    lcd.print(" C");
  noTone(10); 
    
  }else if(temperatureC >= 25 && temperatureC < 36) {
    
    //Print to LCD
    lcd.setCursor(0, 0);
    lcd.print("Hot Weather");
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(temperatureC);
    lcd.print(" C");
    //noTone(10);
  }
  else if(temperatureC <= -20){
    
    //Print to LCD
    lcd.print("Dangerous Temp:");
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(temperatureC);
    lcd.print(" C");
      
    
  }
  else if(temperatureC > 35){
   
    //Print to LCD
    lcd.print("Dangerous Temp:");
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(temperatureC);
    lcd.print(" C");
      
  }
  
  delay (1000);
  
}
