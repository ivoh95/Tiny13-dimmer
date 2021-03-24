#include <EEPROM.h>
const int led = 4;
const int power = 3;
const int plus = 2;
const int minus = 1;
const int output = 0;

const int eePower = 0;
const int eeSetting = 1; 

const int numSettings = 7;
const int clickDelay = 300; 
bool lightOn = 1; 
byte settings[numSettings]= {1,7,15,30,75,150,255};
byte setting = 0;


void setup() {

  pinMode(led, OUTPUT);
  pinMode(output, OUTPUT);
  pinMode(power, INPUT_PULLUP);
  pinMode(plus, INPUT_PULLUP);
  pinMode(minus, INPUT_PULLUP);

  if (!digitalRead(power)) {
   for (unsigned int i = 0 ; i < EEPROM.length() ; i++) {
    EEPROM.write(i, 0);
  }
  }
  
  lightOn = EEPROM.read(eePower);
  setting = EEPROM.read(eeSetting);
}

// the loop function runs over and over again forever
void loop() {

  
    if (!digitalRead(plus)) {
      if(lightOn){
        if ((setting < (numSettings - 1))) setting ++; 
      }
      else lightOn = 1;
      if (lightOn) analogWrite(output, settings[setting]);
      else analogWrite(output, 0);
       digitalWrite(led, !lightOn);
      delay(clickDelay);
      if(digitalRead(plus)){
        EEPROM.put(eePower, lightOn);
        EEPROM.put(eeSetting, setting);
      }
    }
    if (!digitalRead(minus)) {
      if(lightOn){
        if ((setting > 0)) setting --; 
        }
      else lightOn = 1;
      if (lightOn) analogWrite(output, settings[setting]);
        else analogWrite(output, 0);
        digitalWrite(led, !lightOn);
      delay(clickDelay);
      if(digitalRead(minus)){
        EEPROM.put(eePower, lightOn);
        EEPROM.put(eeSetting, setting);
      }
     
    }
  if (!digitalRead(power)) {
    lightOn = !lightOn;
    digitalWrite(led, !lightOn);
    if (lightOn) analogWrite(output, settings[setting]);
    else analogWrite(output, 0);
    
    while(!digitalRead(power)) delay(20); 
    EEPROM.put(eePower, lightOn);
  }


  
  if (lightOn) analogWrite(output, settings[setting]);
  else analogWrite(output, 0);
  digitalWrite(led, !lightOn);
}
