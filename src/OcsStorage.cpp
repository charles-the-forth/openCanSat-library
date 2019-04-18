#include <OcsStorage.h>

OcsStorage::OcsStorage(OcsGraphics& ocsDesignIn)
 : isInitalize(false),
   isTransition(false),
   ocsDesign(ocsDesignIn)
{
}

OcsStorage::message OcsStorage::getActualData()
{
	return this->actualData;
}

void OcsStorage::Update(message income, uint8_t screenNum)
{
	if (screenNum == 2)
	{		
		ocsDesign.drawMessageId(income.messageId);
		ocsDesign.drawTemperatureCanSat(income.temperatureCanSat);
		ocsDesign.drawPressureCanSat(income.pressureCanSat);
		ocsDesign.drawAltitudeCanSat(income.altitudeCanSat);
		ocsDesign.drawHumidityCanSat(income.humidityCanSat);
		ocsDesign.drawLightIntensity(income.lightIntensity);
	}
}
