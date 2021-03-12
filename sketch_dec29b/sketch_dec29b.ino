#include <IRremote.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

void afficher(int chiffre);


const int RECV_PIN = 9;
IRrecv irrecv(RECV_PIN);
decode_results results;
LiquidCrystal_I2C lcd(0x27, 16, 2);


const int A = 2;
const int B = 3;
const int C = 4;
const int D = 5;
const int E = 6;
const int F = 7;
const int G = 8;

void setup() {
  Serial.begin(9200);
  irrecv.enableIRIn();
  irrecv.blink13(true);

  lcd.init();//On initialise l'écran
  lcd.backlight();//Allumage du rétroéclairage

  // définition des broches en sortie
    pinMode(A, OUTPUT);
    pinMode(B, OUTPUT);
    pinMode(C, OUTPUT);
    pinMode(D, OUTPUT);
    pinMode(E, OUTPUT);
    pinMode(F, OUTPUT);
    pinMode(G, OUTPUT);

}

void loop() {
  
  lcd.setCursor(0,0);
  if (irrecv.decode(&results)){
        Serial.println(results.value, HEX);
        afficher(results.value);
        irrecv.resume();}

  
}

void afficher(int chiffre)
{
    switch(chiffre)
    {

    case 0xFFFFFFFF :
        lcd.print("Erreur 0xFFFFFF");
        lcd.setCursor(0,1);
        lcd.print("Bouton enfoncer !");
        delay(5000);
        lcd.clear();
        
    case 0xFF4AB5 :
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(F, HIGH);
        digitalWrite(G, LOW);
        Serial.println("0");
        
        lcd.print("Bouton 0");
        lcd.setCursor(0,1);
        lcd.print("Code : ");
        lcd.print("FF4AB5");
        delay(5000);
        lcd.clear();
        break;
    case 0xFF6897 :
        digitalWrite(A, LOW);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, LOW);
        digitalWrite(E, LOW);
        digitalWrite(F, LOW);
        digitalWrite(G, LOW);
        Serial.println("1");
        lcd.print("Bouton 1");
        lcd.setCursor(0,1);
        lcd.print("Code : ");
        lcd.print("FF6897");
        delay(5000);
        lcd.clear();
        break;
    case 0xFF9867 :
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, LOW);
        digitalWrite(D, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(F, LOW);
        digitalWrite(G, HIGH);
        Serial.println("2");
        lcd.print("Bouton 2");
        lcd.setCursor(0,1);
        lcd.print("Code : ");
        lcd.print("FF9867");
        break;
    case 0xFFB04F :
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, LOW);
        digitalWrite(F, LOW);
        digitalWrite(G, HIGH);
        Serial.println("3");
        lcd.print("Bouton 3");
        lcd.setCursor(0,1);
        lcd.print("Code : ");
        lcd.print("FFB04F");
        break;
    case 0xFF30CF :
        digitalWrite(A, LOW);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, LOW);
        digitalWrite(E, LOW);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
        Serial.println("4");
        lcd.print("Bouton 4");
        lcd.setCursor(0,1);
        lcd.print("Code : ");
        lcd.print("FF30CF");
        break;
    case 0xFF18E7 :
        digitalWrite(A, HIGH);
        digitalWrite(B, LOW);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, LOW);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
        Serial.println("5");
        lcd.print("Bouton 5");
        lcd.setCursor(0,1);
        lcd.print("Code : ");
        lcd.print("FF18E7");
        break;
    case 0xFF7A85 :
        digitalWrite(A, HIGH);
        digitalWrite(B, LOW);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
        Serial.println("6");
        lcd.print("Bouton 6");
        lcd.setCursor(0,1);
        lcd.print("Code : ");
        lcd.print("FF7A85");
        break;
    case 0xFF10EF :
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, LOW);
        digitalWrite(E, LOW);
        digitalWrite(F, LOW);
        digitalWrite(G, LOW);
        Serial.println("7");
        lcd.print("Bouton 7");
        lcd.setCursor(0,1);
        lcd.print("Code : ");
        lcd.print("FF10EF");
        break;
    case 0xFF38C7 :
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
        Serial.println("8");
        lcd.print("Bouton 8");
        lcd.setCursor(0,1);
        lcd.print("Code : ");
        lcd.print("FF38C7");
        break;
    case 0xFF5AA5 :
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, LOW);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
        Serial.println("9");
        lcd.print("Bouton 9");
        lcd.setCursor(0,1);
        lcd.print("Code : ");
        lcd.print("FF5AA5");
        break;
    }
}
