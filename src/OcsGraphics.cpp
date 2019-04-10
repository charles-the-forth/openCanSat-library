
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

	drawBackground();

	drawHeader(screenNum);

	drawSixthScreen();
	/*switch (screenNum)
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

	case 4:
		drawFourthScreen();
		break;

	case 5:
		drawFifthScreen();
		break;

	default:
		break;
	}*/

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
	drawRoundedBox("PRESSURE [hPa]", 3, 12, 76, 30);
	drawRoundedBox("ALTITUDE [m]", 81, 12, 76, 30);
	drawRoundedBox("POWER", 3, 44, 76, 30);
	drawRoundedBox("LIGHT [lx]", 81, 44, 76, 30);
	drawBox(3, 91, 76, 1);
	drawRoundedBox("UV INDEX", 3, 76, 76, 30);
	drawBox(81, 91, 76, 1);
	drawRoundedBox("AIR QUALITY", 81, 76, 76, 30);

	drawPressure(1024);
	drawAltitude(700);
	drawPower(10);
	drawLightIntensity(1300);
	drawUVIndex(1.3);
	drawAirQuality(100);
}

void OcsGraphics::drawThirdScreen()
{
	drawRoundedBox("MESSAGE ID", 3, 12, 76, 30);
	drawRoundedBox("TEMP MPU", 81, 12, 76, 30);
	drawRoundedBox("TEMP INTERNAL", 3, 44, 76, 30);
	drawRoundedBox("TEMP EXTERNAL", 81, 44, 76, 30);
	drawBox(3, 91, 154, 1);
	drawRoundedBox("HUMIDITY", 3, 76, 154, 30);

	drawMessageId(123);
	drawTemperatureMPU(24.51f);
	drawTemperatureInternal(25.1f);
	drawTemperatureExternal(23.5f);
}

void OcsGraphics::drawFourthScreen()
{
	drawRoundedBox("ROTATION X", 3, 12, 76, 30);
	drawRoundedBox("ROTATION Y", 81, 12, 76, 30);
	drawRoundedBox("ROTATION Z", 3, 44, 76, 30);
	drawRoundedBox("ACCELERATION X", 81, 44, 76, 30);
	drawBox(3, 91, 76, 1);
	drawRoundedBox("ACCELERATION Y", 3, 76, 76, 30);
	drawBox(81, 91, 76, 1);
	drawRoundedBox("ACCELERATION Z", 81, 76, 76, 30);

	drawRotationX(12.1f);
	drawRotationY(23.4f);
	drawRotationZ(32.4f);
	drawAccelerationX(5.1f);
	drawAccelerationY(8.1f);
	drawAccelerationZ(2.5f);
}

void OcsGraphics::drawFifthScreen()
{
	drawRoundedBox("MAGNETOMETER X", 3, 12, 76, 30);
	drawRoundedBox("MAGNETOMETER Y", 81, 12, 76, 30);
	drawRoundedBox("MAGNETOMETER Z", 3, 44, 76, 30);

	drawMagnetometerX(14.5f);
	drawMagnetometerY(1.5f);
	drawMagnetometerZ(44.5f);
}

void OcsGraphics::drawSixthScreen()
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

/*
void OcsGraphics::drawSixthScreen()
{
	ucg.setColor(255, 255, 255);
	ucg.drawDisc(80, 61, 45, UCG_DRAW_ALL);

	ucg.setColor(0, 0, 0);
	
	ucg.drawTriangle(76, 20, 76, 69, 45, 69);
	
	ucg.drawBox(76, 20, 12, 80);

	ucg.drawBox(45, 69, 62, 2);

	ucg.drawBox(45, 82, 62, 2);
	
	ucg.drawBox(74, 81, 2, 19);

	ucg.drawBox(92, 95, 5, 5);

	ucg.setColor(255, 255, 255);

	ucg.drawTriangle(74, 43, 74, 69, 58, 69);
	
	ucg.drawBox(45, 71, 70, 11);

	ucg.setColor(0, 0, 0);
	
	ucg.setPrintPos(45, 81);
	
	ucg.setFont(ucg_font_courB10_tr);

	ucg.print("CHARLES");

	ucg.setColor(255, 255, 255);

	ucg.setPrintPos(75, 93);
	
	ucg.setFont(ucg_font_u8glib_4_tr);
	ucg.print("TM.");
}*/

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

void OcsGraphics::drawPressure(uint16_t pressure) {
	drawText(String(pressure), 7, 37);
}

void OcsGraphics::drawAltitude(uint16_t altitude) {
	drawText(String(altitude), 85, 37);
}

void OcsGraphics::drawPower(uint16_t power) {
	drawText(String(power), 7, 69);
}

void OcsGraphics::drawLightIntensity(uint32_t lightIntensity) {
	drawText(String(lightIntensity), 85, 69);
}

void OcsGraphics::drawUVIndex(uint16_t uvIndex) {
	drawText(String(uvIndex), 7, 101);
}

void OcsGraphics::drawAirQuality(uint16_t airQuality) {
	drawText(String(airQuality), 85, 101);
}

void OcsGraphics::drawMessageId(uint32_t messageId) {
	drawText(String(messageId), 7, 37);
}

void OcsGraphics::drawTemperatureMPU(float temperature) {
	drawText(String(temperature), 85, 37);
}

void OcsGraphics::drawTemperatureInternal(float temperature) {
	drawText(String(temperature), 7, 69);
}

void OcsGraphics::drawTemperatureExternal(float temperature) {
	drawText(String(temperature), 85, 69);
}

void OcsGraphics::drawRotationX(float rotationX) {
	drawText(String(rotationX), 7, 37);
}

void OcsGraphics::drawRotationY(float rotationY) {
	drawText(String(rotationY), 85, 37);
}

void OcsGraphics::drawRotationZ(float rotationZ) {
	drawText(String(rotationZ), 7, 69);
}

void OcsGraphics::drawAccelerationX(float accelerationX) {
	drawText(String(accelerationX), 85, 69);
}

void OcsGraphics::drawAccelerationY(float accelerationY) {
	drawText(String(accelerationY), 7, 101);
}

void OcsGraphics::drawAccelerationZ(float accelerationZ) {
	drawText(String(accelerationZ), 85, 101);
}

void OcsGraphics::drawMagnetometerX(float magnetometerX) {
	drawText(String(magnetometerX), 7, 37);
}

void OcsGraphics::drawMagnetometerY(float magnetometerY) {
	drawText(String(magnetometerY), 85, 37);
}

void OcsGraphics::drawMagnetometerZ(float magnetometerZ) {
	drawText(String(magnetometerZ), 7, 69);
}

void OcsGraphics::drawText(String text, int x, int y) {
	ucg.setColor(0, 0, 0);
	ucg.setPrintPos(x, y);
	ucg.setFont(ucg_font_helvB08_tr);

	ucg.print(text);
}