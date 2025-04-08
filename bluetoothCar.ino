char cmd;//The Bluetooth Command

//The L298N Control Pins
const int rightMotorForward = 2;
const int rightMotorBackward = 3;

const int leftMotorForward = 4;
const int leftMotorBackward = 5;

const int rightLed=6;
const int leftLed=7;
const int bezo=8;
 
void setup() {
  pinMode(leftMotorForward,OUTPUT);   //left motor forward
  pinMode(leftMotorBackward,OUTPUT);   //left motor reverse
  pinMode(rightMotorForward,OUTPUT);   //right motor forward
  pinMode(rightMotorBackward,OUTPUT);   //right motor reverse
  pinMode(rightLed,OUTPUT);
  pinMode(leftLed,OUTPUT);
  pinMode(bezo,OUTPUT);
  Serial.begin(9600);
}
 
void loop() {
  if(Serial.available()){
    cmd = Serial.read();
  }
   
  if(cmd == 'F'){           //move forward
    digitalWrite(leftMotorForward,HIGH);
    digitalWrite(rightMotorForward,HIGH);
  }
   
  else if(cmd == 'B'){      //move reverse
    digitalWrite(leftMotorBackward,HIGH);
    digitalWrite(rightMotorBackward,HIGH);
  }
   
  else if(cmd == 'L'){      //turn Left
    digitalWrite(rightMotorForward,HIGH);
    digitalWrite(leftLed,HIGH);
    delay(100);
    digitalWrite(leftLed,LOW);
    delay(100);
    digitalWrite(leftLed,HIGH);
    delay(100);
    digitalWrite(leftLed,LOW);
    
  }
   
  else if(cmd == 'R'){      //turn Right
    digitalWrite(leftMotorForward,HIGH);
    digitalWrite(rightLed,HIGH);
    delay(100);
    digitalWrite(rightLed,LOW);
    delay(100);
    digitalWrite(rightLed,HIGH);
    delay(100);
    digitalWrite(rightLed,LOW);
  }
   
  else{      //STOP (all motors stop)
    digitalWrite(leftMotorForward,LOW);
    digitalWrite(leftMotorBackward,LOW);
    digitalWrite(rightMotorForward,LOW);
    digitalWrite(rightMotorBackward,LOW);
  }
}
