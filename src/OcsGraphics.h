
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

	void drawRightArrow(int x, int y);

	void drawLeftArrow(int x, int y);

	void drawRoundedFrame(String text, int x, int y, int sizeX, int sizeY);

	void drawDate(uint8_t day, uint8_t month, uint16_t year);

	void drawTime(String time);

	void drawFirstScreen();
};

#endif /* _OCSGRAPHICS_HH */
