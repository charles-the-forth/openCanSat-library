
#include "OcsGraphics.h"
#include "Ucglib.h"
#include "Time.h"

OcsGraphics::OcsGraphics(Ucglib_ST7735_18x128x160_HWSPI &ucgIn)
		: ucg(ucgIn)
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

	switch (screenNum)
	{
	case 1:
		drawFirstScreen();
		drawTime("18:46:10");
		drawDate(10, 1, 2018);
		break;

	case 2:
		drawSecondScreen();
		break;

	case 3:
		drawThirdScreen();
		break;

	default:
		break;
	}

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
	if (screenNum > 1)
	{
		drawLeftArrow(10, 118);
	}

	drawHome(74, 114, 12, 11, 17, 30, 108);

	if (screenNum < 6)
	{
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

	ucg.drawBox(x + 5 * divide(width, 12), y + 4 * divide(height, 6), divide(width, 6), divide(height, 3));

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
	return ceil(x / y);
}

void OcsGraphics::drawFirstScreen()
{
	drawRoundedFrame("LONGITUDE", 81, 12, 76, 30);
	drawRoundedFrame("LATITUDE", 81, 44, 76, 30);
	drawRoundedFrame("SATELLITES COUNT", 81, 76, 76, 30);
}

void OcsGraphics::drawSecondScreen()
{
	drawRoundedFrame("PRESSURE", 3, 12, 76, 30);
	drawRoundedFrame("ALTITUDE", 81, 12, 76, 30);
	drawRoundedFrame("POWER", 3, 44, 76, 30);
	drawRoundedFrame("LIGHT INTENSITY", 81, 44, 76, 30);
	drawRoundedFrame("UV INDEX", 3, 76, 154, 30);
}

void OcsGraphics::drawThirdScreen()
{
	drawRoundedFrame("MESSAGE ID", 3, 12, 76, 30);
	drawRoundedFrame("TEMP MPU", 81, 12, 76, 30);
	drawRoundedFrame("TEMP INTERNAL", 3, 44, 76, 30);
	drawRoundedFrame("TEMP EXTERNAL", 81, 44, 76, 30);
	drawRoundedFrame("HUMIDITY", 3, 76, 154, 30);
}

void OcsGraphics::drawRoundedFrame(String text, int x, int y, int sizeX, int sizeY)
{
	ucg.setColor(255, 255, 255);

	ucg.setPrintPos(x + 4, y + 10);

	ucg.setFont(ucg_font_micro_mf);

	ucg.print(text);

	ucg.drawRFrame(x, y, sizeX, sizeY, 3);
}

void OcsGraphics::drawDate(uint8_t day, uint8_t month, uint16_t year)
{

	ucg.setColor(fontR, fontG, fontB);
	ucg.setColor(1, bgrR, bgrG, bgrB);

	ucg.setRotate90();

	String sDay;
	String sMonth;

	if (day < 10)
	{
		sDay += "0";
	}

	switch (month)
	{
	case 0:
	case 1:
		sMonth = "January";
		break;
	case 2:
		sMonth = "February";
		break;
	case 3:
		sMonth = "March";
		break;
	case 4:
		sMonth = "April";
		break;
	case 5:
		sMonth = "May";
		break;
	case 6:
		sMonth = "June";
		break;
	case 7:
		sMonth = "July";
		break;
	case 8:
		sMonth = "August";
		break;
	case 9:
		sMonth = "September";
		break;
	case 10:
		sMonth = "October";
		break;
	case 11:
		sMonth = "November";
		break;
	case 12:
		sMonth = "December";
		break;
	}

	if (day == 0 or year == 0)
	{
		sDay += 1;
		year = 1990;
	}

	sDay += String(day);

	ucg.setPrintPos(13, 58);
	ucg.setFont(ucg_font_helvB10_tr);
	ucg.print(sDay);

	ucg.setFont(ucg_font_helvB10_tr);
	ucg.setPrintPos(13, 73);
	ucg.print(sMonth);

	ucg.setPrintPos(13, 90);
	ucg.setFont(ucg_font_helvB10_tr);
	ucg.print(String(year));
}

void OcsGraphics::drawTime(String time)
{
	ucg.setRotate90();

	ucg.setColor(255, 255, 255);
	ucg.setPrintPos(13, 40);
	ucg.setFont(ucg_font_helvB10_tr);

	ucg.print(time);
}
