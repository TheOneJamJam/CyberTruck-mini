#include <SoftwareSerial.h>

char command;
int Tx = 10;
int Rx = 11;

int motor = 5;

//sets the 2 and 3 pins on Arduino as serial ports, allowing them to recieve bluetooth info
SoftwareSerial bluetooth(Tx, Rx);

void setup() {
  pinMode(motor, OUTPUT);

  Serial.begin(9600);

  Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
  bluetooth.begin(9600);
  bluetooth.println("Hello, world?");
}
void loop() {
  // put your main code here, to run repeatedly:
  if (bluetooth.available() ) {
    command = bluetooth.read();

    switch(command) {
      case '2':
        delay(30);
        analogWrite(motor, 200);
        bluetooth.println("MOTOR VROOOOOM");
        break;
      case '1':
        analogWrite(motor, 50);
        delay(30);
        bluetooth.println("motor meh...");
        break;
      }
    
    
    }
}
