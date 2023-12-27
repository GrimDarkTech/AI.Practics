#include <Arduino_FreeRTOS.h>
#include <Servo.h>

#define SERVO1_PIN 2
#define SERVO2_PIN 3
#define SERVO3_PIN 5
#define SERVO4_PIN 6
#define SERVO5_PIN 7
#define SERVO6_PIN 8
#define SERVO7_PIN 9

#define STEP1 1
#define STEP2 2
#define STEP3 3
#define STEP4 1
#define STEP5 2
#define STEP6 3
#define STEP7 4

#define TIME_DELAY 50

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
Servo servo7;

// define two tasks for Blink & AnalogRead

void TaskServo1Control(void *pvParameters);
void TaskServo2Control(void *pvParameters);
void TaskServo3Control(void *pvParameters);
void TaskServo4Control(void *pvParameters);
void TaskServo5Control(void *pvParameters);
void TaskServo6Control(void *pvParameters);
void TaskServo7Control(void *pvParameters);


// the setup function runs once when you press reset or power the board
void setup() {

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  servo1.attach(SERVO1_PIN);
  servo2.attach(SERVO2_PIN);
  servo3.attach(SERVO3_PIN);
  servo4.attach(SERVO4_PIN);
  servo5.attach(SERVO5_PIN);
  servo6.attach(SERVO6_PIN);
  servo7.attach(SERVO7_PIN);

  xTaskCreate(
    TaskServo1Control, "Servo1ontrol", 128  // Stack size
    ,
    NULL, 1  // Priority
    ,
    NULL);

  xTaskCreate(
    TaskServo2Control, "Servo2control", 128  // Stack size
    ,
    NULL, 1  // Priority
    ,
    NULL);

  xTaskCreate(
    TaskServo3Control, "Servo3control", 128  // Stack size
    ,
    NULL, 1  // Priority
    ,
    NULL);

  xTaskCreate(
    TaskServo4Control, "Servo4control", 128  // Stack size
    ,
    NULL, 1  // Priority
    ,
    NULL);

  xTaskCreate(
    TaskServo5Control, "Servo5control", 128  // Stack size
    ,
    NULL, 1  // Priority
    ,
    NULL);

  xTaskCreate(
    TaskServo6Control, "Servo6control", 128  // Stack size
    ,
    NULL, 1  // Priority
    ,
    NULL);

  xTaskCreate(
    TaskServo7Control, "Servo7control", 128  // Stack size
    ,
    NULL, 1  // Priority
    ,
    NULL);
  // Now the task scheduler, which takes over control of scheduling individual tasks, is automatically started.
}

void loop() {
  // Empty. Things are done in Tasks.
}

/*--------------------------------------------------*/
/*---------------------- Tasks ---------------------*/
/*--------------------------------------------------*/


void TaskServo1Control(void *pvParameters) {
  (void)pvParameters;

  for (;;) {
    // read the input on analog pin 0:
    for (int i = 0; i < 180 / STEP1; i++) {
      servo1.write(i * STEP1);
      vTaskDelay(TIME_DELAY / portTICK_PERIOD_MS);
    }

    for (int i = 180 / STEP1; i > 0; i--) {
      servo7.write(i * STEP1);
      vTaskDelay(TIME_DELAY / portTICK_PERIOD_MS);
    }

    vTaskDelay(1);  // one tick delay (15ms) in between reads for stability
  }
}

void TaskServo2Control(void *pvParameters) {
  (void)pvParameters;

  for (;;) {
    // read the input on analog pin 0:
    for (int i = 0; i < 180 / STEP2; i++) {
      servo2.write(i * STEP2);
      vTaskDelay(TIME_DELAY / portTICK_PERIOD_MS);
    }

    for (int i = 180 / STEP2; i > 0; i--) {
      servo7.write(i * STEP2);
      vTaskDelay(TIME_DELAY / portTICK_PERIOD_MS);
    }
    vTaskDelay(1);  // one tick delay (15ms) in between reads for stability
  }
}

void TaskServo3Control(void *pvParameters) {
  (void)pvParameters;

  for (;;) {
    // read the input on analog pin 0:
    for (int i = 0; i < 180 / STEP3; i++) {
      servo3.write(i * STEP3);
      vTaskDelay(TIME_DELAY / portTICK_PERIOD_MS);
    }
    for (int i = 180 / STEP3; i > 0; i--) {
      servo7.write(i * STEP3);
      vTaskDelay(TIME_DELAY / portTICK_PERIOD_MS);
    }

    vTaskDelay(1);  // one tick delay (15ms) in between reads for stability
  }
}

void TaskServo4Control(void *pvParameters) {
  (void)pvParameters;

  for (;;) {
    // read the input on analog pin 0:
    for (int i = 0; i < 180 / STEP4; i++) {
      servo4.write(i * STEP4);
      vTaskDelay(TIME_DELAY / portTICK_PERIOD_MS);
    }
    for (int i = 180 / STEP4; i > 0; i--) {
      servo7.write(i * STEP4);
      vTaskDelay(TIME_DELAY / portTICK_PERIOD_MS);
    }

    vTaskDelay(1);  // one tick delay (15ms) in between reads for stability
  }
}

void TaskServo5Control(void *pvParameters) {
  (void)pvParameters;

  for (;;) {
    // read the input on analog pin 0:
    for (int i = 0; i < 180 / STEP5; i++) {
      servo5.write(i * STEP5);
      vTaskDelay(TIME_DELAY / portTICK_PERIOD_MS);
    }
    for (int i = 180 / STEP5; i > 0; i--) {
      servo7.write(i * STEP5);
      vTaskDelay(TIME_DELAY / portTICK_PERIOD_MS);
    }

    vTaskDelay(1);  // one tick delay (15ms) in between reads for stability
  }
}

void TaskServo6Control(void *pvParameters) {
  (void)pvParameters;

  for (;;) {
    // read the input on analog pin 0:
    for (int i = 0; i < 180 / STEP6; i++) {
      servo6.write(i * STEP6);
      vTaskDelay(TIME_DELAY / portTICK_PERIOD_MS);
    }
    for (int i = 180 / STEP6; i > 0; i--) {
      servo7.write(i * STEP6);
      vTaskDelay(TIME_DELAY / portTICK_PERIOD_MS);
    }
    vTaskDelay(1);  // one tick delay (15ms) in between reads for stability
  }
}

void TaskServo7Control(void *pvParameters) {
  (void)pvParameters;

  for (;;) {
    // read the input on analog pin 0:
    for (int i = 0; i < 180 / STEP7; i++) {
      servo7.write(i * STEP7);
      vTaskDelay(TIME_DELAY / portTICK_PERIOD_MS);
    }

    for (int i = 180 / STEP7; i > 0; i--) {
      servo7.write(i * STEP7);
      vTaskDelay(TIME_DELAY / portTICK_PERIOD_MS);
    }
    vTaskDelay(1);  // one tick delay (15ms) in between reads for stability
  }
}
