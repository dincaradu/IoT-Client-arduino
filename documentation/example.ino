/*
 * Credits: www.plusivo.com
 * 
 * Lesson 28: 4 Digit 7 Segment Display
 * 
 * The code below is created for the lesson "4 Digit 7 Segment Display",
 * where you will learn how to use multiple shift registers
 * to control each digit and LED of the included display.
 * 
 * Make sure you made the right connections and connected the cables
 * in the order showed in the guide.
 * 
 * More details can be found in the guide.
 */

//declare the pins used by the shift registers
const int dataPin = D8;
const int latchPin = D7;
const int clockPin = D6;

//declare a byte variable to store the current digits active
byte digit;

//create byte variables that have only one segment set to HIGH
byte a = B00000001;
byte b = B00000010;
byte c = B00000100;
byte d = B00001000;
byte e = B00010000;
byte f = B00100000;
byte g = B01000000;
byte dot = B10000000;

void setup()
{
  //set the pins used by the shift registers to output
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

//this function is used to select the digit to be turned on
void Digit(int x)
{
  //the switch statement is used to select the right digit
  switch(x)
  {
  case 1: 
    //prepare to turn on only the first digit
    digit = 14; //B00001110
    //break is used to get out from the switch function
    break;
  case 2:
    //prepare to turn on only the second digit 
    digit = 13; //B00001101
    break;
  case 3: 
    //prepare to turn on only the third digit
    digit = 11; //B00001011
    break;
  case 4: 
    //prepare to turn on only the fourth digit
    digit = 7; //B00000111
    break;
  case 5:
    //turn on all the digits
    digit = 0; //B00000000
    break;
  }
}

void loop()
{
  //call the "Digit" function in order to update 
  //the value of the "digit" variable
  Digit(5);
  //send two byte values tothe shift registers
  //after this, all the A LEDs will turn on, because
  //all the digits are turned on (they are set to LOW)
  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, digit);
  shiftOut(dataPin, clockPin, MSBFIRST, a);
  digitalWrite(latchPin, 1);
  delay(1000);

  //turn on all the B LEDs
  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, digit);
  shiftOut(dataPin, clockPin, MSBFIRST, b);
  digitalWrite(latchPin, 1);
  delay(1000);

  //turn on all the C LEDs
  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, digit);
  shiftOut(dataPin, clockPin, MSBFIRST, c);
  digitalWrite(latchPin, 1);
  delay(1000);

  //turn on all the D LEDs
  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, digit);
  shiftOut(dataPin, clockPin, MSBFIRST, d);
  digitalWrite(latchPin, 1);
  delay(1000);

  //turn on all the E LEDs
  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, digit);
  shiftOut(dataPin, clockPin, MSBFIRST, e);
  digitalWrite(latchPin, 1);
  delay(1000);

  //turn on all the F LEDs
  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, digit);
  shiftOut(dataPin, clockPin, MSBFIRST, f);
  digitalWrite(latchPin, 1);
  delay(1000);

  //turn on all the G LEDs
  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, digit);
  shiftOut(dataPin, clockPin, MSBFIRST, g);
  digitalWrite(latchPin, 1);
  delay(1000);

  //turn on the LEDs for the dots
  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, digit);
  shiftOut(dataPin, clockPin, MSBFIRST, dot);
  digitalWrite(latchPin, 1);
  delay(1000);

  //select the first digit
  Digit(1);
  //turn on the A LED on the selected digit
  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, digit);
  shiftOut(dataPin, clockPin, MSBFIRST, a);
  digitalWrite(latchPin, 1);
  delay(2000);

  //select all the digits
  Digit(5);
  //display on the selected digits a "0"
  //the LEDs for the dots are turned off
  zero_no_dot();
  delay(2000);

  //select the first digit and display on it
  //a "1" for 1 s
  //the LEDs for the dots are turned on
  Digit(1);
  one();
  delay(1000);

  //select the second digit and display on 
  //it a "2" for 1 s
  //the LEDs for the dots are turned on
  Digit(2);
  two();
  delay(1000);

  //select the third digit and display on
  //it a "3" for 1 s
  //the LEDs for the dots are turned on
  Digit(3);
  three();
  delay(1000);

  //select the last digit and display on
  //it a "4" for 1 s
  //the LEDs for the dots are turned on
  Digit(4);
  four();
  delay(1000);
}

void zero()
{
  //display on the selected digits a "0"
  //and the dots are turned on
  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, digit);
  shiftOut(dataPin, clockPin, MSBFIRST, 191); //B10111111
  digitalWrite(latchPin, 1);
}

void zero_no_dot()
{
  //display on the selected digits a "0"
  //and the dots are turned off
  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, digit);
  shiftOut(dataPin, clockPin, MSBFIRST, 63); //B00111111
  digitalWrite(latchPin, 1);
}

void one()
{
  //display on the selected digits a "1"
  //and the dots are turned on
  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, digit);
  shiftOut(dataPin, clockPin, MSBFIRST, 134); //B10000110
  digitalWrite(latchPin, 1);
}

void one_no_dot()
{
  //display on the selected digits a "1"
  //and the dots are turned off
  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, digit);
  shiftOut(dataPin, clockPin, MSBFIRST, 6); //B00000110
  digitalWrite(latchPin, 1);
}
 
void two()
{
  //display on the selected digits a "2"
  //and the dots are turned on
  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, digit);
  shiftOut(dataPin, clockPin, MSBFIRST, 219); //B11011011
  digitalWrite(latchPin, 1);
}

void two_no_dot()
{
  //display on the selected digits a "2"
  //and the dots are turned off
  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, digit);
  shiftOut(dataPin, clockPin, MSBFIRST, 91); //B01011011
  digitalWrite(latchPin, 1);
}
 
void three()
{
  //display on the selected digits a "3"
  //and the dots are turned on
  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, digit);
  shiftOut(dataPin, clockPin, MSBFIRST, 207); //B11001111
  digitalWrite(latchPin, 1);
}

void three_no_dot()
{
  //display on the selected digits a "3"
  //and the dots are turned off
  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, digit);
  shiftOut(dataPin, clockPin, MSBFIRST, 79); //B01001111
  digitalWrite(latchPin, 1);
}
 
void four()
{
  //display on the selected digits a "4"
  //and the dots are turned on
  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, digit);
  shiftOut(dataPin, clockPin, MSBFIRST, 230); //B11100110
  digitalWrite(latchPin, 1);
}

void four_no_dot()
{
  //display on the selected digits a "4"
  //and the dots are turned off
  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, digit);
  shiftOut(dataPin, clockPin, MSBFIRST, 102); //B01100110
  digitalWrite(latchPin, 1);
}
 
void five()
{
  //display on the selected digits a "5"
  //and the dots are turned on
  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, digit);
  shiftOut(dataPin, clockPin, MSBFIRST, 237); //B11101101
  digitalWrite(latchPin, 1);
}

void five_no_dot()
{
  //display on the selected digits a "5"
  //and the dots are turned off
  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, digit);
  shiftOut(dataPin, clockPin, MSBFIRST, 109); //B01101101
  digitalWrite(latchPin, 1);
}
 
void six()
{
  //display on the selected digits a "6"
  //and the dots are turned on
  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, digit);
  shiftOut(dataPin, clockPin, MSBFIRST, 253); //B11111101
  digitalWrite(latchPin, 1);
}

void six_no_dot()
{
  //display on the selected digits a "6"
  //and the dots are turned off
  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, digit);
  shiftOut(dataPin, clockPin, MSBFIRST, 125); //B01111101
  digitalWrite(latchPin, 1);
}
 
void seven()
{
  //display on the selected digits a "7"
  //and the dots are turned on
  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, digit);
  shiftOut(dataPin, clockPin, MSBFIRST, 135); //B10000111
  digitalWrite(latchPin, 1);
}

void seven_no_dot()
{
  //display on the selected digits a "7"
  //and the dots are turned off
  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, digit);
  shiftOut(dataPin, clockPin, MSBFIRST, 7); //B00000111
  digitalWrite(latchPin, 1);
}
 
void eight()
{
  //display on the selected digits a "8"
  //and the dots are turned on
  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, digit);
  shiftOut(dataPin, clockPin, MSBFIRST, 255); //B11111111
  digitalWrite(latchPin, 1);
}

void eight_no_dot()
{
  //display on the selected digits a "8"
  //and the dots are turned off
  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, digit);
  shiftOut(dataPin, clockPin, MSBFIRST, 127); //B01111111
  digitalWrite(latchPin, 1);
}
 
void nine()
{
  //display on the selected digits a "9"
  //and the dots are turned on
  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, digit);
  shiftOut(dataPin, clockPin, MSBFIRST, 239); //B11101111
  digitalWrite(latchPin, 1);
}

void nine_no_dot()
{
  //display on the selected digits a "9"
  //and the dots are turned off
  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, digit);
  shiftOut(dataPin, clockPin, MSBFIRST, 111); //B01101111
  digitalWrite(latchPin, 1);
}
