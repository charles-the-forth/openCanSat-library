#ifndef _OCSDATASTORAGE_HH
#define _OCSDATASTORAGE_HH

#include <Arduino.h>
#include "OcsGraphics.h"

class OcsStorage
{
  public:
	OcsStorage(OcsGraphics& ocsDesignIn);

	// define our own struct data type with variables
	typedef struct
	{
		uint16_t messageId;
		float temperatureCanSat;
		float temperatureExternal;
		double ambientTemp;
		double objectTemp;
		float pressureCanSat;
		float pressureExternal;
		float humidityCanSat;
		float humidityExternal;
		uint32_t lightIntensity;
		float altitudeCanSat;
		float altitudeExternal;
		uint16_t co2SCD30;
		uint16_t co2CCS811;
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
		float accelerationX;
		float accelerationY;
		float accelerationZ;
		float rotationX;
		float rotationY;
		float rotationZ;
		float magnetometerX;
		float magnetometerY;
		float magnetometerZ;
		float a;
		float b;
		float c;
		float d;
		float e;
		float f;
		float g;
		float h;
		float i;
		float j;
		float k;
		float l;
		float r;
		float s;
		float t;
		float u;
		float v;
		float w;
	} message;

	void Update(message income, uint8_t screenNum);

  private:
	bool isInitalize;
	bool isTransition;

	OcsGraphics ocsDesign;

	message actualData {};
};

#endif /* _OCSGRAPHICS_HH */

