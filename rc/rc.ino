#include <Vex5.h>

Vex5_Motor motor12;
Vex5_Motor motor7;


int16_t goalSpeed = 200;


void setup() {
  Vex5.begin();
  motor12.begin(VEX5_PORT_12);
  motor7.begin(VEX5_PORT_7);

  Serial.begin(9600);
  Serial2.begin(115200); 

}


// ДВИЖЕНИЕ ПО ПОЛЮ
void forward(){
 motor12.setSpeed(-goalSpeed);
 motor7.setSpeed(goalSpeed);
}

void backward(){
  motor12.setSpeed(goalSpeed);
 motor7.setSpeed(-goalSpeed);
}

void left(){
   motor12.setSpeed(-goalSpeed);
 motor7.setSpeed(-goalSpeed);
}

void right(){
   motor12.setSpeed(goalSpeed);
 motor7.setSpeed(goalSpeed);
}

void stop(){
  motor12.setSpeed(0);
 motor7.setSpeed(0);
}


void loop() {
  if (Serial2.available()) {
    char a = Serial2.read();
    Serial.print("Received: ");
    Serial.println(a);

    switch(a) {
        case 'F': forward(); break;
        case 'B': backward();  break;
        case 'S': stop();   break;
        case 'L': left();   break;
        case 'R': right(); ; break;
        case '0': goalSpeed = 0;   break;
        case '1': goalSpeed = 600;   break;
        case '2': goalSpeed = 2000;   break;
      }



  }
}