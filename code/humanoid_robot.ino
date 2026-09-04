#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// MG996R pulse range
#define SERVOMIN  120
#define SERVOMAX  620

#define SERVO_FREQ 50

// Servo channels
#define HEAD_PAN        0
#define HEAD_TILT       1
#define L_SHOULDER      2
#define L_ELBOW         3
#define R_SHOULDER      4
#define R_ELBOW         5
#define L_HIP           6
#define L_KNEE          7
#define L_ANKLE         8
#define R_HIP           9
#define R_KNEE          10
#define R_ANKLE         11
#define WAIST           12

int angleToPulse(int angle) {
  return map(angle, 0, 180, SERVOMIN, SERVOMAX);
}

void moveServo(uint8_t ch, int angle) {
  pwm.setPWM(ch, 0, angleToPulse(angle));
  delay(15);   // minimal safe delay
}

// Neutral pose
void standStraight() {
  moveServo(L_HIP, 90);
  moveServo(R_HIP, 90);
  moveServo(L_KNEE, 90);
  moveServo(R_KNEE, 90);
  moveServo(L_ANKLE, 90);
  moveServo(R_ANKLE, 90);
  moveServo(WAIST, 90);
}

// Fast left step
void stepLeft() {
  moveServo(WAIST, 100);    // weight shift
  delay(40);

  moveServo(L_KNEE, 65);
  moveServo(L_HIP, 75);
  delay(60);

  moveServo(L_HIP, 90);     // forward
  delay(60);

  moveServo(L_KNEE, 90);    // down
  moveServo(WAIST, 90);
  delay(40);
}

// Fast right step
void stepRight() {
  moveServo(WAIST, 80);     // weight shift
  delay(40);

  moveServo(R_KNEE, 65);
  moveServo(R_HIP, 105);
  delay(60);

  moveServo(R_HIP, 90);     // forward
  delay(60);

  moveServo(R_KNEE, 90);    // down
  moveServo(WAIST, 90);
  delay(40);
}

void setup() {
  pwm.begin();
  pwm.setPWMFreq(SERVO_FREQ);
  delay(300);

  standStraight();
}

void loop() {
  stepLeft();
  delay(120);
  stepRight();
  delay(120);
}
