#include "SD.h"
#define SD_ChipSelectPin 4
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm tmrpcm;

int redPin = 3;
int greenPin = 5;
int bluePin = 6;

void setup(){
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
  tmrpcm.speakerPin = 9;
  Serial.begin(9600);
  if (!SD.begin(SD_ChipSelectPin)) {
  Serial.println("SD fail");
  return;
  }

  tmrpcm.setVolume(5);
  tmrpcm.play("music.wav");
}

void loop(){
  delay(1000);
  setColor(255, 0, 0);  // red
  delay(1000);
  setColor(0, 255, 0);  // green
  delay(1000);
  setColor(0, 0, 255);  // blue
  delay(1000);
  setColor(255, 255, 0);  // yellow
  delay(1000);  
  setColor(80, 0, 80);  // purple
  delay(1000);
  setColor(255, 50, 0);  // Orange
  delay(1000);
}

void setColor(int red, int green, int blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
