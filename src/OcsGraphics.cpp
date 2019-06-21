
#include "OcsGraphics.h"
#include "Ucglib.h"
#include "Time.h"

OcsGraphics::OcsGraphics(Ucglib_ST7735_18x128x160_HWSPI &ucgIn)
		: ucg(ucgIn)
{
}

void OcsGraphics::drawHomescreen()
{
	drawScreen(1);
}

void OcsGraphics::drawScreen(uint8_t screenNum)
{
	ucg.clearScreen();
	ucg.setRotate90();

	drawBackground();

	drawHeader(screenNum);

	switch (screenNum)
	{
	case 1:
		drawFirstScreen();
		break;

	case 2:
		drawSecondScreen();
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

	ucg.print(String(screenNum) + "/2");

	ucg.setPrintPos(90, 7);

	ucg.print("charles4th.cz");
}

void OcsGraphics::drawFooter(uint8_t screenNum)
{
	if (screenNum > 1)
	{
		drawLeftArrow(10, 118);
	}

	drawHome(74, 114, 12, 11, 115, 210, 247);

	if (screenNum < 2)
	{
		drawRightArrow(141, 118);
	}
}

void OcsGraphics::drawHome(int x, int y, int width, int height, int r, int g, int b)
{
	int halfSizeHeight = divide(height, 2);
	int halfSizeWidth = divide(width, 2);

	ucg.setRotate90();

	ucg.setColor(255, 255, 255);

	ucg.drawBox(x + divide(width, 4), y + halfSizeHeight, halfSizeWidth, halfSizeHeight);

	ucg.drawTriangle(x + halfSizeWidth, y, x + width, y + halfSizeHeight, x, y + halfSizeHeight);

	ucg.setColor(r, g, b);

	ucg.drawBox(x + 5 * divide(width, 12), y + 4 * divide(height, 6), divide(width, 6), divide(height, 3));

	ucg.setColor(255, 255, 255);
}

void OcsGraphics::drawRightArrow(int x, int y)
{
	ucg.setRotate90();	
	
	ucg.setColor(255, 255, 255);

	ucg.drawBox(x, y, 8, 5);

	ucg.drawTriangle(x + 8, y - 4, x + 8, y + 8, x + 14, y + 2);
}

void OcsGraphics::drawLeftArrow(int x, int y)
{
	ucg.setRotate90();

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
	drawRoundedBox("MESSAGE ID", 3, 12, 76, 30);
	drawRoundedBox("TEMP CANSAT", 81, 12, 76, 30);
	drawRoundedBox("PRESSURE CANSAT", 3, 44, 76, 30);
	drawRoundedBox("ALTITUDE CANSAT", 81, 44, 76, 30);
	drawBox(3, 91, 76, 1);
	drawRoundedBox("HUMIDITY CANSAT", 3, 76, 76, 30);
	drawBox(81, 91, 76, 1);
	drawRoundedBox("LIGHT INTENSITY", 81, 76, 76, 30);
}

void OcsGraphics::drawSecondScreen()
{
	ucg.setColor(255, 255, 255);
	ucg.drawDisc(80, 61, 50, UCG_DRAW_ALL);

	ucg.setColor(0, 0, 0);
	
	ucg.drawTriangle(79, 20, 79, 69, 48, 69);
	
	ucg.drawBox(79, 20, 12, 80);

	ucg.drawBox(48, 69, 62, 2);

	ucg.drawBox(48, 82, 62, 2);
	
	ucg.drawBox(77, 81, 2, 19);

	ucg.drawBox(95, 95, 5, 5);

	ucg.setColor(255, 255, 255);

	ucg.drawTriangle(77, 43, 77, 69, 61, 69);
	
	ucg.drawBox(48, 71, 73, 11);

	ucg.setColor(0, 0, 0);
	
	ucg.setPrintPos(48, 81);
	
	ucg.setFont(ucg_font_courB10_tr);

	ucg.print("CHARLES");

	ucg.setColor(255, 255, 255);

	ucg.setPrintPos(82, 28);
	
	ucg.setFont(ucg_font_orgv01_tr);
	ucg.print("C");

	ucg.setPrintPos(82, 36);
	
	ucg.setFont(ucg_font_orgv01_tr);
	ucg.print("A");

	ucg.setPrintPos(82, 44);
	
	ucg.setFont(ucg_font_orgv01_tr);
	ucg.print("N");

	ucg.setPrintPos(82, 52);
	
	ucg.setFont(ucg_font_orgv01_tr);
	ucg.print("S");

	ucg.setPrintPos(82, 60);
	
	ucg.setFont(ucg_font_orgv01_tr);
	ucg.print("A");

	ucg.setPrintPos(82, 68);
	
	ucg.setFont(ucg_font_orgv01_tr);
	ucg.print("T");

	ucg.setPrintPos(78, 93);
	
	ucg.setFont(ucg_font_u8glib_4_tr);
	ucg.print("TM.");
}

void OcsGraphics::drawRoundedBox(String text, int x, int y, int sizeX, int sizeY)
{
	ucg.setColor(255, 255, 255);
	
	ucg.drawRBox(x, y, sizeX, sizeY, 3);

	ucg.setColor(0, 0, 0);

	ucg.setPrintPos(x + 4, y + 10);

	ucg.setFont(ucg_font_micro_mf);

	ucg.print(text);
}

void OcsGraphics::drawBackground() {
	ucg.setColor(115, 210, 247);

	ucg.drawBox(0, 0, 160, 128);
}

void OcsGraphics::drawBox(int x, int y, int sizeX, int sizeY) {
	ucg.setColor(255, 255, 255);

	ucg.drawBox(x, y, sizeX, sizeY);
}

void OcsGraphics::drawPressureCanSat(uint16_t pressure) {
	drawText(String(pressure), 7, 69);
}

void OcsGraphics::drawAltitudeCanSat(uint16_t altitude) {
	drawText(String(altitude), 85, 69);
}

void OcsGraphics::drawLightIntensity(uint32_t lightIntensity) {
	drawText(String(lightIntensity), 85, 101);
}

void OcsGraphics::drawMessageId(uint32_t messageId) {
	drawText(String(messageId), 7, 37);
}

void OcsGraphics::drawTemperatureCanSat(float temperature) {
	drawText(String(temperature), 85, 37);
}

void OcsGraphics::drawHumidityCanSat(float humidity) {
	drawText(String(humidity), 7, 101);
}

void OcsGraphics::drawText(String text, int x, int y) {
	ucg.begin(UCG_FONT_MODE_SOLID);
	
	ucg.setRotate90();
	
	ucg.setColor(0, 0, 0);
	ucg.setColor(1, 255, 255, 255);

	ucg.setPrintPos(x, y);

	ucg.setFont(ucg_font_7x13B_tf);

	ucg.print(text);

	ucg.begin(UCG_FONT_MODE_TRANSPARENT);
}