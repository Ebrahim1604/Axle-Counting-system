/*
 Pin-out of 16x2 LCD and connection with arduino Nano (Left to right)
 
LCDpinno       Description             Arduino Nano
--------------------------------------------------------------------
   1               VSS                  GND
   2               VDD                  5v(Short with pin 15 of LCD)
   3               VO                   No connection with arduino, but with output(middle pin) of 10k potentiometer
   4               RS                   digital pin 2
   5               R/W                  GND 
   6               EN                   digital pin 3
 7,8,9,10      1st 4-bit data lines     No connection as we use the LCD in 4-bit data mode only
   11           data_pin 4              digital  pin 4
   12           data_pin 5              digital  pin 5
   13           data_pin 6              digital  pin 6
   14           data_pin 7              digital  pin 7
   15             VCC                   Connect to a 220 ohm resistor and the other end of the resistor to Arduino 5v pin
   16             GND                   GND
   
   Note: Connect the GND pin of the pot to GND of arduino and VCC pin of pot to 5v pin of arduino
 */

#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

int Cin_val = 2;
int Cout_val = 2;
char op[] = {'O', 'P'};
char uo[] = {'U', 'O'};
char l2r[] = {'-', '>'};
char r2l[] = {'<', '-'};

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Cin:");
  lcd.print(Cin_val);
  lcd.setCursor(9,0);
  lcd.print("Cout:");
  lcd.print(Cout_val);
  lcd.setCursor(0,1);
  lcd.print("Status:");
  for (int i = 0; i<2; i++)
  {
  lcd.print(uo[i]);
  }
  lcd.setCursor(10,1);
  lcd.print("DIR:");
  for (int i = 0; i<2; i++)
  {
  lcd.print(r2l[i]);
  }
  
  
}

void loop() {
  }
 
