#include "DHT.h"

#include <Wire.h>

#include <LiquidCrystal_I2C.h>


#define DHTPIN 2 
#define DHTTYPE DHT11


LiquidCrystal_I2C lcd(0x27, 16, 2);
int a;
float ctemperature;
int B=3975;
float resistance;
const int A13 = 13;
const int A12 = 12;
const int A11 = 11;


DHT dht(DHTPIN, DHTTYPE); 
void setup()
{
  pinMode(A13, OUTPUT);
  pinMode(A12, OUTPUT); 
  pinMode(A11, OUTPUT);
  dht.begin();
  Serial.begin(9600);
  lcd.init();//On initialise l'écran
  lcd.backlight();//Allumage du rétroéclairage
}

void loop()
{
  
  lcd.setCursor(0,0);
  lcd.clear();//On efface l'écran
  //LED ROUGE//
  //digitalWrite(A13, HIGH);
  Serial.println();
  //LUMINATITE//
  int lux = analogRead(A0);
  Serial.print("Luminosité: ");
  Serial.print(lux);
  Serial.print(" Lux");
  Serial.print(" \t");
  if(lux <=500) {
    digitalWrite(A12, HIGH);
    lcd.print("Lumiere eteinte");} 
    else digitalWrite(A12, LOW);

  //TEMPERATURE//
  a=analogRead(1);
  resistance=(float)(1023-a)*10000/a; 
  ctemperature=1/(log(resistance/10000)/B+1/298.15)-273.15;
  Serial.print("Température: ");
  Serial.print(ctemperature);
  Serial.print(" °C");
  Serial.print(" (premier capteur)");
  if (ctemperature >= 30) {
    digitalWrite(A13, HIGH);
    lcd.setCursor(0,0);
    lcd.print("Temperature");
    lcd.setCursor(0,1);
    lcd.print("haut #salle1");
    } 
    else digitalWrite(A13, LOW);
  Serial.println();
  Serial.println();
  
  


  // Lecture du taux d'humidité
  float h = dht.readHumidity();
  // Lecture de la température en Celcius
  float t = dht.readTemperature();
  // Pour lire la température en Fahrenheit
  float f = dht.readTemperature(true);
  
  // Stop le programme et renvoie un message d'erreur si le capteur ne renvoie aucune mesure
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Echec de lecture !");
    return;
  }

  // Calcul la température ressentie. Il calcul est effectué à partir de la température en Fahrenheit
  // On fait la conversion en Celcius dans la foulée
  float hi = dht.computeHeatIndex(f, h);
  

  Serial.print("Humidite: "); 
  Serial.print(h);
  Serial.print("%\t");
  if (h >= 50) {
    digitalWrite(A11, HIGH);
    lcd.setCursor(0,0); 
    lcd.print("Humidite Trop");
    lcd.setCursor(0,1);
    lcd.print("haut #salle2");} 
    else digitalWrite(A11, LOW);
  Serial.print("Temperature: "); 
  Serial.print(t);
  Serial.print(" °C ");
  Serial.print("Temperature ressentie: ");
  if (t  >= 30) {
    digitalWrite(A13, HIGH);
    lcd.setCursor(0,0);
    lcd.print("Temperature");
    lcd.setCursor(0,1);
    lcd.print("haut #salle2");
    } 
    else digitalWrite(A13, LOW);
  Serial.print(dht.convertFtoC(hi));
  Serial.println(" °C");

  delay(1000);
}
