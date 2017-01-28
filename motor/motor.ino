/*
 Motor
 Runs a motor both directions at various speeds.
*/

#include "continous_servo_motor_driver.h"
int motorPin = 8;
UsefulDrivers::ContinousServoMotorDriver *driver = new UsefulDrivers::ContinousServoMotorDriver(motorPin);
// the setup function runs once when you press reset or power the board
void setup()
{
    // initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
    // put your setup code here, to run once:
    driver->init();
}
// the loop function runs over and over again forever
void loop()
{
    // put your main code here, to run repeatedly:
    driver->setSpeed(255);
    Serial.println("Going forward at max speed for 3000ms");
    delay(3000);

    driver->setSpeed(0);
    Serial.println("Stopped for 1000ms");
    delay(1000);

    driver->setSpeed(-255/2);
    Serial.println("Going backward at HALF a speed for 3000ms");
    delay(3000);

    driver->setSpeed(0);
    Serial.println("Stopped for 500ms");
    delay(500);
    // wait for 30 milliseconds
}
