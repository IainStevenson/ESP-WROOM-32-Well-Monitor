/*
  LiquidCrystal Library - Serial Input

  as per https://www.instructables.com/ESP32-How-to-Interface-LCD-With-ESP32-Microcontrol/



  ESP32 GND ->  LCD 1 VSS
  ESP32 +5V ->  LCD 2 VDD (+5V)
  ESP32 +5V ->  LCD 3 VE (Via p10K Pot pin 2, Pot Pin 1 +5v Pin 3 GND)
  ESP32 D22 ->  LCD 4 RS
  ESP32 GND ->  LCD 5 RW
  ESP32 D23 ->  LCD 6 EN
  Nothing   ->  LCD 7
  Nothing   ->  LCD 8
  Nothing   ->  LCD 9
  Nothing   ->  LCD 10
  ESP32 D5  ->  LCD 11 D4
  ESP32 D18 ->  LCD 12 D5
  ESP32 D19 ->  LCD 13 D6
  ESP32 D21 ->  LCD 14 D7
  ESP32 +5v ->  LCD 15 LED + (through 220 Ohm resistor)
  ESP32 GND ->  LCD 16 LED -



*/

// declare LCD pins

// include the library code:
#include <myNetwork.h>
#include <LiquidCrystal.h>
#include <Arduino.h>
#include <WiFi.h>
#include <myWiFi.h>
#include <myDisplay.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to

void ScrollingText(String(StringToScroll), int(LineToScroll));
NetWorkAddress connection;

void setup()
{
  Serial.begin(115200);
  initDisplay();

  displayLine(0, "Well Monitor");
  displayLine(1, "Connecting...");

  connection = initNetwork(preferredSSID, wifiPassword);

  displayLine(0, "IPV4 Address");
  displayLine(1, connection.IPAddress);
}

void loop()
{
}
