
#ifndef _OCSGRAPHICS_HH
#define _OCSGRAPHICS_HH

#include <Arduino.h>
#include "Ucglib.h"

class OcsGraphics
{
  public:
	OcsGraphics(Ucglib_ST7735_18x128x160_HWSPI& ucgIn);

	void drawHomescreen();
	void drawScreen(uint8_t screenNum);
	
  private:
	Ucglib_ST7735_18x128x160_HWSPI& ucg;
	int divide(int x, double y);
	
	void drawHeader(uint8_t screenNum);

	void drawFooter(uint8_t screenNum);

	void drawHome(int x, int y, int width, int height, int r, int g, int b);
	
	void drawRightArrow(int x, int y);
	
	void drawLeftArrow(int x, int y);

};

#endif /* _OCSGRAPHICS_HH */
