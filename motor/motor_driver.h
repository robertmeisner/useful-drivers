/**
 * Motor Driver Interface
 * @file motor_driver.h
 * @brief Motor device driver interface for the robot project.
 * @author Robert Meisner <robert@catchit.pl>
 * @version 1.0 2016-12-22
 */

namespace UsefulDrivers
{
class MotorDriver
{
  public:
    virtual void init() = 0;
    /**
    * @brief Change the speed of the motor.
    * @param speed The new speed of the motor.
    *  Valid values are between -255 and 255. 
    *  Use positive values to run the motor forward, 
    *  negative values to run it backward and zero to stop the motor.
    */
    virtual void setSpeed(int speed) = 0;

    /**
    * @brief Return the current speed of the motor.
    * @return The current speed of the motor with range -255 to 255.
    */
    virtual int getSpeed() const = 0;

  protected:
    static const int MIN_SPEED = -255;
    static const int MAX_SPEED = 255;
};
};