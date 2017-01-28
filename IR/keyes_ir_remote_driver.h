/**
 * Infrared Remote Driver Implementation
 *
 * @file keys_ir_remote_driver.h
 * @brief Infrared Remote Driver Implementation
 * @author Robert Meisner <robert@catchit.pl>
 * @version 1.0 2016-12-22
 */
#include "keyes_ir_sensor_driver.h"
#define KEY_OK 0xE0E016E9
#define KEY_HASH 0xFF52AD
#define KEY_UP 0xC26BF044
#define KEY_DOWN 0xC4FFB646
#define KEY_LEFT 0x758C9D82
#define KEY_RIGHT 0x53801EE8


namespace UsefulDrivers
{
class KeyesIRRemoteDriver
{
  public:
    KeyesIRRemoteDriver(int pin)
    {
        sensor = new UsefulDrivers::KeyesIRSensorDriver(pin);
    }
    void init()
    {
        sensor->init();
    }
    bool keyPressed()
    {
        if (sensor->received())
        {
            keyValue = sensor->value();

            return true;
        }
        return false;
    }

    bool isUp()
    {
        return keyValue == KEY_UP;
    }
    bool isDown()
    {
        return keyValue == KEY_DOWN;
    }
    bool isLeft()
    {
        return keyValue == KEY_LEFT;
    }
    bool isRight()
    {
        return keyValue == KEY_RIGHT;
    }
    bool isOK()
    {
        return keyValue == KEY_OK;
    }
    bool isHash()
    {
        return keyValue == KEY_HASH;
    }
    unsigned long value()
    {
        return keyValue;
    }

  private:
    unsigned long keyValue = 0;
    UsefulDrivers::KeyesIRSensorDriver *sensor = NULL;
};
};
