# LanuzaConnect  

LanuzaConnect is a library for ESP32 designed to facilitate and simplify the use of the communication functions between two ESP32 boards provided by ESP32-NOW. Please read this document to learn how to use it.  

## How to install this library  

To install this library, please follow these steps:  
1. Go to https://github.com/makerbylanuza/lanuza-connect/.
2. Click on the green Code button located in the upper right corner
3. Click on the Download ZIP option.
4. Create a new sketch on Arduino IDE.
5. Go to Sketch > Include library > Add .ZIP library
6. Select the ZIP file you downloaded
7. You now have LanuzaConnect available for use in your Arduino IDE projects!

## How to use this library  

To use this library, please first install it using the steps above. Then, open one of the examples include in the library by opening Arduino IDE and going to File > Examples > Custom library examples > LanuzaConnect, or follow these instructions 

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

### How do I initialise the WiFi device?

In order to use the library, you must first create an object of the LanuzaConnect class specifying the type of device. Do this adding the following to your sketch before the `void setup()` function:
```C++
LanuzaConnect esp(MODE);
```
Substitute the MODE argument for one of the following:
| Argument       | Use                                                                              |
| -------------- | -------------------------------------------------------------------------------- |
|`"TRANSMITTER"` | The board will only be able to transmit messages to other boards                 |
|`"RECEIVER"`    | The board will only be able to receive messages from other boards                |
|`"TRANSCEIVER"` | The board be able to both transmit and receive messages to and from other boards |
|`"MAC"`         | Mode used only to display the board's MAC address: it can't transmit or receive  |

Then, in the `void setup()` function, you must initialise your device, using the `init()` method, such as in the following example:  
```C++
void setup() {
  Serial.begin(115200);
  esp.init();
}
```

In the Serial Monitor, the following text should appear (with the XXX replaced by the MAC address of your board and the mode you initialised it in):
```
MAC Address: XX:XX:XX:XX:XX:XX
WiFi initialized
ESP-NOW initialized
Mode: XXXXXXXXXXXXX
```

### How do I add a peer board to send messages to?

To do this, you must first define the MAC address of the board you want to send messages to. Do this by defining an array of type `uint8_t` with the address, such as in the following line:
```C++
uint8_t receiver[] = {0xXX, 0xXX, 0xXX, 0xXX, 0xXX, 0xXX};
```

Then, in the `void setup()`, use the `addPeer()` function to add your peer board, using the variable defined before as an argument. You must do so **after initializing your board**. Please make sure that your board was initialized in either the `"TRANSMITTER"` or the `"TRANSCEIVER"` modesAn example is shown below:
```C++
void setup() {
  Serial.begin(115200);
  esp.init();
  esp.addPeer(receiver);
}
```

In the Serial Monitor, the following text should appear (the XXX replaced by the actual address):
```
Peer added: XX:XX:XX:XX:XX:XX
```

### How do I send a message?

To send a message, you must first have initialised your ESP32 WiFi device and have added a peer to send text to. Then, the `sendString()` function should be used. This function takes two arguments: a `String` type variable with the data to send, and then a `uint8_t` array with the destination address. An example is shown below:
```C++
void loop() {
  esp.sendString("Hello World!", receiver);
  delay(5000);
}
```

If the send is completed successfuly and the receiver receives it correctly, the following text should appear in the Serial Monitor:
```
Sent successfully data: Hello World!
Text sent; Delivery Success
```

If the send is completed, but the receiver is not active or working, then the following should appear:
```
Sent successfully data: Hello World!
Text sent; Delivery Fail
```

### How do I see if I've received any data?

To see if your ESP32 board has received any data, you do not have to do anything. Your board must, however, be initialized in either `"RECEIVER"` or `"TRANSCEIVER"` mode. Then, if your board receives anything, you will see the following message in the Serial Monitor:
```
Received data: Hello World!
Length: 12
```

However, this does not allow you to get the text you received. To do this, please follow the instructions in the next question.

### How do I get the text I received?

In order to use the text received by your ESP32 board, you have to use the `getLast()` function. This function will return as a string the last received data. An example is shown below:
```C++
#include <LanuzaConnect.h>

LanuzaConnect esp("RECEIVER");
String last = "";

void setup() {
  Serial.begin(115200);
  esp.init();
}

void loop() {
  if (last != esp.getLast()) {
    last = esp.getLast();
    Serial.println("Received something!");
  }
}
```
