/**
 * Distance Sensor Driver Interface
 *
 * @file distance_sensor_driver.h
 * @brief Distance Sensor Driver Interface
 * @author Robert Meisner <robert@catchit.pl>
 * @version 1.0 2016-12-22
 */


namespace UsefulDrivers
{
     class DistanceSensorDriver
    {
    public:
		virtual void init() = 0;
        /**
          * @brief Class constructor.
          */
        DistanceSensorDriver(unsigned int distance) : maxDistance(distance) {}
        
        /**
         * @brief Return the distance to the nearest obstacle in centimeters.
         * @return the distance to the closest object in centimeters 
         *   or maxDistance if no object was detected
         */
        virtual unsigned long getDistance() = 0;
        
    protected:
        unsigned int maxDistance;
    };
};