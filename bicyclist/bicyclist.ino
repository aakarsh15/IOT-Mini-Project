#include "LedControl.h"
#include "binary.h"

/*
 DIN connects to pin 12
 CLK connects to pin 11
 CS connects to pin 10 
*/
LedControl lc=LedControl(12,11,10,1);
#define IR1_Sensor 7 
#define IR2_Sensor 8 
int IR1; 
int IR2;

// delay time between faces
unsigned long delaytime=600;
int bdelay=200;
// flashing light
byte blk[8]= {B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111};
byte nblk[8]= {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};
// left arrow
byte la[8]={B00001110, B00011100,B00111000,B01110000,B01110000,B00111000,B00011100,B00001110};
// right arrow
byte ra[8]= {B01110000,B00111000,B00011100,B00001110,B00001110,B00011100,B00111000,B01110000};

void setup() {
  pinMode(IR1_Sensor, INPUT);
  pinMode(IR2_Sensor, INPUT);
  lc.shutdown(0,false);
  // Set brightness to a medium value
  lc.setIntensity(0,8);
  // Clear the display
  lc.clearDisplay(0);  
}

void loop(){
 IR1=digitalRead(IR1_Sensor);  //digital read function to check IR pin status/
 IR2=digitalRead(IR2_Sensor);
  if(IR1==LOW)              //If sensor detect any reflected ray/
  {
      for(int i=0;i<=8;i++)
      {
        rightarrow();
      }  
  }
  else if(IR2==LOW)               //If sensor detect any reflected ray/
  {
      for(int i=0;i<=8;i++)
      {
        leftarrow();
      }  
  }
  else 
  {
       blink();       
  }

}

void rightarrow()
{
  // Display sad face
  lc.setRow(0,0,ra[0]);
  lc.setRow(0,1,ra[1]);
  lc.setRow(0,2,ra[2]);
  lc.setRow(0,3,ra[3]);
  lc.setRow(0,4,ra[4]);
  lc.setRow(0,5,ra[5]);
  lc.setRow(0,6,ra[6]);
  lc.setRow(0,7,ra[7]);
  delay(delaytime);
  lc.setRow(0,0,nblk[0]);
  lc.setRow(0,1,nblk[1]);
  lc.setRow(0,2,nblk[2]);
  lc.setRow(0,3,nblk[3]);
  lc.setRow(0,4,nblk[4]);
  lc.setRow(0,5,nblk[5]);
  lc.setRow(0,6,nblk[6]);
  lc.setRow(0,7,nblk[7]); 
  delay(bdelay);
}
void leftarrow()
{  
  // Display neutral face
  lc.setRow(0,0,la[0]);
  lc.setRow(0,1,la[1]);
  lc.setRow(0,2,la[2]);
  lc.setRow(0,3,la[3]);
  lc.setRow(0,4,la[4]);
  lc.setRow(0,5,la[5]);
  lc.setRow(0,6,la[6]);
  lc.setRow(0,7,la[7]);
  delay(delaytime);
  lc.setRow(0,0,nblk[0]);
  lc.setRow(0,1,nblk[1]);
  lc.setRow(0,2,nblk[2]);
  lc.setRow(0,3,nblk[3]);
  lc.setRow(0,4,nblk[4]);
  lc.setRow(0,5,nblk[5]);
  lc.setRow(0,6,nblk[6]);
  lc.setRow(0,7,nblk[7]); 
  delay(bdelay);
} 
void blink()
{
  // Display happy face
  lc.setRow(0,0,blk[0]);
  lc.setRow(0,1,blk[1]);
  lc.setRow(0,2,blk[2]);
  lc.setRow(0,3,blk[3]);
  lc.setRow(0,4,blk[4]);
  lc.setRow(0,5,blk[5]);
  lc.setRow(0,6,blk[6]);
  lc.setRow(0,7,blk[7]);
  delay(bdelay);
  lc.setRow(0,0,nblk[0]);
  lc.setRow(0,1,nblk[1]);
  lc.setRow(0,2,nblk[2]);
  lc.setRow(0,3,nblk[3]);
  lc.setRow(0,4,nblk[4]);
  lc.setRow(0,5,nblk[5]);
  lc.setRow(0,6,nblk[6]);
  lc.setRow(0,7,nblk[7]); 
  delay(bdelay);
}