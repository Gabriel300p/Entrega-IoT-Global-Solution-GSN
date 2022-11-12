#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);


#define Trigpin 13
#define Echopin 10
#define Trigpin_2 7
#define Echopin_2 6

#define Red 9
#define Green 8

#define Red_2 3
#define Green_2 4

float distance;
int duration;
float distance_2;
int duration_2;
  
void setup() {
  pinMode (Trigpin, OUTPUT);
  pinMode (Trigpin_2, OUTPUT);
  pinMode (Echopin, INPUT);
  pinMode (Echopin_2, INPUT);
  
  pinMode (Red, OUTPUT);
  pinMode (Green, OUTPUT);
  
  pinMode (Red_2, OUTPUT);
  pinMode (Green_2, OUTPUT);

  Serial.begin(9600);
  digitalWrite (Red, LOW);
  digitalWrite (Green, LOW);
  
  digitalWrite (Red_2, LOW);
  digitalWrite (Green_2, LOW);
  lcd.init();
  lcd.backlight();
}

void loop() {
  digitalWrite(Trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trigpin_2, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigpin_2, LOW);
  duration_2 = pulseIn(Echopin_2, HIGH);
  distance_2 = duration_2 * 0.034 / 2;
  
  digitalWrite(Trigpin_2, LOW);
  delayMicroseconds(2);
  digitalWrite(Trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigpin, LOW);
  duration = pulseIn(Echopin, HIGH);
  distance = duration * 0.034 / 2;
  
  delay (1000);
  Serial.println (" ");
  Serial.print ("Distance = ");
  Serial.print (distance);
  Serial.print (" CM");
  Serial.println (" ");
  
    if (distance_2<=120 and distance<=120)
  {
    Serial.println ("Vagas ocupadas");
    digitalWrite (Red, HIGH);
    digitalWrite (Green, LOW);
     
    digitalWrite (Red_2, HIGH);
    digitalWrite (Green_2, LOW);
      
    lcd.clear();
    lcd.print("vagas livres 0");
    lcd.setCursor(0,1);
    lcd.print("vagas ocupadas 2");
  }
  
   if (distance_2>=120 and distance>=120)
  {
    Serial.println ("Vagas Livres");
    digitalWrite (Red, LOW);
    digitalWrite (Green, HIGH);
    digitalWrite (Red_2, LOW);
    digitalWrite (Green_2, HIGH); 
     
    lcd.clear();
    lcd.print("vagas livres 2");
    lcd.setCursor(0,1);
    lcd.print("vagas ocupadas 0");
  }
     
  	if (distance_2>=120 and distance<=120)
  {
    Serial.println ("Vaga Parcial");
    digitalWrite (Red, LOW);
    digitalWrite (Green, HIGH);
      
    digitalWrite (Red_2, HIGH);
    digitalWrite (Green_2, LOW);
    lcd.clear();
    lcd.print("vagas livres 1");
    lcd.setCursor(0,1);
    lcd.print("vagas ocupadas 1");
  }
  
  	if (distance_2<=120 and distance>=120)
  {
    Serial.println ("Vaga Parcial");
    digitalWrite (Red, HIGH);
    digitalWrite (Green, LOW);
      
    digitalWrite (Red_2, LOW);
    digitalWrite (Green_2, HIGH);
      
    lcd.clear();
    lcd.print("vagas livres 1");
    lcd.setCursor(0,1);
    lcd.print("vagas ocupadas 1");
  }
  
  
  
}
