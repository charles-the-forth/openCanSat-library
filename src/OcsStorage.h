#ifndef _OCSDATASTORAGE_HH
#define _OCSDATASTORAGE_HH

#include <Arduino.h>
#include "OcsGraphics.h"

class OcsStorage
{
public:
	OcsStorage(OcsGraphics &ocsDesignIn);

	// define our own struct data type with variables
	typedef struct
	{
		uint16_t messageId;
		float temperatureCanSat;
		float pressureCanSat;
		float humidityCanSat;
		uint32_t lightIntensity;
		float altitudeCanSat;
		uint16_t year;
		uint8_t month;
		uint8_t day;
		uint8_t hour;
		uint8_t minute;
		uint8_t second;
		uint8_t numberOfSatellites;
		uint8_t latInt;
		uint8_t lonInt;
		uint32_t latAfterDot;
		uint32_t lonAfterDot;
	} message;

	void Update(message income, uint8_t screenNum);

	message getActualData();

private:
	bool isInitalize;
	bool isTransition;

	OcsGraphics ocsDesign;

	message actualData{};
};

#endif /* _OCSGRAPHICS_HH */
