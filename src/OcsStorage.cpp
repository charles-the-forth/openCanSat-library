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
	if (screenNum == 3)
	{
		ocsDesign.drawMessageId(income.messageId);
		ocsDesign.drawTemperatureMPU(income.temperatureMPU);
		ocsDesign.drawTemperatureCanSat(income.temperatureCanSat);
		ocsDesign.drawTemperatureExternal(income.temperatureExternal);
		ocsDesign.drawHumidityCanSat(income.humidityCanSat);
		ocsDesign.drawHumidityExternal(income.humidityExternal);
	}
}
