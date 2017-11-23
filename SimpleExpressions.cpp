#include "Arduino.h"
#include "SimpleExpressions.h"

void SimpleExpressionsClass::init(int mouthPin, int buzzerPin) {
  mouth = Adafruit_NeoPixel(7, mouthPin, NEO_GRB + NEO_KHZ800);
  mouth.begin();
  mouth.show();

  pinBuzzer = buzzerPin;
  pinMode(buzzerPin, OUTPUT);

  int freq = 2000;
  int channel = 1;
  int resolution = 8;
  ledcSetup(1, freq, resolution);
  ledcAttachPin(buzzerPin, 1);
}

///////////////////////////////////////////////////////////////////
//-- MOUTHS  ----------------------------------------//
///////////////////////////////////////////////////////////////////

/*
void SimpleExpressionsClass::putAnimationMouth(int aniMouth, int index){

}
*/


void SimpleExpressionsClass::writeMouth(char mouthName[], int r, int g, int b){
  int number = -1;
    for(int i = 0; i < frameCount; i++){
      if(strncmp(shapes[i].name, mouthName, 20) == 0) {
        number = i;
        break;
      }
    }
    if(number != -1){
      printMouth(number, r, g, b);
    } else {
      if(debug) Serial.println("Error: mouth name does not exist");
    }
}

void SimpleExpressionsClass::printMouth(int number, int r, int g, int b) {
  for(uint16_t i = 0; i<7; i++) {
    if(shapes[number].data[i]) mouth.setPixelColor(i, mouth.Color(r, g, b));
    else mouth.setPixelColor(i, 0);
  }
  mouth.show();
}

void SimpleExpressionsClass::writeMouth(char mouthName[] ){
  int number = -1;
    for(int i = 0; i < colorFrameCount; i++){
      if(strncmp(shapes[i].name, mouthName, 20) == 0) {
        number = i;
        break;
      }
    }
    if(number != -1){
      printMouth(number);
    } else {
      if(debug) Serial.println("Error: mouth name does not exist");
    }
}

void SimpleExpressionsClass::printMouth(int number) {
  for(uint16_t i = 0; i<7; i++) {
    mouth.setPixelColor(i, mouth.Color(colorShapes[number].data[i][0], colorShapes[number].data[i][1], colorShapes[number].data[i][2]));
  }
  mouth.show();
}


void SimpleExpressionsClass::writeMouthGeneric(const bool mouthArray[7], int r, int g, int b) {
  for(uint16_t i=0; i<7; i++) {
    if(mouthArray[i]) mouth.setPixelColor(i, mouth.Color(r, g, b));
    else mouth.setPixelColor(i, 0);
  }
  mouth.show();
}

void SimpleExpressionsClass::writeMouthGeneric(const int mouthArray[7][3]) {
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
    if(silentDuration==0){silentDuration=1;}

    ledcWriteTone(0, noteFrequency);
    ledcWrite(1, 255);
    delay(noteDuration);       //milliseconds to microseconds
    //ledcWrite(0, 0); // notone
    delay(silentDuration);
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
