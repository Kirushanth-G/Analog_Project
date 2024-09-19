// include the library code:
#include <LiquidCrystal.h>
#include <Wire.h>
#include <Adafruit_ADS1015.h>

Adafruit_ADS1115 ads(0x48);
float Voltage = 0.0;
float Weight;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(19, 23, 18, 17, 16, 15);

void setup(void) 
{
Serial.begin(9600); 
ads.begin();
// set up the LCD's number of columns and rows:
lcd.begin(16, 2);
lcd.clear();
lcd.setCursor(1, 0);
// Print Error message on the LCD.
lcd.print("Welcome to");

lcd.setCursor(3, 1);
// print the ADC value:
lcd.print("Thiruchitrampalam electronics");
}

void loop(void) 
{
int16_t adc0;
adc0 = 1*ads.readADC_SingleEnded(0);
Voltage = (adc0 * 0.1875)/1000;

if(Voltage <= 5.0){
  Weight = (map((adc0 * 1.875), 2100, 10100, 0, 10000))/1000.0;

  lcd.clear();
  lcd.setCursor(0, 0);
  // Print Caption on the LCD.
  lcd.print("Weight is: ");
  // set the cursor to column 0, line 1
  lcd.setCursor(0, 1);
  // print the ADC value:
  lcd.print(Weight, 3);

  // set the cursor to column 6, line 1
  lcd.setCursor(6, 1);
  // print Kg at the end:
  lcd.print("Kg");
  Serial.print("adc value: ");
  Serial.print(adc0);
  Serial.print("  Voltage value: ");
  Serial.println(Voltage);


}

else{
  lcd.clear();
  lcd.setCursor(1, 0);
  // Print Error message on the LCD.
  lcd.print("Weight is more");
  
  lcd.setCursor(3, 1);
  // print the ADC value:
  lcd.print("than 10 Kg");
}


// Serial.print("AIN0: "); 
// Serial.print(adc0);
// Serial.print("\tVoltage: ");
// Serial.print(Voltage, 7);
// Serial.print("\tWeight: ");
// Serial.println(Weight, 3); 
// Serial.println();

delay(500);
}
