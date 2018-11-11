//*****************************************
// C++-Praktikum: Tag 1				*
// Rahmenprogramm für die Studierenden	*
// Lu Franzen, 30.10.2014			*
//*****************************************

#include <iostream>
using namespace std;


#include "colorLib.h" 
#include "Display.h"

#include <string>


#define DISP_WIDTH (175)
#define DISP_HEIGHT (132-20)

#define POS_TEXT1 (30)


/*
long map(long x, long in_min, long in_max, long out_min, long out_max)
{
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
*/






void main()
{
	bool openSuccsess = false;
	Display dsp(1);
	openSuccsess = dsp.init();
	std::cout << "Serial connection: " << openSuccsess << "\n";

	if (openSuccsess) {
		bool runMainloop = true;

		char* bgColor = red;
		char* potiDesFg = black;
		char* potiDesBg = bgColor;
		char* potiRecFg = black;
		char* potiTxtFg = black;
		char* potiTxtBg = bgColor;
		char* voltDesFg = black;
		char* voltDesBg = bgColor;
		char* voltRecFg = black;
		char* voltTxtFg = black;
		char* voltTxtBg = bgColor;
		char* diaRecFg = black;
		char* diaLeftFg = blue;
		char* diaRightFg = bgColor;


		int poti = 0;
		int diaWidth = 0;
		char potiTxt[5];
		int potiVolt = 0;
		char voltTxt[5] = "5.00";

		int gelesen_xPos = 20;
		int volt_xPos = 95;
		int text_yPos = 20;
		int num_xPos = 40;

		int dia_yPos = 80;


		dsp.clearScreen(bgColor);

		dsp.drawRectangle(0, 0, DISP_WIDTH, DISP_HEIGHT, black, 5);

		char gelesen[] = "gelesen";
		dsp.drawText(gelesen_xPos, text_yPos, potiDesFg, potiDesBg, sizeof(gelesen), gelesen);
		dsp.drawRectangle(gelesen_xPos, num_xPos, gelesen_xPos + sizeof(gelesen) * 7, 70, potiRecFg, 3);


		char sVolt[] = "in Volt";
		dsp.drawText(volt_xPos, text_yPos, voltDesFg, voltDesBg, sizeof(sVolt), sVolt);
		dsp.drawRectangle(volt_xPos, num_xPos, volt_xPos + sizeof(sVolt) * 7, 70, voltRecFg, 3);


		dsp.drawRectangle(gelesen_xPos, dia_yPos, volt_xPos + sizeof(sVolt) * 7, dia_yPos + 20, diaRecFg, 4);

		while (runMainloop) {

			poti = dsp.readPoti();
			std::cout << poti << '\n';

			sprintf(potiTxt, "%04i ", poti);
			dsp.drawText(gelesen_xPos + 14, text_yPos + 29, potiTxtFg, potiTxtBg, sizeof(potiTxt), potiTxt);

			potiVolt = map(poti, 0, 1023, 0, 500);
			sprintf(voltTxt, "%i.%i", potiVolt / 100, potiVolt % 100);
			dsp.drawText(volt_xPos + 15, text_yPos + 29, voltTxtFg, voltTxtBg, sizeof(voltTxt), voltTxt);

			diaWidth = map(poti, 0, 1023, gelesen_xPos + 4, volt_xPos + sizeof(sVolt) * 7 - 4);
			dsp.drawRectangle(diaWidth, dia_yPos + 4 + 2, volt_xPos + sizeof(sVolt) * 7 - 4, dia_yPos + 14, diaRightFg);
			dsp.drawRectangle(gelesen_xPos + 4, dia_yPos + 4 + 2, diaWidth, dia_yPos + 14, diaLeftFg);

			Sleep(10);
			runMainloop = false;
		}

		dsp.close();
	}


/*
	int color = hex2col(green);
	int c1, c2;
	splitColor(color, &c1, &c2);
	printf("%02x %02x\n", c1, c2);

	int color1[2] = { hex2col(green),0 };
	splitColor(color1);
	printf("%02x %02x\n", color1[0], color1[1]);

	std::cout << hex2col(255,0,0);

*/

	int i;
	std::cin >> i;

}
