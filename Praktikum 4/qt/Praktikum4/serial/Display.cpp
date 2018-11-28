#pragma once

#include "Serial.h"
#include <math.h>
#include <iostream>
#include <string>
#include "colorLib.h"
#include "Display.h"

#define PI 3.14159265


Display::Display(){
    ser = new SerialDummy();
}
Display::~Display(){

}

bool Display::init() {
    return ser->open();
}
void Display::close() {
        ser->close();
}

void Display::clearScreen() {
	char command[4];
	sprintf_s(command, 4, "%c%c%c", 0x00, 0x00, 0x00);
    ser->Write(command, 3);
}
void Display::clearScreen(char clow, char chigh) {
	char command[4];
	sprintf_s(command, 4, "%c%c%c", 0x00, clow, chigh);
    ser->Write(command, 3);
}
void Display::clearScreen(char c[8]) {
	int c1, c2;
	splitColor(hex2col(c), &c1, &c2);
	char command[4];
	sprintf_s(command, 4, "%c%c%c", 0x00, c1, c2);
    ser->Write(command, 3);
}

void Display::drawRectangle(int posx1, int posy1, int posx2, int posy2, char clow, char chigh, int width) {
	char command[9];
	sprintf_s(command, 9, "%c%c%c%c%c%c%c%c", 0x03, posx1, posy1, posx2, posy2, clow, chigh, width);
    ser->Write(command, 8);
}
void Display::drawRectangle(int posx1, int posy1, int posx2, int posy2, char c[8], int width) {
	int clow, chigh;
	splitColor(hex2col(c), &clow, &chigh);
	char command[9];
	sprintf_s(command, 9, "%c%c%c%c%c%c%c%c", 0x03, posx1, posy1, posx2, posy2, clow, chigh, width);
    ser->Write(command, 8);
}

void Display::drawRectangle(int posx1, int posy1, int posx2, int posy2, char clow, char chigh) {
	char command[8];
	sprintf_s(command, 8, "%c%c%c%c%c%c%c", 0x02, posx1, posy1, posx2, posy2, clow, chigh);
    ser->Write(command, 7);
}
void Display::drawRectangle(int posx1, int posy1, int posx2, int posy2, char c[8]) {
	int clow, chigh;
	splitColor(hex2col(c), &clow, &chigh);
	char command[8];
	sprintf_s(command, 8, "%c%c%c%c%c%c%c", 0x02, posx1, posy1, posx2, posy2, clow, chigh);
    ser->Write(command, 7);
}

void Display::drawBalken(int x1, int y1, int x2, int y2, char cFg[8], char cBg[8], int value, int valueMax) {
	int xPos = map(value, 0, valueMax, x1, x2);

	drawRectangle(x1, y1, xPos, y2, cFg);
	if (xPos <= x2) {
		drawRectangle(xPos, y1, x2, y2, cBg);
	}
}

void Display::drawOval(int x1, int y1, int x2, int y2, char c[8], int width, bool keepWidth) {
	int clow, chigh;
	splitColor(hex2col(c), &clow, &chigh);

	if (keepWidth == true) {
		x1 = x1 + ((y2 - y1) / 2);
		x2 = x2 - ((y2 - y1) / 2);
	}

	char command[8];
	sprintf_s(command, 8, "%c%c%c%c%c%c%c", 0x02, x1, y1, x2, y1 + width, clow, chigh);
    ser->Write(command, 7);
	sprintf_s(command, 8, "%c%c%c%c%c%c%c", 0x02, x1, y2 - width, x2, y2, clow, chigh);
    ser->Write(command, 7);
	int curveResolution = 2;

	int i;
	int pos;
	double mapOut;
	for (i = y1 + 1; i < y2; i += curveResolution) {
		mapOut = map(i, y1, y2, 0, PI * 100000);
		mapOut = mapOut / 100000;
		pos = sin(mapOut)*((y2 - y1) / 2);
		//			printf( "%i\n", pos);
		sprintf_s(command, 8, "%c%c%c%c%c%c%c", 0x02, x1 - pos - 3, i, x1 - pos, i + curveResolution - 1, clow, chigh);
        ser->Write(command, 7);
		sprintf_s(command, 8, "%c%c%c%c%c%c%c", 0x02, x2 + pos, i, x2 + pos + 3, i + curveResolution - 1, clow, chigh);
        ser->Write(command, 7);
	}
}

void Display::drawText(int posx, int posy, int fglow, int fghigh, int bglow, int bghigh, char* text) {
	char command[100];
	int tSize = strlen(text);
	sprintf_s(command, 100, "%c%c%c%c%c%c%c%c%s", 0x05, posx, posy, tSize, fglow, fghigh, bglow, bghigh, text);
    ser->Write(command, 8 + tSize);
}
void Display::drawText(int posx, int posy, char fg[8], char bg[8], char* text) {
	int fglow, fghigh;
	splitColor(hex2col(fg), &fglow, &fghigh);
	int bglow, bghigh;
	splitColor(hex2col(bg), &bglow, &bghigh);

	int tSize = strlen(text);
	char command[100];
	sprintf_s(command, 100, "%c%c%c%c%c%c%c%c%s", 0x05, posx, posy, tSize, fglow, fghigh, bglow, bghigh, text);
    ser->Write(command, 8 + tSize);
}

int Display::readPoti() {
	char command[1] = { 0x06 };
    char receive[3];
    ser->Write(command, 1);

    ser->Readv(receive, 2);

    int j =receive[1];
    if (j < 0){
        j = (j*-1) + (256/2);
    }
    int k =receive[0];
    if (k < 0){
        k = (k*-1) + (256/2);
    }

    int i = j * 256 + k;  //256
    return i;
//    return j; //only for serial dummy!!
}

