/**
 * Continous Servo Motor Driver Interface
 * @file continous_servo_motor_driver.h
 * @brief Continous Servo Motor device driver implementation for the robot project.
 * @author Robert Meisner <robert@catchit.pl>
 * @version 1.0 2016-12-22
 */

#include "motor_driver.h"
#include <Servo.h>

namespace UsefulDrivers
{
    class ContinousServoMotorDriver : public MotorDriver
    {
    public:
        /*
         * @brief Class constructor.
         * @param pin number of pin
         */
        ContinousServoMotorDriver(int pin)
            : MotorDriver(),pin(pin), currentSpeed(0)
        {
			//Serial.println("Motor constructor");
		}
		void init(){
			motor.attach(pin); 
			motor.write(scaleRange(currentSpeed));
		}
        void setSpeed(int speed)
        {
			currentSpeed = speed;
			motor.write(scaleRange(speed));
        }

        int getSpeed() const
        {
            return currentSpeed;
        }

    private:
		
        Servo motor;
		int pin;
        int currentSpeed;
		/**
		* Scales robot's <-255,255> range to servo's <0;180> 
		*/
		int scaleRange(int x){
			
			int speed=0;
			int max_new=180;
			int min_new=0;
			if(x==0)
				speed= 90;
			int rangeOld=MAX_SPEED-MIN_SPEED;
			//Serial.println(x);
			//Serial.println(rangeOld);
			int rangeNew = (max_new - min_new);
			//Serial.println(rangeNew);
			/**
			*        (b-a)(x - min)
			* f(x) = --------------  + a
			*          max - min
			*/
			speed = ((((float)x - (float)MIN_SPEED) * (float)rangeNew) / (float)rangeOld) + (float)min_new;
			//Serial.println(speed);
			
			return speed;
		}
    };
};