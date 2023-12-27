#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
Servo servo7;

#define SERVO1_PIN 2
#define SERVO2_PIN 3
#define SERVO3_PIN 5
#define SERVO4_PIN 6
#define SERVO5_PIN 7
#define SERVO6_PIN 8
#define SERVO7_PIN 9

#define STEP 5

void setup() {
  servo1.attach(SERVO1_PIN);
  servo2.attach(SERVO2_PIN);
  servo3.attach(SERVO3_PIN);
  servo4.attach(SERVO4_PIN);
  servo5.attach(SERVO5_PIN);
  servo6.attach(SERVO6_PIN);
  servo7.attach(SERVO7_PIN);
}
void loop() {
  for (int i = 0; i < 180/STEP; i++) {
    servo1.write(i*STEP);
    servo2.write(i*STEP);
    servo3.write(i*STEP);
    servo4.write(i*STEP);
    servo5.write(i*STEP);
    servo6.write(i*STEP);
    servo7.write(i*STEP);
    delay(10);
  }
  for (int i = 180; i > 0; i--) {
    servo1.write(i*STEP);
    servo2.write(i*STEP);
    servo3.write(i*STEP);
    servo4.write(i*STEP);
    servo5.write(i*STEP);
    servo6.write(i*STEP);
    servo7.write(i*STEP);
    delay(10);
  }
}