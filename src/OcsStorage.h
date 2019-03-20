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
	  uint16_t lightIntensity;
	} message;

	void Update(message income, uint8_t screenNum);

	float getTemp();

	message getActualData();

	float getMinTemp();

  private:
	bool isInitalize;
	bool isTransition;

	OcsGraphics ocsDesign;

	message actualData {};
	message minData {};
	message maxData {};

	void checkTemperature(float temp);
	void checkPressure(float pressure);
	void checkAltitude(float altitude);
	void checkHumidity(float humidity);
};

#endif /* _OCSGRAPHICS_HH */

