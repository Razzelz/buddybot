//Remote control
#include<Arduino.h>
#include<IRremote.h>
#define IR_RECEIVE_PIN 11

int motor1pin1 = 4;
int motor1pin2 = 5;

int motor2pin1 = 8;
int motor2pin2 = 9;

void setup () {
  
  Serial.begin (115200);
  
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK, USE_DEFAULT_FEEDBACK_LED_PIN);
  Serial.print(F("Ready to receive IR signals at pin "));
  Serial.println(IR_RECEIVE_PIN);

  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
}


void loop() {
  if (IrReceiver.decode()) {
    IrReceiver.printIRResultShort(&Serial);
    if (IrReceiver.decodedIRData.protocol == UNKNOWN) {
      IrReceiver.printIRResultRawFormatted(&Serial, true);
    }

    switch(IrReceiver.decodedIRData.command) {
      case 0x18 :
      Serial.println ("Move Forward");
      Forward();
      break;
      case 0x52:
      Serial.println("Move Backward");
      Backward();
      break;
      case 0x8:
      Serial.println("Turn Left");
      Left();
      break;
      case 0x5A:
      Serial.println("Turn Right");
      Right();
      break;
      case 0x1C:
      Serial.println("Stop");
      Stop();
      break;
    }
    
  Serial.println();
  IrReceiver.resume();
  }
}

void Left() {
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
}

void Right() {
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
}

void Forward() {
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
}

void Backward() {
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
}

void Stop() {
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
}
