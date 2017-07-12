
#include <EEPROM.h>
#include <BatReader.h>
#include <LedMatrix.h>
#include <Servo.h>
#include <Oscillator.h>
#include <US.h>
#include <Otto.h>
Otto Otto;

#define PIN_YL 2 //servo[2]
#define PIN_YR 3 //servo[3]
#define PIN_RL 4 //servo[4]
#define PIN_RR 5 //servo[5]

int TRIM_RR = 95;
int TRIM_RL = 4;
int TRIM_YR = 4;
int TRIM_YL = -7;


void setup() {
  Serial.begin(9600);
  Otto.init(PIN_YL,PIN_YR,PIN_RL,PIN_RR,true);
  Otto.saveTrimsOnEEPROM();
}

void loop() {
  int a = Otto.servo[0];
  
  Serial.print("Movimento ");
  Serial.print(TRIM_RR);
  Serial.print("|");
  Serial.print(TRIM_RL);
  Serial.print("|");
  Serial.print(TRIM_YR);
  Serial.print("|");
  Serial.print(TRIM_YL);
  Serial.print("\n");
  Otto.home();
  
  delay(500);
}
