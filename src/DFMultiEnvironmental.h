/*
 * This file and associated .cpp file are licensed under the GPLv3 License Copyright (c) 2024 Sam Groveman
 * 
 * External libraries needed:
 * DFRobot_EnvironmentalSensor: https://github.com/DFRobot/DFRobot_EnvironmentalSensor
 * DFRobot_RTU: https://github.com/DFRobot/DFRobot_RTU
 * 
 * Contributors: Sam Groveman
 */

#pragma once
#include <Sensor.h>
#include <Wire.h>
#include <DFRobot_EnvironmentalSensor.h>

class DFMultiEnvironmental : public Sensor {
	public:
		DFMultiEnvironmental(String Name, TwoWire* I2C_bus = &Wire, uint8_t address = SEN050X_DEFAULT_DEVICE_ADDRESS);
		bool begin();
		bool takeMeasurement();
		
	protected:
		DFRobot_EnvironmentalSensor env_sensor;
};