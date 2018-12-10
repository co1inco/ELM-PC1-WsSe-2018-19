#pragma once

#include "Serial.h"

class Display {
public:
    Display();
    ~Display();

	bool init();
	void close();

	void clearScreen();
	void clearScreen(char clow, char chigh);
	void clearScreen(char c[8]);

	void drawRectangle(int posx1, int posy1, int posx2, int posy2, char clow, char chigh, int width);
	void drawRectangle(int posx1, int posy1, int posx2, int posy2, char c[8], int width);

	void drawRectangle(int posx1, int posy1, int posx2, int posy2, char clow, char chigh);
	void drawRectangle(int posx1, int posy1, int posx2, int posy2, char c[8]);

	void drawBalken(int x1, int y1, int x2, int y2, char cFg[8], char cBg[8], int value, int valueMax=0);

	void drawOval(int x1, int y1, int x2, int y2, char c[8], int width, bool keepWidth=true);

	void drawText(int posx, int posy, int fglow, int fghigh, int bglow, int bghigh, char* text);
	void drawText(int posx, int posy, char fg[8], char bg[8], char* text);

	int readPoti();

private:
    Serial *ser;
};

