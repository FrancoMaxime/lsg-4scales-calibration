/*
 Sketch for calibrating a rectangle 4 load cells scale.
 By: Maxime Franco, Simon De Jaeger
 Uliège
 Date: January 17th, 2021
 License: MIT License

 The goal of this sketch is to determine the calibration factors for each load cells.

 This project uses bogde's excellent library: https://github.com/bogde/HX711
 bogde's library is released under a GNU GENERAL PUBLIC LICENSE

 The HX711 does one thing well: read load cells. The breakout board is compatible with any wheat-stone bridge
 based load cell which should allow a user to measure everything from a few grams to tens of tons.
 
 scale 1:
   HX711 CLK    -> 2 
   DAT          -> 3 
   LM35 PINS    -> A1
   VCC          -> 5V
   GND          -> GND
   
 scale 2:
   HX711 CLK    -> 4 
   DAT          -> 5 
   LM35 PINS    -> A2
   VCC          -> 5V
   GND          -> GND
   
 scale 3:
   HX711 CLK    -> 6 
   DAT          -> 7 
   LM35 PINS    -> A3
   VCC          -> 5V
   GND          -> GND

 scale 4:
   HX711 CLK    -> 8
   DAT          -> 9 
   LM35 PINS    -> A4
   VCC          -> 5V
   GND          -> GND

 The HX711 board can be powered from 2.7V to 5V so the Arduino 5V power should be fine.

*/

#include "HX711.h"

HX711 scales[4];
const int LM35_PINS[] = {A1, A2, A3, A4};
const int SCALES_ID[][2] = {{3,2},{7,6},{5,4},{9,8}};
const int NB_SCALES = 4;
const long LOADCELL_DIVIDER = 5895655;
const long LOADCELL_OFFSET = 50682624;
const int CLOCK = 1000;
const float REFERENCE_WEIGHT = 1587;

long zero_factors[]= {0,0,0,0};
float actual=0;
float calibration_factors[] = {-380, -380, -385, -390};
void setup() {
  Serial.begin(115200);
  for(int i = 0; i < NB_SCALES; i++){
    scales[i].begin(SCALES_ID[i][0], SCALES_ID[i][1]);
    scales[i].set_scale(calibration_factors[i]);
    //scales[i].set_offset(LOADCELL_OFFSET);
    scales[i].tare();
    zero_factors[i] = scales[i].read_average();
  } 
}

void loop() {
  if(Serial.available()) {
    char temp = Serial.read();
    switch(temp){
      case 'a':
        calibration_factors[0] += 10;
        break;
      case 'z':
        calibration_factors[0] += 1;
        break;
      case 'e':
        calibration_factors[0] -= 1;
        break;
      case 'r':
        calibration_factors[0] -= 10;
        break;
      case 'q':
        calibration_factors[1] += 10;
        break;
      case 's':
        calibration_factors[1] += 1;
        break;
      case 'd':
        calibration_factors[1] -= 1;
        break;
      case 'f':
        calibration_factors[1] -= 10;
        break;
      case 'w':
        calibration_factors[2] += 10;
        break;
      case 'x':
        calibration_factors[2] += 1;
        break;
      case 'c':
        calibration_factors[2] -= 1;
        break;
      case 'v':
        calibration_factors[2] -= 10;
        break;
      case 't':
        calibration_factors[3] += 10;
        break;
      case 'y':
        calibration_factors[3] += 1;
        break;
      case 'u':
        calibration_factors[3] -= 1;
        break;
      case 'i':
        calibration_factors[3] -= 10;
        break;
      case '9':
        Serial.print("Doing a tare... ");
        for(int i=0; i<NB_SCALES; i++){
          scales[i].tare();
        }
        delay(CLOCK);
        Serial.println("Done");
        break;
      case '0':
        Serial.println("Printing factor... ");
        for(int i=0; i<NB_SCALES; i++){
          Serial.print("Scale ");
          Serial.print(i+1);
          Serial.print(": ");
          Serial.println(calibration_factors[i], 1);
        }
        delay(CLOCK);
        Serial.println("Done");
        break;
      
    }
    for(int i = 0; i < NB_SCALES; i++){
      scales[i].set_scale(calibration_factors[i]);
    }     
  }
  
  int temp_adc_vall[] = {0, 0, 0, 0};
  float temp_vall[] = {0, 0, 0, 0}; 
  float weights[]={0,0,0,0};
  actual=0;
  for(int i=0; i<NB_SCALES; i++){
    temp_adc_vall[i] = analogRead(LM35_PINS[i]);
    temp_vall[i] = temp_adc_vall[i] * 4.88; 
    temp_vall[i] = temp_vall[i]/10;
    weights[i] = scales[i].get_units();
    actual+= weights[i];
    
    Serial.print("Scale ");
    Serial.print(i+1);
    Serial.print(": ");
    Serial.print(weights[i], 1);
    //Serial.print("\t Temperature :");
    //Serial.print(temp_vall[i]);
    Serial.print("\t");
  }
  Serial.print("Reference weight: ");
  Serial.print(REFERENCE_WEIGHT);
  Serial.print(" gr. Actual weight: ");
  Serial.println(actual);
  
  delay(CLOCK);
}
