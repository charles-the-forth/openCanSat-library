
#include "OcsGraphics.h"
#include "Ucglib.h"
#include "Time.h"

OcsGraphics::OcsGraphics(Ucglib_ST7735_18x128x160_HWSPI& ucgIn)
	:ucg(ucgIn)
{
}

void OcsGraphics::drawHomescreen()
{
	drawScreen(3);
}

void OcsGraphics::drawScreen(uint8_t screenNum)
{
	ucg.clearScreen();
  ucg.setRotate90();

	drawHeader(screenNum);
	
	drawFooter(screenNum);
}

void OcsGraphics::drawHeader(uint8_t screenNum)
{
  ucg.setRotate90();

  ucg.setFont(ucg_font_5x7_mf);

  ucg.setColor(255, 255, 255);

  ucg.setFontPosBaseline();

  ucg.setPrintPos(70, 7);

  ucg.print(String(screenNum) + "/6");

  ucg.setPrintPos(90, 7);

  ucg.print("charles4th.cz");
}

void OcsGraphics::drawFooter(uint8_t screenNum)
{
  if (screenNum > 1) {
  	drawLeftArrow(10, 118);
	}

	drawHome(74, 114, 12, 11, 17, 30, 108);
	
	if (screenNum < 6) {
		drawRightArrow(141, 118);
	}
}

void OcsGraphics::drawHome(int x, int y, int width, int height, int r, int g, int b)
{
	int halfSizeHeight = divide(height, 2);
	int halfSizeWidth = divide(width, 2);

	ucg.setColor(255, 255, 255);

	ucg.drawBox(x + divide(width, 4), y + halfSizeHeight, halfSizeWidth, halfSizeHeight);

	ucg.drawTriangle(x + halfSizeWidth, y, x + width, y + halfSizeHeight, x, y + halfSizeHeight);

	ucg.setColor(r, g, b);

	ucg.drawBox(x + 5*divide(width, 12), y + 4*divide(height, 6), divide(width, 6), divide(height, 3));

	ucg.setColor(255, 255, 255);
}

void OcsGraphics::drawRightArrow(int x, int y)
{
  ucg.setColor(255, 255, 255);

  ucg.drawBox(x, y, 8, 5);

  ucg.drawTriangle(x + 8, y - 4, x + 8, y + 8, x + 14, y + 2);
}

void OcsGraphics::drawLeftArrow(int x, int y)
{
  ucg.setColor(255, 255, 255);

  ucg.drawBox(x, y, 8, 5);

  ucg.drawTriangle(x, y - 5, x, y + 8, x - 6, y + 2);
}

int OcsGraphics::divide(int x, double y)
{
	return ceil(x/y);
}