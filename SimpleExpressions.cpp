#include "Arduino.h"
#include "SimpleExpressions.h"

void SimpleExpressionsClass::init(int mouthPin, int buzzerPin) {
  mouth = Adafruit_NeoPixel(7, mouthPin, NEO_GRB + NEO_KHZ800);
  pinBuzzer = buzzerPin;
  pinMode(buzzerPin, OUTPUT);
  mouth.begin();
  mouth.show();

}

///////////////////////////////////////////////////////////////////
//-- MOUTHS  ----------------------------------------//
///////////////////////////////////////////////////////////////////


unsigned long int SimpleExpressionsClass::getAnimShape(int anim, int index){

}


void SimpleExpressionsClass::putAnimationMouth(unsigned long int aniMouth, int index){

}

void SimpleExpressionsClass::writeMouth(unsigned int mouthId){
   if(mouthId > sizeof(shapes)/sizeof(Frame*)) {
     if(debug) Serial.println('mouth does not exist');
   }
  writeMouthGeneric(shapes[mouthId].data);
}

void SimpleExpressionsClass::writeMouthGeneric(const unsigned int mouthArray[7][3]) {
  for(uint16_t i=0; i<7; i++) {
    mouth.setPixelColor(i, mouth.Color(mouthArray[i][0], mouthArray[i][1], mouthArray[i][2]));
  }
  mouth.show();
}


void SimpleExpressionsClass::clearMouth(){
  for(uint16_t i=0; i<mouth.numPixels(); i++) {
    mouth.setPixelColor(i, mouth.Color(0, 0, 0));
  }
  mouth.show();
}

///////////////////////////////////////////////////////////////////
//-- SOUNDS -----------------------------------------------------//
///////////////////////////////////////////////////////////////////

void SimpleExpressionsClass::_tone (float noteFrequency, long noteDuration, int silentDuration){

    // tone(10,261,500);
    // delay(500);
    //
    // #define anaPin 32
/*
#define digiPin 33
#define beepPin 35

int freq = 2000;
int channel = 0;
int resolution = 8;

void setup() {
pinMode(digiPin, INPUT_PULLUP);
Serial.begin(115200);

  ledcSetup(channel, freq, resolution);
  ledcAttachPin(12, channel);
    ledcWriteTone(channel, 440);
}
void loop() {
  // put your main code here, to run repeatedly:
Serial.print("AnalogValue: ");
Serial.print(analogRead(anaPin));
Serial.print(" DigitalValue: ");
Serial.println(digitalRead(digiPin));
if(!digitalRead(digiPin))ledcWrite(channel, 255);
else ledcWrite(channel, 0);


delay(50);

}


      if(silentDuration==0){silentDuration=1;}

      tone(SimpleExpressionsClass::pinBuzzer, noteFrequency, noteDuration);
      delay(noteDuration);       //milliseconds to microseconds
      //noTone(PIN_Buzzer);
      delay(silentDuration);
      */
}
/*

void SimpleE::bendTones (float initFrequency, float finalFrequency, float prop, long noteDuration, int silentDuration){

  //Examples:
  //  bendTones (880, 2093, 1.02, 18, 1);
  //  bendTones (note_A5, note_C7, 1.02, 18, 0);

  if(silentDuration==0){silentDuration=1;}

  if(initFrequency < finalFrequency)
  {
      for (int i=initFrequency; i<finalFrequency; i=i*prop) {
          _tone(i, noteDuration, silentDuration);
      }

  } else{

      for (int i=initFrequency; i>finalFrequency; i=i/prop) {
          _tone(i, noteDuration, silentDuration);
      }
  }
}


void SimpleExpressionsClass::sing(int songName){
  switch(songName){

    case S_connection:
      _tone(note_E5,50,30);
      _tone(note_E6,55,25);
      _tone(note_A6,60,10);
    break;

    case S_disconnection:
      _tone(note_E5,50,30);
      _tone(note_A6,55,25);
      _tone(note_E6,50,10);
    break;

    case S_buttonPushed:
      bendTones (note_E6, note_G6, 1.03, 20, 2);
      delay(30);
      bendTones (note_E6, note_D7, 1.04, 10, 2);
    break;

    case S_mode1:
      bendTones (note_E6, note_A6, 1.02, 30, 10);  //1318.51 to 1760
    break;

    case S_mode2:
      bendTones (note_G6, note_D7, 1.03, 30, 10);  //1567.98 to 2349.32
    break;

    case S_mode3:
      _tone(note_E6,50,100); //D6
      _tone(note_G6,50,80);  //E6
      _tone(note_D7,300,0);  //G6
    break;

    case S_surprise:
      bendTones(800, 2150, 1.02, 10, 1);
      bendTones(2149, 800, 1.03, 7, 1);
    break;

    case S_OhOoh:
      bendTones(880, 2000, 1.04, 8, 3); //A5 = 880
      delay(200);

      for (int i=880; i<2000; i=i*1.04) {
           _tone(note_B5,5,10);
      }
    break;

    case S_OhOoh2:
      bendTones(1880, 3000, 1.03, 8, 3);
      delay(200);

      for (int i=1880; i<3000; i=i*1.03) {
          _tone(note_C6,10,10);
      }
    break;

    case S_cuddly:
      bendTones(700, 900, 1.03, 16, 4);
      bendTones(899, 650, 1.01, 18, 7);
    break;

    case S_sleeping:
      bendTones(100, 500, 1.04, 10, 10);
      delay(500);
      bendTones(400, 100, 1.04, 10, 1);
    break;

    case S_happy:
      bendTones(1500, 2500, 1.05, 20, 8);
      bendTones(2499, 1500, 1.05, 25, 8);
    break;

    case S_superHappy:
      bendTones(2000, 6000, 1.05, 8, 3);
      delay(50);
      bendTones(5999, 2000, 1.05, 13, 2);
    break;

    case S_happy_short:
      bendTones(1500, 2000, 1.05, 15, 8);
      delay(100);
      bendTones(1900, 2500, 1.05, 10, 8);
    break;

    case S_sad:
      bendTones(880, 669, 1.02, 20, 200);
    break;

    case S_confused:
      bendTones(1000, 1700, 1.03, 8, 2);
      bendTones(1699, 500, 1.04, 8, 3);
      bendTones(1000, 1700, 1.05, 9, 10);
    break;

    case S_fart1:
      bendTones(1600, 3000, 1.02, 2, 15);
    break;

    case S_fart2:
      bendTones(2000, 6000, 1.02, 2, 20);
    break;

    case S_fart3:
      bendTones(1600, 4000, 1.02, 2, 20);
      bendTones(4000, 3000, 1.02, 2, 20);
    break;

  }

}
*/

SimpleExpressionsClass SimpleExpressions;
