
#ifndef _OCSGRAPHICS_HH
#define _OCSGRAPHICS_HH

#include <Arduino.h>
#include "Ucglib.h"

class OcsGraphics
{
  public:
	OcsGraphics(Ucglib_ST7735_18x128x160_HWSPI &ucgIn);

	void drawHomescreen();
	void drawScreen(uint8_t screenNum);

	void drawLongitude(uint16_t lonInt, uint32_t lonAfterDot);

	void drawLatitude(uint16_t latInt, uint32_t latAfterDot);

	void drawSatellitesCount(uint16_t satellitesCount);

	void drawPressure(uint16_t pressure);

	void drawAltitude(uint16_t altitude);

	void drawPower(uint16_t power);

	void drawLightIntensity(uint32_t lightIntensity);

	void drawUVIndex(uint16_t uvIndex);

	void drawAirQuality(uint16_t airQuality);

	void drawMessageId(uint32_t messageId);

	void drawTemperatureMPU(float temperature);

	void drawTemperatureInternal(float temperature);

	void drawTemperatureExternal(float temperature);

  private:
	Ucglib_ST7735_18x128x160_HWSPI &ucg;

	uint8_t fontR = 255;
	uint8_t fontG = 255;
	uint8_t fontB = 255;

	uint8_t bgrR = 17;
	uint8_t bgrG = 30;
	uint8_t bgrB = 108;

	int divide(int x, double y);

	void drawHeader(uint8_t screenNum);

	void drawFooter(uint8_t screenNum);

	void drawHome(int x, int y, int width, int height, int r, int g, int b);

	void drawBackground();

	void drawRightArrow(int x, int y);

	void drawLeftArrow(int x, int y);

	void drawRoundedBox(String text, int x, int y, int sizeX, int sizeY);

	void drawBox(int x, int y, int sizeX, int sizeY);

	void drawDate(uint8_t day, uint8_t month, uint16_t year);

	void drawTime(String time);

	void drawFirstScreen();

	void drawSecondScreen();

	void drawThirdScreen();

	void drawFourthScreen();

	void drawFifthScreen();

	void drawText(String text, int x, int y);
};

#endif /* _OCSGRAPHICS_HH */
