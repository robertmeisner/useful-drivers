/*
 Distance
 Reads a distance, prints the result to the serial monitor
*/

#include "hc_sr04_distance_sensor_driver.h"
int trigPin = 2;
int echoPin = 4;
UsefulDrivers::HC04DistanceSensorDriver *driver = new UsefulDrivers::HC04DistanceSensorDriver(trigPin, echoPin, 3000);
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
    unsigned long distance = driver->getDistance();
    Serial.print("Distance is: ");
    Serial.print(distance);
    Serial.println("mm");

    // wait for 30 milliseconds
    delay(30);
}
