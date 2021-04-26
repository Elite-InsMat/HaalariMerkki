#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include <stdlib.h>
#include <time.h>
#include "globals.hpp"
#include "BluetoothSerial.h"

int r_counter = 0;
int b_counter = 0;

void insmat_scroll_setup() {
}

void insmat_scroll_loop() {

  display.clearDisplay();
  display.setCursor(b_counter, 16);
  
  // Draw bitmap on the screen
  display.printf("Elite InsMat");
  display.display();
  b_counter--;
  if(b_counter <= -290){
    b_counter = 128;
  }
}