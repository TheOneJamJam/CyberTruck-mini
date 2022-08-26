/* Code written by Chams for Youtube Channel - That'sEngineering
 *  13/2/2020
 *  Youtube video: HC-05 BT module, interfacing with Arduino (via Computer)
 *  
 */

#include <SoftwareSerial.h>

char value;
int Tx = 2;       // connect BT module TX to 2
int Rx = 3;       // connect BT module RX to 3

int redLED = 4;

// creates a "virtual" serial port/UART
SoftwareSerial bluetooth(Tx, Rx);

void setup() {
  pinMode(redLED, OUTPUT);

  // start serial communication at default baud rate 9600bps
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() {
  
    if (bluetooth.available()) {
      
      value = bluetooth.read();
      
      if (value =='3') {
        digitalWrite(redLED, HIGH);
        bluetooth.println("Red LED on");
      }
      
      if (value =='4') {
        digitalWrite(redLED, LOW);
        bluetooth.println("Red LED off");
      }
    }
}
