#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal.h>		// importa libreria

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);	// pines RS, E, D4, D5, D6, D7 de modulo 1602A

float temp;
int tempPin = 0;

int ThermistorPin = 0;
int Vo;
float R1 = 10000;
float logR2, R2, T;
float c1 = 0.7904710802e-3, c2 = 2.251846924e-4, c3 = 0.87060700625e-7;

void setup() {
  lcd.begin(16, 2);			// inicializa a display de 16 columnas y 2 lineas
}

void loop() {
  lcd.setCursor(0, 0);			// ubica cursor en columna 0 y fila 0		
  
  Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2)) - 233.15;
  T = T - 273.15;
  T = (T * 9.0)/ 5.0 + 32.0; 

  lcd.print("hola paola, tu "); 
  lcd.setCursor(0, 2);
  lcd.print("eres gay <3");

  delay(500);
}
