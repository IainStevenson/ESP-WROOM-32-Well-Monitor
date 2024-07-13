#ifndef myNetwork_h
#define myNetwork_h
#include <Arduino.h>

typedef struct
{
    String IPAddress;
    String MACAddress;
} NetWorkAddress;

NetWorkAddress initNetwork(const char *preferredSSID, const char *wifiPassword);

#endif // myNetwork_h