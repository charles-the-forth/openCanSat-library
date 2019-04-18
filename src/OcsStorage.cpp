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
		if (income.hour != 0 && income.minute != 0 && income.second != 0) {
			ocsDesign.drawTime(income.hour, income.minute, income.second);
		}
		if (income.day != 0 && income.month != 0 && income.year != 0) {
			ocsDesign.drawDate(income.day, income.month, income.year);
		}
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
