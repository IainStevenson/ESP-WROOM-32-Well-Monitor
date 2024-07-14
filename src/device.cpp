#include <Arduino.h>
class ESPClass;

void reportHeap()
{
    Serial.print("HEAP size ");
    Serial.println(ESP.getHeapSize());
    Serial.print("HEAP free ");
    Serial.println(ESP.getFreeHeap());
    Serial.print("Count ");
}