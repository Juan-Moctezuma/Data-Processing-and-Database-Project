//www.elegoo.com
//2016.12.9

#include <LiquidCrystal.h> //This Library is required to connect the Liquid Crystal Display (LCD) screen

int tempPin = 0; //Signal (or data) received from the sensor will initially be zero
//                BS  E  D4 D5  D6 D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); //This sets up where the numbers in the screen will show up
void setup()
{
  lcd.begin(16, 2);
  Serial.begin(9600); //Data rate in which bits per second will be transmitted into the Python Code
}
void loop()
{
  int tempReading = analogRead(tempPin);
  double tempK = log(10000.0 * ((1024.0 / tempReading - 1))); //Temperature will be calculated in Kelvin initially
  tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * tempK * tempK )) * tempK ); 
  float tempC = tempK - 273.15;            // Convert Kelvin to Celsius
  float tempF = (tempC * 9.0)/ 5.0 + 32.0; // Convert Celsius to Fahrenheit

  //The following code block displays and accomodates temperature data into the LCD
  // Display Temperature in C
  lcd.setCursor(0, 0);
  lcd.print("Temp         C  ");
  lcd.setCursor(6, 0);
  lcd.print(tempC);
  // Display Temperature in F
  lcd.setCursor(0, 1);
  lcd.print("             F  "); 
  lcd.setCursor(6, 1); 
  lcd.print(tempF);

  //The following code block will print the recorded data every second in the Arduino platform/IDE, but
  //the same data will be transmitted and printed into the Python script
  Serial.print(tempC);
  Serial.print(",");
  Serial.print(tempF);
  Serial.println(" ");
  delay(1000); //1000ms = 1 second
}

