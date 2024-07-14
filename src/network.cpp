
#include <WiFi.h>
#include <NTPClient.h>
#include <time.h>
#include <Arduino.h>
#include <myNetwork.h>

NetWorkAddress initNetwork(const char *ssid, const char *password)
{
    NetWorkAddress connection;
    Serial.println("Initialising network");

    WiFi.begin(ssid, password);
    Serial.print("Connecting to SSID: ");
    Serial.println(ssid);

    unsigned long startTime = millis();
    while (WiFi.status() != WL_CONNECTED && millis() - startTime < 10000)
    { // 10 second timeout
        delay(500);
        Serial.print(".");
    }
    Serial.println("");

    // If connected, print the MAC address and return
    if (WiFi.status() == WL_CONNECTED)
    {
        Serial.print("Connected! ");
        Serial.print("IP Address: ");
        Serial.print(WiFi.localIP());
        Serial.print(" MAC Address: ");
        Serial.println(WiFi.macAddress());
        connection.IPAddress = WiFi.localIP().toString();
        connection.MACAddress = WiFi.macAddress();
    }
    else
    {
        Serial.print("Failed to connect, ");
        Serial.println("Please reset");
        while (true)
        {
            delay(500);
        }
    }
    return connection;
}

void initTimeServer(NTPClient timeClient)
{
    Serial.println("Initialising time client");

    timeClient.begin();
    Serial.print("Getting time from server");
    while (!timeClient.forceUpdate())
    {
        Serial.print("Getting time from server: Now = ");
        Serial.println(timeClient.getFormattedTime());

        delay(1000);
    }
}