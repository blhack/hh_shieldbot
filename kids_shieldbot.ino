#include <Shieldbot.h>
 
Shieldbot shieldbot = Shieldbot();
int S1,S2,S3,S4,S5;	//values to store state of sensors
 
void setup(){
  Serial.begin(9600);
  shieldbot.setMaxSpeed(60);//255 is max
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
  S2 = shieldbot.readS2();
  S4 = shieldbot.readS4();
  S5 = shieldbot.readS5();
  int wait_time = 100;
 
 if ((S1 == 1) && (S2 == 0) && (S3 == 0) && (S4 == 0) && (S5 == 0)){
   go_forward();
   delay(wait_time);
 }
 
 if ((S1 == 0) && (S2 == 0) && (S3 == 0) && (S4 == 0) && (S5 == 0)) {
   go_right();
   delay(wait_time);
   
 }
 
 if ((S1 == 1) && (S2 == 1) && (S3 == 1) && (S4 == 1) && (S5 == 0)) {
   go_left();
   delay(wait_time);
 }
 
 if ((S1 == 1) && (S2 == 1)) {
   go_left();
   delay(wait_time);
 }
 
 if ((S1 == 1) && (S2 == 1) && (S3 == 1) && (S4 == 0) && (S5 == 0)) {
   go_left();
   delay(wait_time);
   go_forward();
   delay(wait_time);
 }
 
 Serial.println(S1);
}
