#include<cvzone.h>
#include<ESP32Servo.h>

Servo servo[2];

SerialData serialData(2,3); //Values per tx, digits per value
int valsRec[2];

#define servoPin1 2
#define servoPin2 4

void setup() {
  // put your setup code here, to run once:

  //Serial.begin(9600); 
  serialData.begin(9600);

  servo[0].setPeriodHertz(50);
  servo[0].attach(servoPin1, 500, 2400);
  servo[0].write(0);

  servo[1].setPeriodHertz(50);
  servo[1].attach(servoPin2, 500, 2400);
  servo[1].write(0);

  
}

void loop() {
  // put your main code here, to run repeatedly:

  serialData.Get(valsRec);
  //digitalWrite(LED,valsRec[0]);
  servo[0].write(valsRec[0]); 
  servo[1].write(valsRec[1]);


}
