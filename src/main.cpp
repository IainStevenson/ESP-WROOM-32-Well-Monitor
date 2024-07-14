#include <LiquidCrystal.h>
#include <Arduino.h>
#include <WiFi.h>
#include <NTPClient.h>

#include <myWiFi.h>
#include <myNetwork.h>
#include <myDisplay.h>

void ScrollingText(String(StringToScroll), int(LineToScroll));
NetWorkAddress connection;
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");

const char PROGMEM *TIME_NOW = "Time now (UTC):";
const char PROGMEM *IPV4_ADDRESS = "IPV4 Address";
const char PROGMEM *TITLE = "Well Monitor";
const char PROGMEM *CONNECTING = "Connecting......";
const char PROGMEM *GETTINGTIME = "Getting time....";
const char PROGMEM *TIMESERVER = "From NNTP as UTC";
void setup()
{
  Serial.begin(115200);
  initDisplay();

  displayLine(0, TITLE);
  displayLine(1, CONNECTING);

  connection = initNetwork(preferredSSID, wifiPassword);

  displayLine(0, IPV4_ADDRESS);
  displayLine(1, connection.IPAddress);
  delay(5000);

  displayLine(0, GETTINGTIME);
  displayLine(1, TIMESERVER);

  initTimeServer(timeClient);
}
int counter = 0;
void loop()
{
  delay(1000);

  timeClient.update();

  displayLine(0, TIME_NOW);
  displayLine(1, timeClient.getFormattedTime());

  Serial.println(counter++);

  if (counter > 86400) // every 24 hours or so
  {
    resetDevice();
  }
}
