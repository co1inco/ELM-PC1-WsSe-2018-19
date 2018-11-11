#pragma once

extern char red[];
extern char green[];
extern char blue[];
extern char white[];
extern char black[];
extern char grey[];
extern char orange[];

long map(long value, long x1, long x2, long y1, long y2);
//	(x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;

int hex2col(int redV, int greenV, int blueV);
int hex2col(char colorS[8]);

void splitColor(int color[2]);
void splitColor(int c, int* c1, int* c2);


//	color[1] = int(("%04x" % color)[2:4], 0x10), int(("%04x" % color)[0:2], 0x10)
/*
def printColor(c1, c2 = -1, c3 = -1) :
if c2 == -1 :
print("%6x" % c1)
elif c3 == -1 :
print("%02x %02x" % (c1, c2))
else :
print("%02x %02x %02x" % (c1, c2, c3))
*/