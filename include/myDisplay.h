#include <Arduino.h>
#include <LiquidCrystal.h>
// defines the pins on this project for the LCD display
const int Display_RS = 22, Display_EN = 23, Display_D4 = 5, Display_D5 = 18, Display_D6 = 19, Display_D7 = 21;

void InitDisplay();

void DisplayLine(int line, String message);