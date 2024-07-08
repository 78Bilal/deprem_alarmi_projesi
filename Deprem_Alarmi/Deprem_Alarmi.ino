#include <LiquidCrystal_I2C.h> // LCD Ekran Kütüphanesi
#include <MPU6050.h> // Deprem ve Sarsıntı Sensörünün Kütüphanesi
#include <Wire.h>
MPU6050 MPU;
int GyroX , GyroY , GyroZ;
int buzzer = 2;
LiquidCrystal_I2C lcd(0x27, 16, 2);
int button = 3;
void setup() {
  lcd.begin();
  Serial.begin(9600);
  Wire.begin();
  MPU.initialize();
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(button,INPUT);
}
void loop() {
  MPU.getRotation(&GyroX, &GyroY, &GyroZ);
  if(GyroX< -500 ||GyroX> 500 || GyroY>500 || GyroY< -500 || GyroZ >500 || GyroZ < -500 ) {
  lcd.clear();
  lcd.backlight();
  for(int i=0;i<17;i++)
  lcd.setCursor(0, 0);        
  lcd.print("   DİKKAT !!!   ");
  lcd.setCursor(0, 1);    
  lcd.print(" DEPREM OLUYOR  ");
  digitalWrite(4,0);
  digitalWrite(6,1);
  digitalWrite(5,1);
  digitalWrite(7,0);
  tone(buzzer,1000);
  delay(2000);
  lcd.clear();
    lcd.backlight();
    lcd.setCursor(0, 0);        
    lcd.print(" Elektrik : OFF ");
    lcd.setCursor(0, 1);    
    lcd.print(" Doğalgaz : OFF ");
  } else {
  digitalWrite(5,0);
  noTone(buzzer);
  delay(1000);
  if (digitalRead(button)==1){
    digitalWrite(4,1); 
    digitalWrite(6, 0);
    digitalWrite(7, 1);
    lcd.clear();
    lcd.backlight();
    lcd.setCursor(0, 0);        
    lcd.print(" DEPREM ALARMI  ");
    lcd.setCursor(0, 1);    
    lcd.print("    PROJESİ     ");
  }
  
 
  
}}

