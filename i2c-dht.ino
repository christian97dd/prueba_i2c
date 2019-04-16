#include "DHT.h"
#define DHTPIN 12     
#define DHTTYPE DHT11  

DHT dht(DHTPIN, DHTTYPE);

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 


void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  dht.begin();
}

void loop() {
  int h = dht.readHumidity();
  int t = dht.readTemperature();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print("C");
  
  
  lcd.setCursor(0,1);
  lcd.print("humedad: ");
  lcd.print(h);
  lcd.print("%");
    
  Serial.print("Temp: ");
  Serial.print(t);
  Serial.print("C, humedad: ");
  Serial.print(h);
  Serial.println("%");
  delay (2500);
}
