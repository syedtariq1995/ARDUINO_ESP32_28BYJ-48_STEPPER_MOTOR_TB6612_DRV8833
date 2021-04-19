// Guide by Syed Tariq - syedtariq034@gmail.com (Pakistan) dated: 18 April 2021
// ====================================
//
//  Requirement:
//  Arduino Uno / Nano
//  Battery 3.7v, 800mAh
//  Stepper Motor 28BYJ48, 5V
//  TB6612 Motor Driver
//
//
// ====================================
//    CONNECTIONS (PINS)
//                ============
//    Arduino to Motor Driver TB6612 Module
//    
//    ARDUINO       TB6612
//    5             STDBY
//    6             ENA
//    7             ENB
//    8             B IN 2
//    9             B IN 1
//    10            A IN 2
//    11            A IN 1
//    GND           GND
//
//                ============
//    TB6612 Module to Stepper Motor 28BYJ-48 (5V)
//
//    TB6612      STEPPER MOTOR
//    VM            not connected
//    VCC           red wire
//    GND           not connected
//    AO1           blue wire
//    AO2           pink wire
//    BO2           orange wire
//    BO1           yellow wire
//    GND           GND of Arduino
// ====================================

#define STEPPER_PIN_1 8  // motor1pin1
#define STEPPER_PIN_2 9  // motor1pin2
#define STEPPER_PIN_3 10 // motor2pin1
#define STEPPER_PIN_4 11 // motor2pin2
#define stbyPin 5        // standby pin
#define enaPin 6         // motor1 enable Pin
#define enbPin 7         // motor2 enable pin

int speedValue = 255;
int delayValue = 5;
int stepsCount = 0;
int cycles = 0;

void setup() {
pinMode(STEPPER_PIN_1, OUTPUT);
pinMode(STEPPER_PIN_2, OUTPUT);
pinMode(STEPPER_PIN_3, OUTPUT);
pinMode(STEPPER_PIN_4, OUTPUT);
pinMode(stbyPin, OUTPUT);
pinMode(enaPin, OUTPUT);
pinMode(enbPin, OUTPUT);

digitalWrite(stbyPin, HIGH);
digitalWrite(enaPin, HIGH);
digitalWrite(enbPin, HIGH);

Serial.begin(9600);
}

void loop() {
  oneStepForward(delayValue);
  Serial.println("==== ==== ==== FORWARD COMMAND EXECUTED ==== ==== ====");
  delay(1000);
  
  //oneStepReverse(delayValue);
  //Serial.println("==== ==== ==== REVERSE COMMAND EXECUTED ==== ==== ====");

  Serial.println("Stopping all the motors for two seconds");
  stopAll();
}

void oneStepForward(int delayValue)
{
  for (int i = 0; i <= 512; i++)
  {
      analogWrite(enaPin, speedValue);
      digitalWrite(STEPPER_PIN_1, HIGH);
      digitalWrite(STEPPER_PIN_2, LOW);
      digitalWrite(STEPPER_PIN_3, LOW);
      digitalWrite(STEPPER_PIN_4, LOW);
      delay(delayValue);
      analogWrite(enaPin, speedValue);
      digitalWrite(STEPPER_PIN_1, LOW);
      digitalWrite(STEPPER_PIN_2, HIGH);
      digitalWrite(STEPPER_PIN_3, LOW);
      digitalWrite(STEPPER_PIN_4, LOW);
      delay(delayValue);
      analogWrite(enbPin, speedValue);
      digitalWrite(STEPPER_PIN_1, LOW);
      digitalWrite(STEPPER_PIN_2, LOW);
      digitalWrite(STEPPER_PIN_3, HIGH);
      digitalWrite(STEPPER_PIN_4, LOW);
      delay(delayValue);
      analogWrite(enbPin, speedValue);
      digitalWrite(STEPPER_PIN_1, LOW);
      digitalWrite(STEPPER_PIN_2, LOW);
      digitalWrite(STEPPER_PIN_3, LOW);
      digitalWrite(STEPPER_PIN_4, HIGH);
      delay(delayValue);
      stepsCount++;
      
      if(stepsCount == 512)
      {
        cycles++;
        stepsCount = 0;
      }
  }
}


void oneStepReverse(int delayValue)
{
  for (int i = 0; i <= 512; i++)
  {
      analogWrite(enbPin, speedValue);
      digitalWrite(STEPPER_PIN_1, LOW);
      digitalWrite(STEPPER_PIN_2, LOW);
      digitalWrite(STEPPER_PIN_3, LOW);
      digitalWrite(STEPPER_PIN_4, HIGH);
      delay(delayValue);
      analogWrite(enbPin, speedValue);
      digitalWrite(STEPPER_PIN_1, LOW);
      digitalWrite(STEPPER_PIN_2, LOW);
      digitalWrite(STEPPER_PIN_3, HIGH);
      digitalWrite(STEPPER_PIN_4, LOW);
      delay(delayValue);
      analogWrite(enaPin, speedValue);
      digitalWrite(STEPPER_PIN_1, LOW);
      digitalWrite(STEPPER_PIN_2, HIGH);
      digitalWrite(STEPPER_PIN_3, LOW);
      digitalWrite(STEPPER_PIN_4, LOW);
      delay(delayValue);
      analogWrite(enaPin, speedValue);
      digitalWrite(STEPPER_PIN_1, HIGH);
      digitalWrite(STEPPER_PIN_2, LOW);
      digitalWrite(STEPPER_PIN_3, LOW);
      digitalWrite(STEPPER_PIN_4, LOW);
      delay(delayValue);
      stepsCount++;
      
    if(stepsCount == 512)
    {
      cycles++;
      stepsCount = 0;
    }
  }
}

void stopAll()
{
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  delay(5000);
}
