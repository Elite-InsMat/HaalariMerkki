#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include <stdlib.h>
#include <time.h>
#include "BluetoothSerial.h"
#include "globals.hpp"

//New screens here
#include "einsmatScroll.hpp"
#include "mikagunspin.hpp"
#include "mikabounce.hpp"

char screen = '0';

BluetoothSerial SerialBT;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {

  //Begin comunication at baud tate of 115200
  Serial.begin(115200);

  //Begin BT broadcasting
  SerialBT.begin("ESP32test");

  //Init display ports 5 and 4
  Wire.begin(5, 4);

  //Set display parameters
  display.setCursor(0, 10);
  display.setTextColor(1);
  display.setTextSize(4);
  display.setTextWrap(0);

  //Init rand
  srand (time(NULL));

  //Display init check
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C, false, false)) {
  Serial.println(F("SSD1306 allocation failed"));
  for(;;);
  }

  //Setup screens
  insmat_scroll_setup();
}

void loop() {
  if(SerialBT.available())
  {
    char incomingChar = SerialBT.read();
    if(incomingChar == '0' || incomingChar == '1' || incomingChar == '2')
    {
      screen = incomingChar;
      display.setRotation(0); //Clear rotation
    }
    Serial.write(screen);
  }
  switch (screen-'0')
  {
  case 0:
  insmat_scroll_loop();
    break;
  case 1:
  mikagun_loop();
    break;
  case 2:
  mikabounce_loop();
    break;
  default:
  screen = '0';
    break;
  }
}