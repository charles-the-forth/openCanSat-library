#include <OcsStorage.h>

OcsStorage::OcsStorage(OcsGraphics& ocsDesignIn)
 : isInitalize(false),
   isTransition(false),
   ocsDesign(ocsDesignIn)
{
}

void OcsStorage::Update(message income, uint8_t screenNum)
{
	if (screenNum == 1)
	{
		if (income.lonInt != 0 && income.lonAfterDot != 0) {
			ocsDesign.drawLongitude(income.lonInt, income.lonAfterDot);
		}
		if (income.latInt != 0 && income.latAfterDot != 0) {
			ocsDesign.drawLatitude(income.latInt, income.latAfterDot);
		}
		ocsDesign.drawSatellitesCount(income.numberOfSatellites);
	} else if(screenNum == 2)
	{
		ocsDesign.drawTemperatureCanSat(income.temperatureCanSat);
		ocsDesign.drawPressureCanSat(income.pressureCanSat);
		ocsDesign.drawAltitudeCanSat(income.altitudeCanSat);
		ocsDesign.drawHumidityCanSat(income.humidityCanSat);
		ocsDesign.drawLightIntensity(income.lightIntensity);
		ocsDesign.drawMessageId(income.messageId);
	}
}
