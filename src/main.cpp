#include <myNetwork.h>
#include <LiquidCrystal.h>
#include <Arduino.h>
#include <WiFi.h>

#include <myWiFi.h>
#include <myDisplay.h>


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
