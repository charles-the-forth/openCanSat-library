#include <OcsStorage.h>

OcsStorage::OcsStorage(OcsGraphics& ocsDesignIn)
 : isInitalize(false),
   isTransition(false),
   ocsDesign(ocsDesignIn)
{
}

void OcsStorage::Update(message income, uint8_t screenNum)
{
	if(screenNum == 1)
	{
		ocsDesign.drawTemperatureCanSat(income.temperatureCanSat);
		ocsDesign.drawPressureCanSat(income.pressureCanSat);
		ocsDesign.drawAltitudeCanSat(income.altitudeCanSat);
		ocsDesign.drawHumidityCanSat(income.humidityCanSat);
		ocsDesign.drawLightIntensity(income.lightIntensity);
		ocsDesign.drawMessageId(income.messageId);
	}
}
