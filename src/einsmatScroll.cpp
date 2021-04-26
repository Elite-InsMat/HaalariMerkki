#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include <stdlib.h>
#include <time.h>
#include "globals.hpp"
#include "BluetoothSerial.h"

//init local variables
static int b_counter = 0;

void insmat_scroll_loop() {

  display.clearDisplay();
  display.setCursor(b_counter, 16);
  display.printf("Elite InsMat");
  display.display();

  b_counter--;

  if(b_counter <= -290){
    b_counter = 128;
  }
}