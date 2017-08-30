/* 
Test program 10 servos for Massage post- stroke rehabilitation
*/
int Mass1[8][2]={2,178,12,166,24,154,36,142,48,130,60,118,72,106,84,94};
int Mass2[8][2]={68,178,53,163,38,148,23,135,16,120,10,108,5,100,2,95};
int posX, posY;
#include <Servo.h>
#define STEPTIME 5


Servo myservo0;  // create servo object to control a servo
Servo myservo1; 
Servo myservo2; 
Servo myservo3; 
Servo myservo4; 
Servo myservo5; 
Servo myservo6; 
Servo myservo7;
 Servo myservo8;
 Servo myservo9;

// twelve servo objects can be created on most boards

int pos0 = 0,pos1 = 0,pos2 = 0,pos3 = 0,  iCount0=0,  iCount1=90,  iCount2=180,  iCount3=270;    // variable to store the servo position
int pos[8];
int i;
int Ns = 25;
int ns;
void setup() 
{
Serial.begin(9600);
pinMode(A0,INPUT);


pinMode(13,INPUT_PULLUP);
  
  myservo0.attach(2, 630,2400);  // attaches the servo on pin 9 to the servo object
   myservo1.attach(3, 630,2400); 
    myservo2.attach(4, 630,2400); 
     myservo3.attach(5, 630,2400); 
         myservo4.attach(6, 630,2400); 
     myservo5.attach(7, 630,2400); 
     myservo6.attach(8, 630,2400); 
     myservo7.attach(9, 630,2400); 
     myservo8.attach(10, 630,2400); 
     myservo9.attach(12, 630,2400); 


     
}

void loop() {

pos0=0;


pos[0]=analogRead(A0)/4;
pos[1]=analogRead(A1)/4;
pos[2]=analogRead(A2)/4;
pos[3]=analogRead(A3)/4;
pos[4]=analogRead(A4)/4;
pos[5]=analogRead(A5)/4;



//delay(5+analogRead(A0)/32);


 delay(20);
  ++i%=16;
  if(i==7)
  i=8;
  if(i==15)
  i=0;
  for(ns = 0;   ns<Ns;ns++)
  {
    delay(STEPTIME);
if (digitalRead(13)==HIGH)
  
 {
  
  if (i < 8) 
  {

   posX = Mass1[i][0] + ns * (Mass1[(i+1)%8][0] - Mass1[i][0]) / Ns;
   posY = Mass1[i][1] + ns * (Mass1[(i+1)%8][1] - Mass1[i][1]) / Ns;
    
  myservo0.write(posX);
  myservo1.write(posY);

  myservo2.write(posX);
  myservo3.write(posY);

myservo4.write(posX);
  myservo5.write(posY);


  myservo6.write(posX);
  myservo7.write(posY);
  
myservo8.write(posX);
   myservo9.write(posY);
  
  }
  else 
  {
posX = Mass1[15-i][0] + ns * (Mass1[(15-i-1)%8][0] - Mass1[15-i][0]) / Ns;
   posY = Mass1[15-i][1] + ns * (Mass1[(15-i-1)%8][1] - Mass1[15-i][1]) / Ns;

    
  myservo0.write(posX);
   myservo1.write(posY);

   myservo2.write(posX);
   myservo3.write(posY);

 myservo4.write(posX);
   myservo5.write(posY);

 myservo6.write(posX);
   myservo7.write(posY);

 myservo8.write(posX);
   myservo9.write(posY);
  
  }
 }

else
 {
  
  if (i < 8)
  {

  posX = Mass2[i][0] + ns * (Mass2[(i+1)%8][0] - Mass2[i][0]) / Ns;
   posY = Mass2[i][1] + ns * (Mass2[(i+1)%8][1] - Mass2[i][1]) / Ns;

    
  myservo0.write(posX);
   myservo1.write(posY);

   myservo2.write(posX);
   myservo3.write(posY);

 myservo4.write(posX);
   myservo5.write(posY);

 myservo6.write(posX);
   myservo7.write(posY);

  myservo8.write(posX);
   myservo9.write(posY);
  
  }
  else 
  {

 posX = Mass2[15-i][0] + ns * (Mass2[(15-i-1)%8][0] - Mass2[15-i][0]) / Ns;
   posY = Mass2[15-i][1] + ns * (Mass2[(15-i-1)%8][1] - Mass2[15-i][1]) / Ns;


    
  myservo0.write(posX);
   myservo1.write(posY);

   myservo2.write(posX);
   myservo3.write(posY);

 myservo4.write(posX);
   myservo5.write(posY);

 myservo6.write(posX);
   myservo7.write(posY);

   myservo8.write(posX);
   myservo9.write(posY);
  
  }
 }



  }

//
//
//
//
//
//
//
// 
//    myservo0.write(pos[0]);              // tell servo to go to position in variable 'pos'
//     myservo1.write(pos[1]);   
//      myservo2.write(pos[2]);   
//       myservo3.write(pos[3]);   
//        myservo4.write(pos[4]);   
//       myservo5.write(pos[5]); 
//
//       for (i=0;i<6;i++)
//       {
        Serial.print(i);
        Serial.print("  ");
       Serial.print(posX);
       Serial.print("  ");
        Serial.println(posY);
        

//       }
//
//       Serial.println("");
}

