/*

  Servo Rehab Helper by ErgBusterz from Tchernogolovka
  Bogdanov Bogdanovf Komarov
  20170902


  For library information please go to refs:
  http://www.arduino.cc/en/Tutorial/Sweep

  http://playground.arduino.cc/Main/LedControl




*/

#include "LedControl.h"  // from  http://playground.arduino.cc/Main/LedControl




 int Mass1[8][2] = {101, 111, 91, 106, 81, 100, 73, 94, 66, 87, 60, 79, 54, 71, 49, 63};
 int Mass1r[8][2] = {49, 63, 54, 71, 60, 79, 66, 87, 73, 94, 81, 100, 91, 106, 101, 111};

int Mass2[8][2] = {99, 62, 89, 72, 81, 80, 75, 86, 71, 91, 67, 94, 65, 97, 63, 99};
int Mass2r[8][2] = {63, 99, 65, 97, 67, 94, 71, 91, 75, 86, 81, 80, 89, 72, 99, 62};

int Mass5[8][2] = {137, 76, 129, 67, 121, 58, 111, 49, 101, 41, 91, 34, 80, 27, 69, 21};
int Mass5r[8][2] = {69, 21, 80, 27, 91, 34, 101, 41, 111, 49, 121, 58, 129, 67, 137, 76};


int Mass6[8][2] = {99, 102, 86, 104, 75, 103, 66, 100, 58, 94, 53, 86, 50, 76, 50, 63,};
int Mass6r[8][2] = {50, 63, 50, 76, 53, 86, 58, 94, 66, 100, 75, 103, 86, 104, 99, 102,};



int Mass7[8][2] = {76, 90, 68, 90, 63, 87, 61, 82, 62, 74, 63, 63, 66, 49, 70, 33,};
int Mass7r[8][2] = {70, 33, 66, 49, 63, 63, 62, 74, 61, 82, 63, 87, 68, 90, 76, 90,};



//int Mass8[8][2] = {147, 124, 118, 118, 95, 109, 77, 97, 63, 83, 52, 67, 42, 49, 33, 30};
//int Mass8r[8][2] = {33, 30, 42, 49, 52, 67, 63, 83, 77, 97, 95, 109, 118, 118, 147, 124};

int Mass8[8][2] = {99, 62, 89, 72, 81, 80, 75, 86, 71, 91, 67, 94, 65, 97, 63, 99};
int Mass8r[8][2] = {63, 99, 65, 97, 67, 94, 71, 91, 75, 86, 81, 80, 89, 72, 99, 62};



unsigned long VibCount, VibCount1;
unsigned long SelectTimer;
int posX, posY, posX2, posY2;
byte Mode = 0, PressN = 0, PressLimit;
#include <Servo.h>



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

LedControl lc = LedControl(11, 13, A5, 2);
byte LedCh[16], iLed, IndyTimer, TactPoint, CountTimer;


int pos0 = 0, pos1 = 0, pos2 = 0, pos3 = 0,  iCount0 = 0,  iCount1 = 90,  iCount2 = 180,  iCount3 = 270; // variable to store the servo position
int pos[8];
int i;
int Ns = 10;
int ns;
int TimerA0;
void setup()
{
  Serial.begin(115200);
  pinMode(A0, INPUT);
  pinMode(A4, INPUT_PULLUP);
  pinMode(A5, OUTPUT);

  pinMode(13, OUTPUT);


  lc.shutdown(0, false);
  lc.shutdown(1, false);
  /* Set the brightness to a maximum values */
  lc.setIntensity(0, 15);
  lc.setIntensity(1, 15);

  /* and clear the display */
  lc.clearDisplay(0);
  lc.clearDisplay(1);




  myservo0.attach(2, 630, 2400); // attaches the servo on pin 9 to the servo object
  delay(100);
  myservo1.attach(3, 630, 2400);
  delay(200);
  myservo2.attach(4, 630, 2400);
  delay(200);
  myservo3.attach(5, 630, 2400);
  delay(100);
  myservo4.attach(6, 630, 2400);
  delay(200);
  myservo5.attach(7, 630, 2400);
  delay(300);
  myservo6.attach(8, 630, 2400);
  delay(300);
  myservo7.attach(9, 630, 2400);
  delay(300);
  myservo8.attach(10, 630, 2400);
  delay(400);
  myservo9.attach(12, 630, 2400);
  delay(400);
  LedCh[0] = ' ';
  LedCh[3] = ' ';


}

void loop() {

  if (Mode > 0)
    VibCount++;



  if (CountTimer > 0)
  {
    LedCh[1] = Mode % 10 ;
    LedCh[2] = Mode / 10;

    VibCount1 = (VibCount / 15);
    LedCh[4] = VibCount1 % 10;
    LedCh[5] = (VibCount1 / 10) % 10;
    LedCh[6] = (VibCount1 / 100) % 10;
    LedCh[7] = (VibCount1 / 1000) % 10;


    LedCh[8] = Ns % 10;
    LedCh[9] = (Ns / 10) % 10;
    if (Ns / 100 > 0)
      LedCh[10] = (Ns / 100) % 10;
    else
      LedCh[10] = ' ';
    LedCh[11] = 'F';

    LedCh[12] = TimerA0 % 10;
    LedCh[13] = (TimerA0 / 10) % 10;
    if (TimerA0 / 100 > 0)
      LedCh[14] = (TimerA0 / 100) % 10;
    else
      LedCh[14] = ' ';
    LedCh[15] = 'P';








    CountTimer = 0;
  }



  if (IndyTimer > 0)
  {



    IndyTimer = 0;


    lc.setChar(0, 4, LedCh[0], false);
    lc.setChar(0, 5, LedCh[1], false);
    lc.setChar(0, 6, LedCh[2], false);
    lc.setChar(0, 7, LedCh[3], false);

    lc.setChar(0, 0, LedCh[4], false);
    lc.setChar(0, 1, LedCh[5], false);
    lc.setChar(0, 2, LedCh[6], false);
    lc.setChar(0, 3, LedCh[7], false);

    if (TactPoint++ > 1)
      lc.setChar(1, 0, LedCh[12], 1);
    else
      lc.setChar(1, 0, LedCh[12], false);

    if (TactPoint > 19)
      TactPoint = 0;

    lc.setChar(1, 1, LedCh[13], false);
    lc.setChar(1, 2, LedCh[14], false);
    lc.setChar(1, 3, LedCh[15], false);

    lc.setChar(1, 4, LedCh[8], false);
    lc.setChar(1, 5, LedCh[9], false);
    lc.setChar(1, 6, LedCh[10], false);
    lc.setChar(1, 7, LedCh[11], false);

    CountTimer = 1;
  }



  if ( (millis() - SelectTimer)  > 100   )


  {
    SelectTimer = millis();

    TimerA0 = (analogRead(A0)) / 10  ;
    Ns = analogRead(A1) / 32 + 3;

    if ( digitalRead(A4) == HIGH) //  PINC==17) //(PINC&0x10) ==   0x10)
      PressN = 0;
    else
    {

      PressLimit = byte (  1000 / (TimerA0 * Ns + 1));
      if (PressLimit < 1)
        PressLimit = 1;
      if (PressLimit > 20)
        PressLimit = 10;
      Serial.print(TimerA0);
      Serial.print("  ");
      Serial.print (Ns);
      Serial.print(" pressl= ");
      Serial.print(PressLimit);

      Serial.print("res=  ");
      Serial.println(1000 / (TimerA0 * Ns + 1));
      if (++PressN > PressLimit)
      {
        if (Mode++ > 16)
          Mode = 0;
        PressN = 0;

      }

    }
    if (CountTimer == 0)
      IndyTimer = 10;

  }
  ++i %= 16;
  if (i == 7)
    i = 8;
  if (i == 15)
    i = 0;
  for (ns = 0;   ns < Ns; ns++)
  {
    delay(TimerA0);

    if (Mode == 1  || Mode == 9)
    {

      if (i < 8)
      {

        posX = Mass1[i][0] + ns * (Mass1[(i + 1) % 8][0] - Mass1[i][0]) / Ns;
        posY = Mass1[i][1] + ns * (Mass1[(i + 1) % 8][1] - Mass1[i][1]) / Ns;

        posX2 = Mass1r[i][0] + ns * (Mass1r[(i + 1) % 8][0] - Mass1r[i][0]) / Ns;
        posY2 = Mass1r[i][1] + ns * (Mass1r[(i + 1) % 8][1] - Mass1r[i][1]) / Ns;



        myservo0.write(posX);
        myservo1.write(posY);

        myservo2.write(posX);
        myservo3.write(posY);

        myservo4.write(posX2);
        myservo5.write(posY2);


        myservo6.write(posX2);
        myservo7.write(posY2);

        if (Mode == 9)
        {
          myservo8.write(posX);
          myservo9.write(posY);

        }

      }
      else
      {
        posX = Mass1[15 - i][0] + ns * (Mass1[(15 - i - 1) % 8][0] - Mass1[15 - i][0]) / Ns;
        posY = Mass1[15 - i][1] + ns * (Mass1[(15 - i - 1) % 8][1] - Mass1[15 - i][1]) / Ns;
        posX2 = Mass1r[15 - i][0] + ns * (Mass1r[(15 - i - 1) % 8][0] - Mass1r[15 - i][0]) / Ns;
        posY2 = Mass1r[15 - i][1] + ns * (Mass1r[(15 - i - 1) % 8][1] - Mass1r[15 - i][1]) / Ns;


        myservo0.write(posX);
        myservo1.write(posY);

        myservo2.write(posX);
        myservo3.write(posY);

        myservo4.write(posX2);
        myservo5.write(posY2);

        myservo6.write(posX2);
        myservo7.write(posY2);

        if (Mode == 9)
        {
          myservo8.write(posX);
          myservo9.write(posY);

        }


      }


    }


    else  if (Mode == 2  || Mode == 10)
    {

      if (i < 8)
      {

        posX = Mass1[i][0] + ns * (Mass1[(i + 1) % 8][0] - Mass1[i][0]) / Ns;
        posY = Mass1[i][1] + ns * (Mass1[(i + 1) % 8][1] - Mass1[i][1]) / Ns;





        myservo0.write(posX);
        myservo1.write(posY);

        myservo2.write(posX);
        myservo3.write(posY);

        myservo4.write(posX);
        myservo5.write(posY);


        myservo6.write(posX);
        myservo7.write(posY);

        if (Mode == 10)
        {
          myservo8.write(posX);
          myservo9.write(posY);

        }

      }
      else
      {
        posX = Mass1[15 - i][0] + ns * (Mass1[(15 - i - 1) % 8][0] - Mass1[15 - i][0]) / Ns;
        posY = Mass1[15 - i][1] + ns * (Mass1[(15 - i - 1) % 8][1] - Mass1[15 - i][1]) / Ns;



        myservo0.write(posX);
        myservo1.write(posY);

        myservo2.write(posX);
        myservo3.write(posY);

        myservo4.write(posX);
        myservo5.write(posY);

        myservo6.write(posX);
        myservo7.write(posY);

        if (Mode == 10)
        {
          myservo8.write(posX);
          myservo9.write(posY);

        }


      }


    }











    else  if (Mode == 3    || Mode == 11           )
    {

      if (i < 8)
      {

        posX = Mass2[i][0] + ns * (Mass2[(i + 1) % 8][0] - Mass2[i][0]) / Ns;
        posY = Mass2[i][1] + ns * (Mass2[(i + 1) % 8][1] - Mass2[i][1]) / Ns;

        posX2 = Mass2r[i][0] + ns * (Mass2r[(i + 1) % 8][0] - Mass2r[i][0]) / Ns;
        posY2 = Mass2r[i][1] + ns * (Mass2r[(i + 1) % 8][1] - Mass2r[i][1]) / Ns;



        myservo0.write(posX);
        myservo1.write(posY);

        myservo2.write(posX2);
        myservo3.write(posY2);

        myservo4.write(posX);
        myservo5.write(posY);


        myservo6.write(posX2);
        myservo7.write(posY2);


        if (Mode == 11)
        {
          myservo8.write(posX);
          myservo9.write(posY);
        }

      }
      else
      {
        posX = Mass2[15 - i][0] + ns * (Mass2[(15 - i - 1) % 8][0] - Mass2[15 - i][0]) / Ns;
        posY = Mass2[15 - i][1] + ns * (Mass2[(15 - i - 1) % 8][1] - Mass2[15 - i][1]) / Ns;
        posX2 = Mass2r[15 - i][0] + ns * (Mass2r[(15 - i - 1) % 8][0] - Mass2r[15 - i][0]) / Ns;
        posY2 = Mass2r[15 - i][1] + ns * (Mass2r[(15 - i - 1) % 8][1] - Mass2r[15 - i][1]) / Ns;


        myservo0.write(posX);
        myservo1.write(posY);

        myservo2.write(posX2);
        myservo3.write(posY2);

        myservo4.write(posX);
        myservo5.write(posY);

        myservo6.write(posX2);
        myservo7.write(posY2);
        if (Mode == 11)
        {
          myservo8.write(posX);
          myservo9.write(posY);
        }

      }





    }


    else  if (Mode == 4    || Mode == 12)
    {

      if (i < 8)
      {

        posX = Mass2[i][0] + ns * (Mass2[(i + 1) % 8][0] - Mass2[i][0]) / Ns;
        posY = Mass2[i][1] + ns * (Mass2[(i + 1) % 8][1] - Mass2[i][1]) / Ns;





        myservo0.write(posX);
        myservo1.write(posY);

        myservo2.write(posX);
        myservo3.write(posY);

        myservo4.write(posX);
        myservo5.write(posY);


        myservo6.write(posX);
        myservo7.write(posY);
        if (Mode == 12)
        {
          myservo8.write(posX);
          myservo9.write(posY);
        }

      }
      else
      {
        posX = Mass2[15 - i][0] + ns * (Mass2[(15 - i - 1) % 8][0] - Mass2[15 - i][0]) / Ns;
        posY = Mass2[15 - i][1] + ns * (Mass2[(15 - i - 1) % 8][1] - Mass2[15 - i][1]) / Ns;



        myservo0.write(posX);
        myservo1.write(posY);

        myservo2.write(posX);
        myservo3.write(posY);

        myservo4.write(posX);
        myservo5.write(posY);

        myservo6.write(posX);
        myservo7.write(posY);
        if (Mode == 12)
        {
          myservo8.write(posX);
          myservo9.write(posY);
        }

      }





    }


    if (Mode == 8  || Mode == 16)
    {

      if (i < 8)
      {

        posX = Mass8[i][0] + ns * (Mass8[(i + 1) % 8][0] - Mass8[i][0]) / Ns;
        posY = Mass8[i][1] + ns * (Mass8[(i + 1) % 8][1] - Mass8[i][1]) / Ns;

        posX2 = Mass8r[i][0] + ns * (Mass8r[(i + 1) % 8][0] - Mass8r[i][0]) / Ns;
        posY2 = Mass8r[i][1] + ns * (Mass8r[(i + 1) % 8][1] - Mass8r[i][1]) / Ns;



        myservo0.write(posX);
        myservo1.write(posY);

        myservo2.write(posX);
        myservo3.write(posY);

        myservo4.write(posX2);
        myservo5.write(posY2);


        myservo6.write(posX2);
        myservo7.write(posY2);

        if (Mode == 16)
        {
          myservo8.write(posX);
          myservo9.write(posY);

        }

      }
      else
      {
        posX = Mass8[15 - i][0] + ns * (Mass8[(15 - i - 1) % 8][0] - Mass8[15 - i][0]) / Ns;
        posY = Mass8[15 - i][1] + ns * (Mass8[(15 - i - 1) % 8][1] - Mass8[15 - i][1]) / Ns;
        posX2 = Mass8r[15 - i][0] + ns * (Mass8r[(15 - i - 1) % 8][0] - Mass8r[15 - i][0]) / Ns;
        posY2 = Mass8r[15 - i][1] + ns * (Mass8r[(15 - i - 1) % 8][1] - Mass8r[15 - i][1]) / Ns;


        myservo0.write(posX);
        myservo1.write(posY);

        myservo2.write(posX);
        myservo3.write(posY);

        myservo4.write(posX2);
        myservo5.write(posY2);

        myservo6.write(posX2);
        myservo7.write(posY2);

        if (Mode == 16)
        {
          myservo8.write(posX);
          myservo9.write(posY);

        }


      }


    }



    else  if (Mode == 5  || Mode == 13)
    {

      if (i < 8)
      {

        posX = Mass5[i][0] + ns * (Mass5[(i + 1) % 8][0] - Mass5[i][0]) / Ns;
        posY = Mass5[i][1] + ns * (Mass5[(i + 1) % 8][1] - Mass5[i][1]) / Ns;

        posX2 = Mass5r[i][0] + ns * (Mass5r[(i + 1) % 8][0] - Mass5r[i][0]) / Ns;
        posY2 = Mass5r[i][1] + ns * (Mass5r[(i + 1) % 8][1] - Mass5r[i][1]) / Ns;



        myservo0.write(posX);
        myservo1.write(posY);

        myservo2.write(posX);
        myservo3.write(posY);

        myservo4.write(posX2);
        myservo5.write(posY2);


        myservo6.write(posX2);
        myservo7.write(posY2);

        if (Mode == 13)
        {
          myservo8.write(posX);
          myservo9.write(posY);

        }

      }
      else
      {
        posX = Mass5[15 - i][0] + ns * (Mass5[(15 - i - 1) % 8][0] - Mass5[15 - i][0]) / Ns;
        posY = Mass5[15 - i][1] + ns * (Mass5[(15 - i - 1) % 8][1] - Mass5[15 - i][1]) / Ns;
        posX2 = Mass5r[15 - i][0] + ns * (Mass5r[(15 - i - 1) % 8][0] - Mass5r[15 - i][0]) / Ns;
        posY2 = Mass5r[15 - i][1] + ns * (Mass5r[(15 - i - 1) % 8][1] - Mass5r[15 - i][1]) / Ns;


        myservo0.write(posX);
        myservo1.write(posY);

        myservo2.write(posX);
        myservo3.write(posY);

        myservo4.write(posX2);
        myservo5.write(posY2);

        myservo6.write(posX2);
        myservo7.write(posY2);

        if (Mode == 13)
        {
          myservo8.write(posX);
          myservo9.write(posY);

        }


      }


    }



    else  if (Mode == 6  || Mode == 14)
    {

      if (i < 8)
      {

        posX = Mass6[i][0] + ns * (Mass6[(i + 1) % 8][0] - Mass6[i][0]) / Ns;
        posY = Mass6[i][1] + ns * (Mass6[(i + 1) % 8][1] - Mass6[i][1]) / Ns;

        posX2 = Mass6r[i][0] + ns * (Mass6r[(i + 1) % 8][0] - Mass6r[i][0]) / Ns;
        posY2 = Mass6r[i][1] + ns * (Mass6r[(i + 1) % 8][1] - Mass6r[i][1]) / Ns;



        myservo0.write(posX);
        myservo1.write(posY);

        myservo2.write(posX);
        myservo3.write(posY);

        myservo4.write(posX2);
        myservo5.write(posY2);


        myservo6.write(posX2);
        myservo7.write(posY2);

        if (Mode == 14)
        {
          myservo8.write(posX);
          myservo9.write(posY);

        }

      }
      else
      {
        posX = Mass6[15 - i][0] + ns * (Mass6[(15 - i - 1) % 8][0] - Mass6[15 - i][0]) / Ns;
        posY = Mass6[15 - i][1] + ns * (Mass6[(15 - i - 1) % 8][1] - Mass6[15 - i][1]) / Ns;
        posX2 = Mass6r[15 - i][0] + ns * (Mass6r[(15 - i - 1) % 8][0] - Mass6r[15 - i][0]) / Ns;
        posY2 = Mass6r[15 - i][1] + ns * (Mass6r[(15 - i - 1) % 8][1] - Mass6r[15 - i][1]) / Ns;


        myservo0.write(posX);
        myservo1.write(posY);

        myservo2.write(posX);
        myservo3.write(posY);

        myservo4.write(posX2);
        myservo5.write(posY2);

        myservo6.write(posX2);
        myservo7.write(posY2);

        if (Mode == 14)
        {
          myservo8.write(posX);
          myservo9.write(posY);

        }


      }


    }

    else  if (Mode == 7  || Mode == 15)
    {

      if (i < 8)
      {

        posX = Mass7[i][0] + ns * (Mass7[(i + 1) % 8][0] - Mass7[i][0]) / Ns;
        posY = Mass7[i][1] + ns * (Mass7[(i + 1) % 8][1] - Mass7[i][1]) / Ns;

        posX2 = Mass7r[i][0] + ns * (Mass7r[(i + 1) % 8][0] - Mass7r[i][0]) / Ns;
        posY2 = Mass7r[i][1] + ns * (Mass7r[(i + 1) % 8][1] - Mass7r[i][1]) / Ns;



        myservo0.write(posX);
        myservo1.write(posY);

        myservo2.write(posX);
        myservo3.write(posY);

        myservo4.write(posX2);
        myservo5.write(posY2);


        myservo6.write(posX2);
        myservo7.write(posY2);

        if (Mode == 15)
        {
          myservo8.write(posX);
          myservo9.write(posY);

        }

      }
      else
      {
        posX = Mass7[15 - i][0] + ns * (Mass7[(15 - i - 1) % 8][0] - Mass7[15 - i][0]) / Ns;
        posY = Mass7[15 - i][1] + ns * (Mass7[(15 - i - 1) % 8][1] - Mass7[15 - i][1]) / Ns;
        posX2 = Mass7r[15 - i][0] + ns * (Mass7r[(15 - i - 1) % 8][0] - Mass7r[15 - i][0]) / Ns;
        posY2 = Mass7r[15 - i][1] + ns * (Mass7r[(15 - i - 1) % 8][1] - Mass7r[15 - i][1]) / Ns;


        myservo0.write(posX);
        myservo1.write(posY);

        myservo2.write(posX);
        myservo3.write(posY);

        myservo4.write(posX2);
        myservo5.write(posY2);

        myservo6.write(posX2);
        myservo7.write(posY2);

        if (Mode == 15)
        {
          myservo8.write(posX);
          myservo9.write(posY);

        }


      }


    }

    if (Mode == 17)
    {

      if (i < 8)
      {

        posX = Mass1[i][0] + ns * (Mass1[(i + 1) % 8][0] - Mass1[i][0]) / Ns;
        posY = Mass1[i][1] + ns * (Mass1[(i + 1) % 8][1] - Mass1[i][1]) / Ns;


        myservo8.write(posX);
        myservo9.write(posY);



      }
      else
      {
        posX = Mass1[15 - i][0] + ns * (Mass1[(15 - i - 1) % 8][0] - Mass1[15 - i][0]) / Ns;
        posY = Mass1[15 - i][1] + ns * (Mass1[(15 - i - 1) % 8][1] - Mass1[15 - i][1]) / Ns;



        myservo8.write(posX);
        myservo9.write(posY);




      }


    }
    else if (Mode == 0)
    {

      delay(100 / Ns);
    }


    if (1) // to Print
    {
      Serial.print("Mode= ");
      Serial.print(Mode);
      Serial.print(" i= \t");

      Serial.print(i);
      Serial.print(" ns=\t");
      Serial.print(ns);
      Serial.print("  Fi=\t");

      Serial.print(posX);
      Serial.print(" Psi= \t");
      Serial.print(posY);
      Serial.print("\t  Timer= ");
      Serial.print (TimerA0);
      Serial.print ("Frames = ");
      Serial.print(Ns);
      Serial.print("Swipes=");
      Serial.println(VibCount1);
    }

  }



}

