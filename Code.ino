#include <LiquidCrystal.h>

// LCD pin configuration
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Turbidity sensor pin
int turbidityPin = A0;

void setup() 
{
  lcd.begin(16, 2);
  lcd.print("Turbidity");
  lcd.setCursor(0, 1);
  lcd.print("Monitoring");
  
  delay(2000);
  lcd.clear();

  Serial.begin(9600);
}

void loop() 
{
  int sensorValue = analogRead(turbidityPin);

  // Convert sensor value to voltage
  float voltage = sensorValue * (5.0 / 1024.0);

  // Approximate turbidity calculation
  float turbidity = map(sensorValue, 0, 750, 1000, 0);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Turbidity:");

  lcd.setCursor(0, 1);
  lcd.print(turbidity);
  lcd.print(" NTU");

  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);

  Serial.print("  Turbidity: ");
  Serial.print(turbidity);
  Serial.println(" NTU");

  delay(1000);
}
