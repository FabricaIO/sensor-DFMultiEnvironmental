#include "DFMultiEnvironmental.h"

/// @brief Creates a new multi environmental sensor object
/// @param Name The device name
/// @param I2C_bus The I2C bus attached to the sensor
/// @param address Address of the sensor
DFMultiEnvironmental::DFMultiEnvironmental(String Name, TwoWire* I2C_bus, uint8_t address) : env_sensor(address, I2C_bus), Sensor(Name) {}

/// @brief Starts the environmental sensor
/// @return True on success
bool DFMultiEnvironmental::begin() {
	Description.parameterQuantity = 6;
	Description.type = "Multi Environment Sensor";
	Description.parameters = {"Temperature", "Humidity", "UV Intensity", "Light Flux", "Atmospheric Pressure", "Altitude"};
	Description.units = {"C", "%RH", "mw/cm^2", "lx", "kpa", "m"};
	values.resize(Description.parameterQuantity);
	// Call default setup
	if (!Sensor::begin()) {
		return false;
	}
	return env_sensor.begin() == 0;
}

/// @brief Takes a measurement
/// @return True on success
bool DFMultiEnvironmental::takeMeasurement() {
	values[0] = env_sensor.getTemperature(TEMP_C);
	values[1] = env_sensor.getHumidity();
	values[2] = env_sensor.getUltravioletIntensity();
	values[3] = env_sensor.getLuminousIntensity();
	values[4] = env_sensor.getAtmospherePressure(KPA);
	values[5] = env_sensor.getElevation();
	return true;
}