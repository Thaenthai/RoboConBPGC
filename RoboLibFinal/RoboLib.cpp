#include "Arduino.h"
#include "RoboLib.h"
#include "PS2X_lib.h"
#include "SabertoothSimplified.h"

char mode = 'E';    //Seesaw, Pole walk, Swing, Jungle gym, Run, Drive adjust
bool registers[8];

//******************** PS2 controller ********************//
int error = 0; 
byte type = 0;
byte vibrate = 0;
PS2X ps2x; // create PS2 Controller Class
//**********************************************************************//

/*
Configure pins of arduino as either INPUT/OUTPUT and initialize them as either HIGH/LOW. Comment out pins not in use.
*/
void arduConfig()
{
    pinMode(pin1,OUTPUT);
    pinMode(pin2,OUTPUT);
    pinMode(pin3,OUTPUT);
    pinMode(pin4,OUTPUT);
    pinMode(pin5,OUTPUT);
    pinMode(pin6,OUTPUT);
    pinMode(pin7,OUTPUT);
    pinMode(pin8,OUTPUT);
    pinMode(pin9,OUTPUT);
    pinMode(pin10,OUTPUT);
    pinMode(pin11,OUTPUT);
    pinMode(pin12,OUTPUT);
    pinMode(pin13,OUTPUT);
    pinMode(pin14,OUTPUT);
    pinMode(pin15,OUTPUT);
    pinMode(pin16,OUTPUT);
    pinMode(pin17,OUTPUT);
    pinMode(pin18,OUTPUT);
    pinMode(pin19,OUTPUT);
    pinMode(pin20,OUTPUT);
    pinMode(pin21,OUTPUT);
    pinMode(pin22,OUTPUT);
    pinMode(pin23,OUTPUT);
    pinMode(pin24,OUTPUT);
    pinMode(pin25,OUTPUT);
    pinMode(pin26,OUTPUT);
    pinMode(pin27,OUTPUT);
    pinMode(pin28,OUTPUT);
    pinMode(pin29,OUTPUT);
    pinMode(pin30,OUTPUT);
    pinMode(pin31,OUTPUT);
    pinMode(pin32,OUTPUT);
    pinMode(pin33,OUTPUT);
    pinMode(pin34,OUTPUT);
    pinMode(pin35,OUTPUT);
    pinMode(pin36,OUTPUT);
    pinMode(pin37,OUTPUT);
    pinMode(pin38,OUTPUT);
    pinMode(pin39,OUTPUT);
    pinMode(pin40,OUTPUT);
    pinMode(pin41,OUTPUT);
    pinMode(pin42,OUTPUT);
    pinMode(pin43,OUTPUT);
    pinMode(pin44,OUTPUT);
    pinMode(pin45,OUTPUT);
    pinMode(pin46,OUTPUT);
    pinMode(pin47,OUTPUT);
    pinMode(pin48,OUTPUT);
    pinMode(pin49,OUTPUT);
    pinMode(pin50,OUTPUT);
    pinMode(pin51,OUTPUT);
    pinMode(pin52,OUTPUT);
    pinMode(pin53,OUTPUT);
    pinMode(pin54,OUTPUT);
    
    digitalWrite(pin1,HIGH);
    digitalWrite(pin2,HIGH);
    digitalWrite(pin3,HIGH);
    digitalWrite(pin4,HIGH);
    digitalWrite(pin5,HIGH);
    digitalWrite(pin6,HIGH);
    digitalWrite(pin7,HIGH);
    digitalWrite(pin8,HIGH);
    digitalWrite(pin9,HIGH);
    digitalWrite(pin10,HIGH);
    digitalWrite(pin11,HIGH);
    digitalWrite(pin12,HIGH);
    digitalWrite(pin13,HIGH);
    digitalWrite(pin14,HIGH);
    digitalWrite(pin15,HIGH);
    digitalWrite(pin16,HIGH);
    digitalWrite(pin17,HIGH);
    digitalWrite(pin18,HIGH);
    digitalWrite(pin19,HIGH);
    digitalWrite(pin20,HIGH);
    digitalWrite(pin21,HIGH);
    digitalWrite(pin22,HIGH);
    digitalWrite(pin23,HIGH);
    digitalWrite(pin24,HIGH);
    digitalWrite(pin25,HIGH);
    digitalWrite(pin26,HIGH);
    digitalWrite(pin27,HIGH);
    digitalWrite(pin28,HIGH);
    digitalWrite(pin29,HIGH);
    digitalWrite(pin30,HIGH);
    digitalWrite(pin31,HIGH);
    digitalWrite(pin32,HIGH);
    digitalWrite(pin33,HIGH);
    digitalWrite(pin34,HIGH);
    digitalWrite(pin35,HIGH);
    digitalWrite(pin36,HIGH);
    digitalWrite(pin37,HIGH);
    digitalWrite(pin38,HIGH);
    digitalWrite(pin39,HIGH);
    digitalWrite(pin40,HIGH);
    digitalWrite(pin41,HIGH);
    digitalWrite(pin42,HIGH);
    digitalWrite(pin43,HIGH);
    digitalWrite(pin44,HIGH);
    digitalWrite(pin45,HIGH);
    digitalWrite(pin46,HIGH);
    digitalWrite(pin47,HIGH);
    digitalWrite(pin48,HIGH);
    digitalWrite(pin49,HIGH);
    digitalWrite(pin50,HIGH);
    digitalWrite(pin51,HIGH);
    digitalWrite(pin52,HIGH);
    digitalWrite(pin53,HIGH);
    digitalWrite(pin54,HIGH);
}

void PS2_setup()
{
  error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_ATTN, PS2_DAT, pressures, rumble);
  if(error == 0) Serial.println("Found Controller, configured successful");
  else if(error == 1) Serial.println("No controller found, check wiring, see readme.txt to enable debug. visit www.billporter.info for troubleshooting tips");
  else if(error == 2) Serial.println("Controller found but not accepting commands. see readme.txt to enable debug. Visit www.billporter.info for troubleshooting tips");
  else if(error == 3) Serial.println("Controller refusing to enter Pressures mode, may not support it. ");
  type = ps2x.readType(); 
     switch(type) {
       case 0:
        Serial.println("Unknown Controller type");
       break;
       case 1:
        Serial.println("DualShock Controller Found");
       break;
       case 2:
         Serial.println("GuitarHero Controller Found");
       break;
     }
}
     
/////******************************************************************************************/////
void clearRegisters(){
  for(int i = 7; i>=0; i--){
     registers[i] = HIGH;
  }
}
////////////////////////////////////////////////////////////////////////////////////////////////////

/////******************************************************************************************/////
void setRegisterPin(int index, int value){
  registers[index-1] = value;
}
////////////////////////////////////////////////////////////////////////////////////////////////////

/////******************************************************************************************/////
void writeRegisters(){
  digitalWrite(RCLK_Pin, LOW);
  for(int i = 7; i>=0; i--){
    digitalWrite(SRCLK_Pin, LOW);
    
    int val = registers[i];
    digitalWrite(SER_Pin, val);
    
    digitalWrite(SRCLK_Pin, HIGH);
  }
  digitalWrite(RCLK_Pin, HIGH);
}
////////////////////////////////////////////////////////////////////////////////////////////////////

/////******************************************************************************************/////
void setModeLED(char modeLED)
{
  if(modeLED=='A'){
  setRegisterPin(1, LOW);
  setRegisterPin(2, HIGH);
  setRegisterPin(3, HIGH);
  setRegisterPin(4, HIGH);
  setRegisterPin(5, HIGH);
  setRegisterPin(6, HIGH);
  setRegisterPin(7, HIGH);
  setRegisterPin(8, HIGH);
  writeRegisters();
  }
  else if(modeLED=='B'){
  setRegisterPin(1, HIGH);
  setRegisterPin(2, LOW);
  setRegisterPin(3, HIGH);
  setRegisterPin(4, HIGH);
  setRegisterPin(5, HIGH);
  setRegisterPin(6, HIGH);
  setRegisterPin(7, HIGH);
  setRegisterPin(8, HIGH);
  writeRegisters();
  }
  else if(modeLED=='C'){
  setRegisterPin(1, HIGH);
  setRegisterPin(2, HIGH);
  setRegisterPin(3, LOW);
  setRegisterPin(4, HIGH);
  setRegisterPin(5, HIGH);
  setRegisterPin(6, HIGH);
  setRegisterPin(7, HIGH);
  setRegisterPin(8, HIGH);
  writeRegisters();
  }
  else if(modeLED=='D'){
  setRegisterPin(1, HIGH);
  setRegisterPin(2, HIGH);
  setRegisterPin(3, HIGH);
  setRegisterPin(4, LOW);
  setRegisterPin(5, HIGH);
  setRegisterPin(6, HIGH);
  setRegisterPin(7, HIGH);
  setRegisterPin(8, HIGH);
  writeRegisters();
  }
  else if(modeLED=='E'){
  setRegisterPin(1, HIGH);
  setRegisterPin(2, HIGH);
  setRegisterPin(3, HIGH);
  setRegisterPin(4, HIGH);
  setRegisterPin(5, LOW);
  setRegisterPin(6, HIGH);
  setRegisterPin(7, HIGH);
  setRegisterPin(8, HIGH);
  writeRegisters();
  }
  else if(modeLED=='F'){
  setRegisterPin(1, HIGH);
  setRegisterPin(2, HIGH);
  setRegisterPin(3, HIGH);
  setRegisterPin(4, HIGH);
  setRegisterPin(5, HIGH);
  setRegisterPin(6, LOW);
  setRegisterPin(7, HIGH);
  setRegisterPin(8, HIGH);
  writeRegisters();
  }
}
////////////////////////////////////////////////////////////////////////////////////////////////////

/////******************************************************************************************/////
void ssLoop()
{
    setModeLED('A');
}
////////////////////////////////////////////////////////////////////////////////////////////////////

/////******************************************************************************************/////
void poleLoop()
{
  setModeLED('B');
}
////////////////////////////////////////////////////////////////////////////////////////////////////

/////******************************************************************************************/////
void swingLoop()
{
  setModeLED('C');
}
////////////////////////////////////////////////////////////////////////////////////////////////////

/////******************************************************************************************/////
void gymLoop()
{
  setModeLED('D');
}
////////////////////////////////////////////////////////////////////////////////////////////////////

/////******************************************************************************************/////
void runLoop()
{
  setModeLED('E');
}
////////////////////////////////////////////////////////////////////////////////////////////////////

/////******************************************************************************************/////
void adjLoop()
{
  setModeLED('F');
}
////////////////////////////////////////////////////////////////////////////////////////////////////
