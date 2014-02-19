#include <Shieldbot.h>

Shieldbot shieldbot = Shieldbot();
int S1,S2,S3,S4,S5;	//values to store state of sensors

void setup(){
  Serial.begin(9600);
  shieldbot.setMaxSpeed(50
  );//255 is max
}



void go_forward() {
  shieldbot.drive(100,100);
}

void go_stop() {
  shieldbot.drive(0,0);
}

void go_left() {
  shieldbot.drive(-100,100);
}

void go_right() {
  shieldbot.drive(100,-100);
}

void go_backward() {
  shieldbot.drive(-100,-100);
}

void loop(){
  S3 = shieldbot.readS3();
  S1 = shieldbot.readS1();
  S5 = shieldbot.readS5();
 
 
 go_forward();
 
 if (S5 == 1) {
  
   go_stop();
   delay(500);
   go_right();
   delay(165); 
 }
 
 if (S1 == 1) {
  go_stop();
  go_left();
  delay(165); 
 }
 
}
