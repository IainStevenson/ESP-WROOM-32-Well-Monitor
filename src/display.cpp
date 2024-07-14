#include <Arduino.h>
#include <myDisplay.h>
LiquidCrystal lcd(Display_RS, Display_EN, Display_D4, Display_D5, Display_D6, Display_D7);
const char PROGMEM *CLEARLINE = "                 ";
void initDisplay()
{
    lcd.begin(16, 2);
    lcd.clear();
}

void displayLine(int line, String message)
{
    lcd.setCursor(0, line);
    lcd.print(CLEARLINE);
    lcd.setCursor(0, line);
    lcd.print(message);
}