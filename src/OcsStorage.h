#ifndef _OCSDATASTORAGE_HH
#define _OCSDATASTORAGE_HH

#include <Arduino.h>
#include "OcsGraphics.h"

class OcsStorage
{
public:
	OcsStorage(OcsGraphics &ocsDesignIn);

	typedef struct
	{
		uint8_t messageType;
		uint16_t messageId;
		float temperatureCanSat;
		float temperatureExternal;
		float ambientTemp;
		float objectTemp;
		float pressureCanSat;
		float pressureExternal;
		float humidityCanSat;
		float humidityExternal;
		uint32_t lightIntensity;
		float altitudeCanSat;
		float altitudeExternal;
		uint16_t co2SCD30;
		uint16_t co2CCS811;
	} message1;

	typedef struct
	{
		uint8_t messageType;
		uint16_t messageId;
		uint16_t tvoc;
		float o2Concentration;
		uint16_t latInt;
		uint16_t lonInt;
		uint32_t latAfterDot;
		uint32_t lonAfterDot;
		uint8_t numberOfSatellites;
		float uvIndex;
		float temperatureMPU;
		float temperatureSCD30;
		float humiditySCD30;
	} message2;

	typedef struct
	{
		uint8_t messageType;
		uint16_t messageId;
		float accelerationX;
		float accelerationY;
		float accelerationZ;
		float rotationX;
		float rotationY;
		float rotationZ;
		float magnetometerX;
		float magnetometerY;
		float magnetometerZ;
	} message3;

	typedef struct
	{
		uint8_t messageType;
		uint16_t messageId;
		float a;
		float b;
		float c;
		float d;
		float e;
		float f;
		float g;
		float h;
		float r;
		float i;
		float s;
		float j;
		float t;
	} message4;

	void Update(message1 income, uint8_t screenNum);
	void Update(message2 income, uint8_t screenNum);
	void Update(message3 income, uint8_t screenNum);
	void Update(message4 income, uint8_t screenNum);

private:
	bool isInitalize;
	bool isTransition;

	OcsGraphics ocsDesign;
};

#endif /* _OCSGRAPHICS_HH */
