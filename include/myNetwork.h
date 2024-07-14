#ifndef myNetwork_h
#define myNetwork_h
#include <Arduino.h>

typedef struct
{
    String IPAddress;
    String MACAddress;
} NetWorkAddress;

NetWorkAddress initNetwork(const char *preferredSSID, const char *wifiPassword);
/// @brief Initialise the NNTP client and force an update,
/// @note wait for the time to synch before returning.
void initTimeServer(NTPClient timeClient);

#endif // myNetwork_h