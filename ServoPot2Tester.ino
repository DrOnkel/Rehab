/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo0;  // create servo object to control a servo
Servo myservo1; 
 
// twelve servo objects can be created on most boards

int pos0 = 0,pos1 = 0,pos2 = 0,pos3 = 0,  iCount0=0,  iCount1=90,  iCount2=180,  iCount3=270;    // variable to store the servo position

void setup() 
{
Serial.begin(9600);
pinMode(A0,INPUT);



  
  myservo0.attach(2);  // attaches the servo on pin 9 to the servo object
   myservo1.attach(3); 
  
}

void loop() {

pos0=0;


pos0=(1023-analogRead(A0))/4;
pos1=(1023-analogRead(A1))/4;

//delay(5+analogRead(A0)/32);


 
  Serial.print(pos0);
  Serial.print("  \t");
  Serial.println(pos1);
 

 








 
    myservo0.write(pos0);              // tell servo to go to position in variable 'pos'
     myservo1.write(pos1);   
 

       delay(100);
}

