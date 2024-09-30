#include "DFMultiEnvironmental.h"

/// @brief Creates a new multi environmental sensor object
/// @param I2C_bus The I2C bus attached to the sensor
/// @param address Address of the sensor
DFMultiEnvironmental::DFMultiEnvironmental(TwoWire* I2C_bus, uint8_t address) : env_sensor(address, I2C_bus) {}

/// @brief Starts the environmental sensor
/// @return True on success
bool DFMultiEnvironmental::begin() {
	values.resize(6);
	Description.parameterQuantity = 6;
	Description.type = "Multi Environment Sensor";
	Description.name = "Environmental Sensor";
	Description.parameters = {"Temperature", "Humidity", "UV Intensity", "Light FLux", "Atmospheric Pressure", "Altitude"};
	Description.units = {"C", "%RH", "mw/cm^2", "lx", "kpa", "m"};
	Description.id = 1;
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