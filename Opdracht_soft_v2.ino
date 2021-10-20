#include <runtimer.h>                               //Library for the timer
 
#define led 9                                       //Pin 9 is the led
#define sensor A0                                   //Pin A0 is the sensor

intervalTimer timer1(2000);                         //Timer with an interval of 2000ms

int input;                                          //Var for the input of the senor
byte sensorHigh = 255;                              //Var for the max value of the sensor

void setup() 
{
  pinMode(sensor, INPUT);                           //Declare sensor as input
  pinMode(led, OUTPUT);                             //Declare led as output
  Serial.begin(9600);                               //Declare the speed of the Serial monitor
  Serial.flush();                                   //Waits for the transmission of outgoing serial data to complete
}

void loop() 
{
  input = map(analogRead(sensor), 0, 1023, 0, 255); //Convert the input of the sensor of 0 - 1023 to 0 - 255
  analogWrite(led,(sensorHigh-input));              //Write the input to the led
  if (timer1.expired())                             //When 2 seconds have past
  {
    Serial.print("The input is: ");                 //Print the input
    Serial.println(input);
  }
}
