/**
 * Infrared Sensor Driver Interface
 *
 * @file ir_sensor_driver.h
 * @brief Infrared Sensor Driver Interface
 * @author Robert Meisner <robert@catchit.pl>
 * @version 1.0 2016-12-22
 */

namespace UsefulDrivers
{
class IRSensorDriver
{
public:
  virtual void init() = 0;
  /**
  * Class constructor.
  */
  IRSensorDriver() {}
  /**
  * Return true if sensor has received new value
  * @return bool
  */
  virtual bool received() = 0;
  /**
  * Returns last value received
  * @return int
  */
  virtual unsigned long value() = 0;

protected:
};
};
