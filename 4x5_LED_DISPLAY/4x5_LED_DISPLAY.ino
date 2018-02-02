// Written by Sai Krishna - androidwall.nrt@gmail.com date :- 01/02/2018
// for Arduino Uno

#include"Arduino.h"

int ALPHABET[][21] =   //Array of ALPHABET
 {{2,3,5,8,9,10,11,12,13,16,17,20,0},//A
  {1,2,3,5,8,9,10,11,13,16,17,18,19,0},//B
  {1,2,3,4,5,9,13,17,18,19,20,0},//C
  {1,2,3,5,8,9,12,13,16,17,18,19,0},//D
  {1,2,3,4,5,9,10,11,12,13,17,18,19,20,0},//E
  {1,2,3,4,5,9,10,11,12,13,17,0},//F
  {1,2,3,4,5,9,10,11,12,13,16,17,18,19,20,0},//G
  {1,4,5,8,9,10,11,12,13,16,17,20,0},//H
  {1,2,3,4,6,7,10,11,14,15,17,18,19,20,0},//I
  {1,2,3,4,7,11,13,15,18,19,0},//J
  {1,4,5,7,9,10,13,15,17,20,0},//K
  {1,5,9,13,17,18,19,20,0},//L
  {1,2,3,4,6,11,14,17,18,19,20,0},//M
  {1,4,5,6,8,9,11,12,13,16,17,20,0},//N
  {1,2,3,4,5,8,9,12,13,16,17,18,19,20,0},//O
  {1,2,3,4,5,8,9,10,11,12,13,17,0},//P
  {1,2,3,4,5,8,9,10,12,13,14,15,16,20,0},//Q
  {1,2,3,4,5,8,9,10,11,12,13,15,17,20,0},//R
  {1,2,3,4,5,9,10,11,12,16,17,18,19,20,0},//S
  {1,2,3,4,6,7,10,11,14,15,18,19,0},//T
  {1,4,5,8,9,12,13,16,17,18,19,20,0},//U
  {1,4,5,8,9,12,13,16,18,19,0},//V
  {1,2,3,4,7,10,15,17,18,19,20,0},//W
  {1,4,6,7,10,11,13,16,17,20,0},//X
  {1,4,5,8,10,11,14,15,18,19,0},//Y
  {1,2,3,4,7,10,13,17,18,19,20,0},//Z
  {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,0},// ALL HIGH
  {0}};

//define column and row pins here

#define column1 8
#define column2 9
#define column3 10
#define column4 11

#define column5 12 //dummy pin

#define row1 3
#define row2 4
#define row3 5
#define row4 6
#define row5 7

int row[] = {row1, row2, row3, row4, row5};
int column[] = {column1, column2, column3, column4, column5};

int charSerial = 124;

void setup() {
  Serial.begin(115200);
  for(int i = 0; i <5; i++ ){
    pinMode(row[i], OUTPUT);
    pinMode(column[i], OUTPUT);
    digitalWrite(column[i], LOW);
    digitalWrite(row[i], HIGH);
  }
}

void loop() {
  if(Serial.available() > 0){
    charSerial = Serial.read();
  }
  ledController();
}

void ledController(){
  resetAll();
  int i = 0;
  int x = 1;
  int y;
    while(ALPHABET[(charSerial-97)][i]!=0){
      while(ALPHABET[(charSerial-97)][i] > (x * 4)){
        x++;
        resetAll();
      }
      y = (ALPHABET[(charSerial-97)][i]-((x-1) * 4));
      ledActivate(x, y);
      i++;
    }
}

void ledActivate(int x, int y){
  digitalWrite(row[x-1], LOW);
  digitalWrite(column[y-1], HIGH);
}

void resetAll(){
  for(int i = 0; i <5; i++ ){
    digitalWrite(column[i], LOW);
    digitalWrite(row[i], HIGH);
  }
}
