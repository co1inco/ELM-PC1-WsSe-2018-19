#include "colorLib.h"
#include <iostream>

using namespace std;


char red[] = "#ff0000";
char green[] = "#00ff00";
char blue[] = "#0000ff";
char black[] = "#000000";
char white[] = "#ffffff";
char grey[] = "#7d7d7d";
char orange[] = "#ff8000";


long map(long value, long x1, long x2, long y1, long y2) {
	return (value - x1) * (y2 - y1) / (x2 - x1) + y1;
}


int hex2col(int redV, int greenV, int blueV) {
	int colors = 0x0000;
	colors = colors | (map(redV, 0, 255, 0, 31) << 11),
	colors = colors | (map(greenV, 0, 255, 0, 63) << 5);
	colors = colors | (map(blueV, 0, 255, 0, 31));
	return colors;
}
int hex2col(char colorS[8]) {
	int redV, greenV, blueV;
	sscanf(colorS, "#%2x%2x%2x", &redV, &greenV, &blueV);
	int color = 0x0000;
	
	color = color | (map(redV, 0, 255, 0, 31) << 11),
	color = color | (map(greenV, 0, 255, 0, 63) << 5);
	color = color | (map(blueV, 0, 255, 0, 31));
	
	return color;
}


void splitColor(int color[2]) {
	color[1] = color[0] % 0x100;
	color[0] = color[0] / 0x100;
}
void splitColor(int c, int* c1, int* c2) {
	*c1 = c / 0x100;
	*c2 = c % 0x100;
}


/*
def printColor(c1, c2 = -1, c3 = -1) :
	if c2 == -1 :
		print("%6x" % c1)
		elif c3 == -1 :
		print("%02x %02x" % (c1, c2))
	else :
		print("%02x %02x %02x" % (c1, c2, c3))
*/



