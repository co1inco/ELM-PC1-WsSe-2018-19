#pragma once

#include "Serial.h"
#include <math.h>
#include <iostream>

#define PI 3.14159265

class Display {
public:
	Display(int d) :dummy(d), ser(1) {};

	bool init() {
		return ser.open();
	}
	void close() {
		ser.close();
	}

	void clearScreen() {
		char command[4];
		sprintf_s(command, 4, "%c%c%c", 0x00, 0x00, 0x00);
		ser.Write(command, 3);
	}
	void clearScreen(char clow, char chigh) {
		char command[4];
		sprintf_s(command, 4, "%c%c%c", 0x00, clow, chigh);
		ser.Write(command, 3);
	}
	void clearScreen(char c[8]) {
		int c1, c2;
		splitColor(hex2col(c), &c1, &c2);

		char command[4];
		sprintf_s(command, 4, "%c%c%c", 0x00, c1, c2);
		ser.Write(command, 3);
	}

	void drawRectangle(int posx1, int posy1, int posx2, int posy2, char clow, char chigh, int width) {
		char command[9];
		sprintf_s(command, 9, "%c%c%c%c%c%c%c%c", 0x03, posx1, posy1, posx2, posy2, clow, chigh, width);
		ser.Write(command, 8);
	}
	void drawRectangle(int posx1, int posy1, int posx2, int posy2, char c[8], int width) {
		int clow, chigh;
		splitColor(hex2col(c), &clow, &chigh);

		char command[9];
		sprintf_s(command, 9, "%c%c%c%c%c%c%c%c", 0x03, posx1, posy1, posx2, posy2, clow, chigh, width);
		ser.Write(command, 8);
	}

	void drawRectangle(int posx1, int posy1, int posx2, int posy2, char clow, char chigh) {
		char command[8];
		sprintf_s(command, 8, "%c%c%c%c%c%c%c", 0x02, posx1, posy1, posx2, posy2, clow, chigh);
		ser.Write(command, 7);
	}
	void drawRectangle(int posx1, int posy1, int posx2, int posy2, char c[8]) {
		int clow, chigh;
		splitColor(hex2col(c), &clow, &chigh);

		char command[8];
		sprintf_s(command, 8, "%c%c%c%c%c%c%c", 0x02, posx1, posy1, posx2, posy2, clow, chigh);
		ser.Write(command, 7);
	}

	void drawOval(int x1, int y1, int x2, int y2, char c[8], int width, bool keepWidth=true) {
		int clow, chigh;
		splitColor(hex2col(c), &clow, &chigh);

		if (keepWidth == true) {
			x1 = x1 + (y2 - y1);
			x2 = x2 - (y2 - y1);
		}
		
		char command[8];
		sprintf_s(command, 8, "%c%c%c%c%c%c%c", 0x02, x1, y1, x2, y1 + width, clow, chigh);
		ser.Write(command, 7);
		sprintf_s(command, 8, "%c%c%c%c%c%c%c", 0x02, x1, y2 - width, x2, y2, clow, chigh);
		ser.Write(command, 7);

		int curveResolution = 2;

		int i;
		int pos;
		double mapOut;
		for (i = y1-1; i < y2; i += curveResolution) {
			mapOut = map(i, y1, y2, 0, PI * 100000);
			mapOut = mapOut / 100000;
			pos = sin(mapOut)*(y2 - y1);
//			printf( "%i\n", pos);
			sprintf_s(command, 8, "%c%c%c%c%c%c%c", 0x02, x1 - pos - 3, i, x1 - pos, i + curveResolution-1, clow, chigh);
			ser.Write(command, 7);
			sprintf_s(command, 8, "%c%c%c%c%c%c%c", 0x02, x2 + pos, i, x2 + pos + 3, i + curveResolution - 1, clow, chigh);
			ser.Write(command, 7);
		}
	}

	void drawText(int posx, int posy, int fglow, int fghigh, int bglow, int bghigh, int tSize, char* text) {
		char command[100];
		sprintf_s(command, 100, "%c%c%c%c%c%c%c%c", 0x05, posx, posy, tSize, fglow, fghigh, bglow, bghigh);

		int i;
		for (i = 0; (i < tSize) && (i < 8 + tSize); i++) {
			command[8 + i] = text[i];
		}
		ser.Write(command, 8 + tSize);
	}
	void drawText(int posx, int posy, char fg[8], char bg[8], int tSize, char* text) {
		int fglow, fghigh;
		splitColor(hex2col(fg), &fglow, &fghigh);
		int bglow, bghigh;
		splitColor(hex2col(bg), &bglow, &bghigh);

		char command[100];
		sprintf_s(command, 100, "%c%c%c%c%c%c%c%c", 0x05, posx, posy, tSize, fglow, fghigh, bglow, bghigh);

		int i;
		for (i = 0; (i < tSize) && (i < 8 + tSize); i++) {
			command[8 + i] = text[i];
		}
		ser.Write(command, 8 + tSize);
	}

	int readPoti() {
		char command[1] = { 0x06 };
		ser.Write(command, 1);

		char receive[2];
		ser.Readv(receive, 2);

		int i = receive[1] * 256 + receive[0];
		return i;
	}

private:
	int dummy;
	SerialDummy ser;
};

