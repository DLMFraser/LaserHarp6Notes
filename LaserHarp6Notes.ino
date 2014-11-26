/*
  Program Name: LaserHarp Six Notes
  Purpose:
    - Main project for CS 207
    - Detect Light and play a tone under
      the condition that not enough 
      light is present
    - Will play notes from a pentatonic
      scale
  Circuit:
    - An Arduino Uno R3 supplies 5V to the voltage dividers
      used to detect light. It will also supply 3.3V to six
      LASER modules that will always be on when power is
      supplied to the Arduino.
    - A0 is hooked up to a voltage divider with a photoresistor
      and a 100k resistor
    - A1 is hooked up to a voltage divider with a photoresistor
      and a 100k resistor
    - A2 is hooked up to a voltage divider with a photoresistor
      and a 100k resistor
    - A3 is hooked up to a voltage divider with a photoresistor
      and a 100k resistor
    - A4 is hooked up to a voltage divider with a photoresistor
      and a 100k resistor
    - A5 is hooked up to a voltage divider with a photoresistor
      and a 100k resistor
    - A piezo is hooked up to pin 11 (PWM~)
  Based on: LaserHarp Two Notes
  Written By: James Spaleta and Destinee Fraser on 26/11/2014 (DD/MM/YYYY)
  Last Updated: 26/11/2014 (DD/MM/YYYY)
*/

//Sensor Pin
const int sensor0 = A0; //Analog-in pins A0-A5
                        //Will be used to
                        //Detect light
const int sensor1 = A1; 
const int sensor2 = A2; 
const int sensor3 = A3;
const int sensor4 = A4;
const int sensor5 = A5;
//Speaker Pin
int speaker = 11;//Speaker is on pin
                  //11 as it must be 
                  //On a PWM~ pin to use
                  //The tone function
//Light Threashold
const int lightThreashold = 10;   //Will play audio when there
                                  //Is a lower reading than
                                  //This from the light sensor
void setup()
{
  pinMode(sensor0, INPUT);
  pinMode(speaker, OUTPUT);
  Serial.begin(9600); //Begin serial communication
                      //At 9600 baud for use in 
                      //Calibration of the sensor
}

void loop()
{
  //Read first sensor
  int lightLevel = analogRead(sensor0); //low number means more light
  Serial.println(lightLevel); //for calibration purposes only
  while(lightLevel > lightThreashold) //While loop will prevent other tones from being played
  {
    tone(speaker, 277); // plays C#
    lightLevel = analogRead(sensor0);
  }
  noTone(speaker); //Ensures the tone stops 
                   
  //Read next sensor                 
  lightLevel = analogRead(sensor1);
  Serial.println(lightLevel);
  while(lightLevel > lightThreashold)
  {
    tone(speaker, 311); // plays D#
    lightLevel = analogRead(sensor1);
  }
  noTone(speaker);
  
  //Read next sensor
  lightLevel = analogRead(sensor2);
  Serial.println(lightLevel);
  while(lightLevel > lightThreashold)
  {
    tone(speaker, 370); //plays F#
    lightLevel = analogRead(sensor2);
  }
  noTone(speaker);
  
  //Read next sensor
  lightLevel = analogRead(sensor3);
  Serial.println(lightLevel);
  while(lightLevel > lightThreashold)
  {
    tone(speaker, 415); //plays G#
    lightLevel = analogRead(sensor3);
  }
  noTone(speaker);
  
  //Read next sensor
  lightLevel = analogRead(sensor4);
  Serial.println(lightLevel);
  while(lightLevel > lightThreashold)
  {
    tone(speaker, 466); //plays A#
    lightLevel = analogRead(sensor4);
  }
  noTone(speaker);
  
  //Read next sensor
  lightLevel = analogRead(sensor5);
  Serial.println(lightLevel);
  while(lightLevel > lightThreashold)
  {
    tone(speaker, 554); //plays high C#
    lightLevel = analogRead(sensor5);
  }
  noTone(speaker);
  //Read first sensor
}
