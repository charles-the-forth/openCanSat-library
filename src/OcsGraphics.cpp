
#include "OcsGraphics.h"
#include "Ucglib.h"
#include "Time.h"

OcsGraphics::OcsGraphics(Ucglib_ST7735_18x128x160_HWSPI &ucgIn)
		: ucg(ucgIn)
{
}

void OcsGraphics::drawHomescreen()
{
	drawScreen(2);
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
		drawTime("14:46:10");
		drawDate(10, 4, 2019);
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

	ucg.print(String(screenNum) + "/3");

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

	if (screenNum < 6)
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
	drawRoundedBox("LONGITUDE", 81, 12, 76, 30);
	drawRoundedBox("LATITUDE", 81, 44, 76, 30);
	drawBox(81, 91, 76, 1);
	drawRoundedBox("SATELLITES COUNT", 81, 76, 76, 30);

	drawLongitude(5002, 2308);
	drawLatitude(1546, 79412);
	drawSatellitesCount(5);
}

void OcsGraphics::drawSecondScreen()
{
	drawRoundedBox("MESSAGE ID", 3, 12, 76, 30);
	drawRoundedBox("TEMP CANSAT", 81, 12, 76, 30);
	drawRoundedBox("PRESSURE CANSAT", 3, 44, 76, 30);
	drawRoundedBox("ALTITUDE CANSAT", 81, 44, 76, 30);
	drawBox(3, 91, 154, 1);
	drawRoundedBox("HUMIDITY CANSAT", 3, 76, 76, 30);
	drawRoundedBox("LIGHT INTENSITY", 81, 76, 76, 30);
	drawBox(3, 91, 154, 1);
}

void OcsGraphics::drawThirdScreen()
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

void OcsGraphics::drawBackground() {
	ucg.setColor(115, 210, 247);

	ucg.drawBox(0, 0, 160, 128);
}

void OcsGraphics::drawBox(int x, int y, int sizeX, int sizeY) {
	ucg.setColor(255, 255, 255);

	ucg.drawBox(x, y, sizeX, sizeY);
}

void OcsGraphics::drawLongitude(uint16_t lonInt, uint32_t lonAfterDot) {

	drawText(String(lonInt / 100) + " " + String(lonInt % 100) + "." + String(lonAfterDot), 85, 37);
}

void OcsGraphics::drawLatitude(uint16_t latInt, uint32_t latAfterDot) {
	drawText(String(latInt / 100) + " " + String(latInt % 100) + "." + String(latAfterDot), 85, 69);
}

void OcsGraphics::drawSatellitesCount(uint16_t satellitesCount) {
	drawText(String(satellitesCount), 85, 101);
}

void OcsGraphics::drawAltitudeCanSat(uint16_t altitude) {
	drawText(String(altitude), 85, 69);
}

void OcsGraphics::drawMessageId(uint32_t messageId) {
	drawText(String(messageId), 7, 37);
}

void OcsGraphics::drawTemperatureCanSat(float temperature) {
	drawText(String(temperature), 85, 37);
}

void OcsGraphics::drawPressureCanSat(uint16_t pressure) {
	drawText(String(pressure), 7, 69);
}

void OcsGraphics::drawHumidityCanSat(float humidityCanSat) {
	drawText(String(humidityCanSat), 7, 101);
}

void OcsGraphics::drawLightIntensity(uint32_t lightIntensity) {
	drawText(String(lightIntensity), 85, 101);
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