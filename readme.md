
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
Potentiometer (Middle pin (or on its own))	1602 LCD	VO (Contrast Adjust)
Potentiometer (One side)	GND	-
Potentiometer (Other side)	5V	-

```