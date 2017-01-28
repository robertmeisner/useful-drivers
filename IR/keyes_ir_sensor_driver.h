/**
 * "Keyes" Infrared Sensor Driver Implementation
 * 
 * @file keys_ir_sensor_driver.h
 * @brief Infrared Sensor Driver Implementation
 * @author Robert Meisner <robert@catchit.pl>
 * @version 1.0 2016-12-22
 */
#include <IRremote.h>
#include "ir_sensor_driver.h"
namespace UsefulDrivers
{
class KeyesIRSensorDriver : public IRSensorDriver
{
  public:
    /**
          * @brief Class constructor.
          * @param distance The maximum distance in centimeters that needs to be tracked.
          */
    KeyesIRSensorDriver(int pin) : IRSensorDriver()
    {
        irrecv = new IRrecv(pin);
    };
    void init()
    {
        irrecv->enableIRIn();
    };
    bool received()
    {
        if (irrecv->decode(&results))
        {
            // I have received an IR signal
            // Serial.println(results.value, HEX);
            lastValue = results.value;

            irrecv->resume();
            return true;
        }
        return false;
    }

    unsigned long value()
    {
        return lastValue;
    }

    unsigned long lastValue = 0;

  private:
    IRrecv *irrecv = NULL;
    decode_results results;
};
};
