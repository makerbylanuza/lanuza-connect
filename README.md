# LanuzaConnect  

LanuzaConnect is a library for ESP32 designed to facilitate and simplify the use of the communication functions between two ESP32 boards provided by ESP32-NOW. Please read this document to learn how to use it.  

## How to install this library  

To install this library, please follow these steps:  
1. Go to https://github.com/makerbylanuza/lanuza-connect/tree/main.
2. Click on the green Code button located in the upper right corner
3. Click on the Download ZIP option.
4. Create a new sketch on Arduino IDE.
5. Go to Sketch > Include library > Add .ZIP library
6. Select the ZIP file you downloaded
7. You now have LanuzaConnect available for use in your Arduino IDE projects!

## How to use this library  

To use this library, please first install it using the steps above. Then, open one of the examples include in the library by opening Arduino IDE and going to File > Examples > Custom library examples > LanuzaConnect.  

### How do I include this library in an Arduino IDE sketch?

Just include the following code at the top of your sketch:
```C++
#include <LanuzaConnect.h>
```
After that, you can use all of the functions explained below.

### How do I find my ESP32's MAC address?

To do that, please open the `macfinder.ino` example in Arduino IDE, select your board and port and upload it. Reset your ESP32 by clicking on the RST button and look at the Serial Monitor at a rate of 115200 baud. Something like this should appear:
```
MAC Address: XX:XX:XX:XX:XX:XX
```
Please copy this MAC address. It will be different for each ESP32 board. You will need to use it each time you want to send something to that board.

### How do I initalise the WiFi device?

In order to use the library, you must first create an object of the LanuzaConnect class specifying the type of device. Do this adding the following to your sketch before the `void setup()` function:
```C++
LanuzaConnect esp(MODE);

/*
PLEASE SUBSTITUTE MODE FOR ONE OF THE FOLLOWING:

"TRANSMITTER" - Able to only transmit messages to other boards
"RECEIVER" - Able to only receive messages from other boards
"TRANSCEIVER" - Able to both transmit and receive messages
"MAC" - Used only to display the board MAC address
*/
```
Substitute the MODE argument for one of the following:
| Argument       | Use  |
| -------------- | ---- |
|`"TRANSMITTER"` | 
### fsf
