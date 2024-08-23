#include <Arduino.h>

#define LED 2

/*
void setup() {
  // Set pin mode
  pinMode(LED,OUTPUT);
}

void loop() {
  delay(500);
  digitalWrite(LED,HIGH);
  delay(500);
  digitalWrite(LED,LOW);
}
*/

#define LeftMotor1 19
#define LeftMotor2 18

#define RightMotor1 17
#define RightMotor2 16

void driveMotors(int A, int B, int duration);

void setup(void)
{
  //Motor outputs
  pinMode(LeftMotor1, OUTPUT);
  pinMode(LeftMotor2, OUTPUT);
  pinMode(RightMotor1, OUTPUT);
  pinMode(RightMotor2, OUTPUT);

  //defaulting to off
  digitalWrite(LeftMotor1, LOW);
  digitalWrite(LeftMotor2, LOW);
  digitalWrite(RightMotor1, LOW);
  digitalWrite(RightMotor2, LOW);

  Serial.begin(9600);
}

void loop(void)
{

//Start receiving instructions, wait until something comes in




// EXAMPLES:
/*
  // Increase speed
  for (int i = 0; i < 11; i++) 
  {
    driveMotors(25*i, 25*i, 500);
  }
  // fast forward.
  driveMotors(255,255,2000);

  // slow to full reverse.
  for (int i = 0; i < 21 ; i++) 
  {
    driveMotors(255 - 25*i, 255 - 25*i, 500);
  }

  // Full speed reverse.
  driveMotors(-255,-255,2000);

  // Stop.
  driveMotors(0,0,2000);

  // Full speed, forward, turn, reverse, and turn for a two-wheeled base.
  driveMotors(255, 255, 2000);
  driveMotors(0, 0, 1000);
  driveMotors(-255, 255, 2000);
  driveMotors(0, 0, 1000);
  driveMotors(-255, -255, 2000);
  driveMotors(0, 0, 1000);
  driveMotors(255, -255, 2000);
  driveMotors(0, 0, 1000);
  */
}

/// Set the current on a motor channel using PWM and directional logic.
///
/// \param pwm    PWM duty cycle ranging from -255 full reverse to 255 full forward
/// \param IN1_PIN  pin number xIN1 for the given channel
/// \param IN2_PIN  pin number xIN2 for the given channel
void set_motor_pwm(int pwm, int IN1_PIN, int IN2_PIN)
{
  if (pwm < 0) 
  {
    analogWrite(IN1_PIN, -pwm);
    digitalWrite(IN2_PIN, LOW);

  } 
  else 
  {
    digitalWrite(IN1_PIN, LOW);
    analogWrite(IN2_PIN, pwm);
  }
}

//Motor currents
/// \param A  motor A PWM, -255 to 255
/// \param B  motor B PWM, -255 to 255
void motorCurrent(int A, int B)
{
  set_motor_pwm(A, LeftMotor1, LeftMotor2);
  set_motor_pwm(B, RightMotor1, RightMotor2);


  Serial.print("motor A PWM = ");
  Serial.println(A);
  Serial.print(" motor B PWM = ");
  Serial.println(B);
}


/// \param A  motorA PWM -255 - 255
/// \param B  motorB PWM -255 - 255
/// \param duration delay in milliseconds
void driveMotors(int A, int B, int duration)
{
  motorCurrent(A, B);
  delay(duration);
}