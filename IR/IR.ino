/*
 Distance
 Reads a distance, prints the result to the serial monitor
*/

#include "keyes_ir_remote_driver.h"
// pin of the receiver
int recvPin = 12;
UsefulDrivers::KeyesIRRemoteDriver *driver = new UsefulDrivers::KeyesIRRemoteDriver(recvPin);

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
    bool keyPressed = driver->keyPressed();
    if (keyPressed)
    {
        Serial.print("Remote value: ");
        Serial.println(driver->value(), HEX);
    }
}
