/**
 * HC-SR04 Distance Sensor Driver Implementation
 *
 * @file hc_sr04_distance_sensor_driver.h
 * @brief HC-SR04 Distance Sensor Driver Implementation
 * @author Robert Meisner <robert@catchit.pl>
 * @version 1.0 2016-12-22
 */


#include "distance_sensor_driver.h"

#define MEASURE_SAMPLE_DELAY 5
#define MEASURE_SAMPLES 25
namespace UsefulDrivers
{
class HC04DistanceSensorDriver : public DistanceSensorDriver
{
  public:
    HC04DistanceSensorDriver(int triggerPin, int echoPin, int maxDistance)
        : DistanceSensorDriver(maxDistance),
          triggerPin(triggerPin), echoPin(echoPin)
    {
    }
    void init()
    {
        Serial.print("Initiating Distance Sensor on :");
        Serial.println(echoPin);
        pinMode(echoPin, INPUT);
        pinMode(triggerPin, OUTPUT);
    }
    virtual unsigned long getDistance()
    {
        long dist = measure();
        //Serial.println(dist);
        return dist;
    }

  private:
    int triggerPin;
    int echoPin;
    const float usonicDiv = 58.0;

    long measure()
    {
        long measureSum = 0;
        for (int i = 0; i < MEASURE_SAMPLES; i++)
        {
            delay(MEASURE_SAMPLE_DELAY);
            measureSum += singleMeasurement();
        }
        return measureSum / MEASURE_SAMPLES;
    }
    long singleMeasurement()
    {
        long duration = 0;
        // Measure: Put up Trigger...
        digitalWrite(triggerPin, LOW);
        delayMicroseconds(2);
        digitalWrite(triggerPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(triggerPin, LOW);
        duration = pulseIn(echoPin, HIGH);
        return (long)(((float)duration / usonicDiv) * 10.0);
    }
};
};