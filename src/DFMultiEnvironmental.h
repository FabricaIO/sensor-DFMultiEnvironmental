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
		DFMultiEnvironmental(String Name, int sda, int scl, TwoWire* I2C_bus = &Wire, uint8_t address = SEN050X_DEFAULT_DEVICE_ADDRESS);
		bool begin();
		bool takeMeasurement();
		
	protected:
		/// @brief I2C bus in use
		TwoWire* i2c_bus;

		/// @brief SCL pin in use
		int scl_pin = -1;

		/// @brief SDA pin in use
		int sda_pin = -1;

		DFRobot_EnvironmentalSensor env_sensor;
};