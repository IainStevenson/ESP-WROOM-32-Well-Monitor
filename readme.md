
# Wiring
This setup reflects the connections specified in the updated sketch and uses the available GPIO pins on the ESP32 to ensure the correct operation of the DHT11, HC-SR04, and the LCD 1602 display.


```
+---------+       +---------+      +---------+
| ESP32   |       | DHT11   |      | HC-SR04 |
|         |       |         |      |         |
|   3V3 --+-------+ VCC     |      | VCC     |
|   GND --+-------+ GND     |      | GND     |
|  GPIO15-+-------+ Data    |      |         |
|         |       +---------+      |         |
|  GPIO13-+------------------------+ Trig    |
|  GPIO14-+------------------------+ Echo    |
|         |                        +---------+
|         |                        
|         |
|         |       +---------+      +---------+
|         |       | LCD 1602|      |Potentiom|
|         |       |         |      |(10k Ohm)|
|   GND --+-------+ VSS     |      +---------+
|    5V --+-------+ VDD     |      |  Pin 1  |  5V
|         +--+----+ VO      |      |  Pin 2  |
|  GPIO22 |  |    | RS      |      |  Pin 3  |  GND
|         |  +----+ RW (GND)|      +---------+
|  GPIO23-+-------+ E       |
|                   D0      |      
|                   D1      |      
|                   D2      |      
|                   D3      |      
|  GPIO15-+-------+ D4      |
|  GPIO18-+-------+ D5      |
|  GPIO19-+-------+ D6      |
|  GPIO21-+-------+ D7      |
|    5V --+--220Ω-+ A (LED+)| 
|   GND --+-------+ K (LED-)| 
+---------+       +---------+

For clarity
Potentiometer 
Pin 1 (Middle pin (or on its own))	1602 LCD	VO (Contrast Adjust)
Pin 2 (One side)	+5V
Pin 3 (Other side)	GND	

Pins
        1
        O     < dial
       2 3
This way the clockwise is brighter
Reversing pins 2 and 3 results in reversal of the LCD contrast control to clockwise is dimmer.

Added WIFI, connecting to ssid and using password in the myWiFi.h (you need to add your own).
And showing IP Address as default banner on LCD once connected.

Initialising a Network time server client and geting the time updated every 10 seconds and displayed as UTC.



Notes: 

Serial output is as follows;

Initialising network
Connecting to SSID: <ssid>
..
Connected! IP Address: 192.168.0.50 MAC Address: xx:xx:xx:xx:xx:xx
Initialising time client
Getting time from server

HEAP size 331232
HEAP free 255848
Count 0
HEAP size 331232
HEAP free 255840
Count 1
HEAP size 331232
HEAP free 255840
Count 2
HEAP size 331232
HEAP free 255848
Count 3
HEAP size 331232
HEAP free 255840
Count 4
HEAP size 331232
HEAP free 255840
Count 5
HEAP size 331232
HEAP free 255840
Count 6
HEAP size 331232
HEAP free 255840
Count 7
HEAP size 331232
HEAP free 255840
Count 8
HEAP size 331232
HEAP free 255840
Count 9
HEAP size 331232
HEAP free 255840
Count 10
ets Jul 29 2019 12:21:46
```