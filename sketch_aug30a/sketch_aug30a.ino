#include <EEPROM.h>
#define EEPROM_ADDRESS_MAX_BRIGHTNESS 350
#define LED_PIN 10
#define POTENTIOMETER_PIN A2
#define MAX_BRIGHNTESS_DEFAULT 255

byte maxBrightness;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.setTimeout(10);
  pinMode(LED_PIN,OUTPUT);
  pinMode(POTENTIOMETER_PIN,INPUT);
  maxBrightness = EEPROM.read(EEPROM_ADDRESS_MAX_BRIGHTNESS);
  if(maxBrightness==0){
    maxBrightness = MAX_BRIGHNTESS_DEFAULT;
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()>0){
    int intValue=Serial.parseInt();
    if((intValue>= 0) && (intValue<256)){
      EEPROM.write(EEPROM_ADDRESS_MAX_BRIGHTNESS, intValue);
      maxBrightness = intValue;
    }
  }
  byte LEDBrightness = analogRead(POTENTIOMETER_PIN)/4;
  if  (LEDBrightness> maxBrightness){
    LEDBrightness=maxBrightness;
  }
  analogWrite(LED_PIN, LEDBrightness);

}
