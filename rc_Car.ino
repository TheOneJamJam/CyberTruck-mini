5//Definig Motor actions and their corresponding pins on the Arduino
#define RightForw 11 //Arduino Pin that causes right motors of vehicle to go forword if voltage applied
#define RightBack 10 //Arduino Pin that causes right motors of vehicle to go backwards if voltage applied
#define LeftForw 5 //Arduino Pin that causes left motors of vehicle to go forword if voltage applied
#define LeftBack 6 //Arduino Pin that causes left motors of vehicle to go backwards if voltage applied

//Definig LED locations and corresponding pins on the Arduino
#define LED_FR A0   //LED Front Right
#define LED_FL A1   //LED Front Left
#define LED_BR A2   //LED Back Right
#define LED_BL A3   //LED Back Left

int Speed = 255;      //speed of car, range: 0- 256
int turnRad = 255;   //higher number causes vehicle to turn slower, range: 0 - Value of variable Speed



void setup() {
  // put your setup code here, to run once:
  //Setting all the pins with components attatched to recieve instructions from the Arduino
  pinMode(RightForw, OUTPUT);
  pinMode(RightBack, OUTPUT);
  pinMode(LeftForw, OUTPUT);
  pinMode(LeftBack, OUTPUT);
  pinMode(LED_FR, OUTPUT);
  pinMode(LED_FL, OUTPUT);
  pinMode(LED_BR, OUTPUT);
  pinMode(LED_BL, OUTPUT);

  //setting baud rate (pulses of information / second) of the Bluetooth Module
  Serial.begin(9600);
  Serial.println("Hello World?");  // Bluetooth module sends this text when connection is secured, confirming there is indeed a bluetooth connection
}

void loop() {
  // put your main code here, to run repeatedly:
  //checking if serial ports(RX, TX) are recieving any information, they are connected to the bluetooth module in this project
  if (Serial.available() ) {
    char command = Serial.read();  //Bluetooth Information  
    
    switch (command) {           //Bluetooth Module looks for keys pressed on the computer
      case '1':
        delay(300);
        analogWrite(RightForw, 200);
        Serial.println("1");
        break;
      case '2':
        delay(300);
        analogWrite(RightBack, 200);
        Serial.println("2");
        break;
      case '3':
        delay(300);
        analogWrite(LeftForw, 200);
        Serial.println("3");
        break;
      case '4':
        delay(300);
        analogWrite(LeftBack, 200);
        Serial.println("4");
        break;
      case 'w':
        delay(300);
        forw();
        Serial.println("w");
        break;
      case 'a':
        delay(300);
        left();
        Serial.println("a");
        break;
      case 's':
        delay(300);
        back();
        Serial.println("s");
        break;
      case 'd':
        delay(300);
        right();
        Serial.println("d");
        break;
      case '5':
        ShutDown();
        break;
     /*
      case 'z':
        Speed += 50;
        Serial.println("Zuper Fazt: " + Speed);
        break;
      case 'c':
        Speed -= 50;
        Serial.println("Cool Down: " + Speed);
        break;    
      */
      
      }
    //makes sure that Speed is a valid input for the motors (range: 0-256)
    /*
    if (Speed < 0) {
      Speed = 1;
      }
    else if (Speed > 256) {
      Speed = 255;
      }
      */
    }
                                                                                                                                         
}

//functions that control the different directions the vehicle moves
void forw() {
  ShutDown();
  delay(200);
  //analogWrite(RightBack, 0);
  //analogWrite(LeftBack, 0);
  analogWrite(RightForw, Speed);
  analogWrite(LeftForw, Speed);
  digitalWrite(LED_FR, HIGH);
  digitalWrite(LED_FL, HIGH);
  }
void back() {
  ShutDown();
  delay(200);
  //analogWrite(RightForw, 0);
  //analogWrite(LeftForw, 0);
  analogWrite(RightBack, Speed);
  analogWrite(LeftBack, Speed);
  analogWrite(LED_FR, HIGH);
  analogWrite(LED_FL, HIGH);
  }
void left() {
  ShutDown();
  delay(50);
  //analogWrite(RightBack, 0);
  //analogWrite(LeftForw, 0);
  analogWrite(RightForw, Speed);
  analogWrite(LeftBack, turnRad);
  analogWrite(LED_FR,HIGH);
  analogWrite(LED_FL, HIGH);
  }
void right() {
  ShutDown();
  delay(50);
  //analogWrite(RightForw, 0);
  //analogWrite(LeftBack, 0);
  analogWrite(LeftForw, Speed);
  analogWrite(RightBack, turnRad);
  analogWrite(LED_FR,HIGH);
  analogWrite(LED_FL, HIGH);
  }
/*void forwLeft() {
  analogWrite(RightForw, Speed);
  analogWrite(LeftForw, turnRad);
  analogWrite(RightForw, Speed);
  analogWrite(LeftForw, turnRad);
  }
void forwRight() {
  analogWrite(RightForw, turnRad);
  analogWrite(LeftForw, Speed);
  }
void backRight() {
  analogWrite(RightBack, turnRad);
  analogWrite(LeftBack, Speed);
  }
void backLeft() {
  analogWrite(RightBack, Speed);
  analogWrite(LeftBack, turnRad);
  }
*/

//turns off all motors & lights
void ShutDown() {
  analogWrite(RightForw, 0);
  analogWrite(RightBack, 0);
  analogWrite(LeftForw, 0);
  analogWrite(LeftBack, 0);
  
  }
