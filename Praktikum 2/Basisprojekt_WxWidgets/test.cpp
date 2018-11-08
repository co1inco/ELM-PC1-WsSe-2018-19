//*****************************************
// C++-Praktikum: Tag 1				*
// Rahmenprogramm für die Studierenden	*
// Lu Franzen, 30.10.2014			*
//*****************************************

#include <iostream>
using namespace std;

#include "comBasis.h"			    // Einbinden der Com-Klasse
 
#include <string>


#define DISP_WIDTH (175)
#define DISP_HEIGHT (132-20)

#define POS_TEXT1 (30)

long map(long x, long in_min, long in_max, long out_min, long out_max)
{
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

class Serial {
public:
	Serial(int d) : dummy(d) {};

	bool  open() {
//		port = ser.givePort();           // hole die Port-Adresse
//		return ser.openCom();
		return true;
	}
	void close() {
		std::cout << "Connection closed\n";
//		ser.closeCom();
	}
	void write(char* command, int length) {
		int i;
		char s[8];
		sprintf(s, "%2i | ", length);
		std::cout << "Command: " << s;
		for (i = 0; i < length; i++) {
			std::cout << command[i];
		}
		std::cout << "\n";
//		port->Write(command, length);
	}
	void Write(char* command, int length) {
		write(command, length);
	}
	void read(char* receive, int length) {
		receive[0] = 254;
		receive[1] = 0;
//		port->Readv(receive, length, NULL, false);
	}
	void Read(char* receive, int length) {
		read(receive, length);
	}
	void Readv(char* receive, int length) {
		read(receive, length);
	}

private:
	int dummy;
//	wxIOBase * port;			    // notwendig für die I/O-Befehle
//	comBasis ser;                    // Objekt für die Kommunkikation anlegen

};

class Display {
public:
	Display(int d) :dummy(d), ser(1){};

	bool init() {
		return ser.open();
	}
	void close() {
		ser.close();
	}
	void clearScreen() {
		char command[4];
		sprintf(command, "%c%c%c", 0x00, 0x00, 0x00);
		ser.Write(command, 3);
	}
	void clearScreen(char clow, char chigh) {
		char command[4];
		sprintf(command, "%c%c%c", 0x00, clow, chigh);
		ser.Write(command, 3);
	}

	void drawRectangle(int posx1, int posy1, int posx2, int posy2, char clow, char chigh, int width) {
		char command[9];
		sprintf(command, "%c%c%c%c%c%c%c%c", 0x03, posx1, posy1, posx2, posy2, clow, chigh, width);
		ser.Write(command, 8);
	}

	void drawRectangle( int posx1, int posy1, int posx2, int posy2, char clow, char chigh) {
		char command[8];
		sprintf(command, "%c%c%c%c%c%c%c", 0x02, posx1, posy1, posx2, posy2, clow, chigh);
		ser.Write(command, 7);
	}

	void drawText(int posx, int posy, int fglow, int fghigh, int bglow, int bghigh, int tSize, char* text) {
		char command[100];
		sprintf(command, "%c%c%c%c%c%c%c%c", 0x05, posx, posy, tSize, fglow, fghigh, bglow, bghigh);

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
	Serial ser;
};



void main()
{
	bool openSuccsess = false;
	Display dsp(1);
	openSuccsess = dsp.init();
	std::cout << "Serial connection: " << openSuccsess << "\n";

	if (openSuccsess){
		bool runMainloop = true;
	
		dsp.clearScreen(0xff, 0xff);

		dsp.drawRectangle(0, 0, DISP_WIDTH, DISP_HEIGHT, 0x00, 0x00, 5);
		
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

		char gelesen[] = "gelesen";
		dsp.drawText(gelesen_xPos, text_yPos, 0x00, 0x00, 0xff, 0xff, sizeof(gelesen), gelesen);
		dsp.drawRectangle(gelesen_xPos, num_xPos, gelesen_xPos + sizeof(gelesen) * 7, 70, 0x00, 0xf8, 3);


		char sVolt[] = "in Volt";
		dsp.drawText(volt_xPos, text_yPos, 0x00, 0x00, 0xff, 0xff, sizeof(sVolt), sVolt);
		dsp.drawRectangle(volt_xPos, num_xPos, volt_xPos+sizeof(sVolt) * 7, 70, 0x1f, 0x00, 3);
		

		dsp.drawRectangle(gelesen_xPos, dia_yPos, volt_xPos+sizeof(sVolt)*7, dia_yPos + 20, 0x00, 0x00, 4);

		while (runMainloop){

			poti = dsp.readPoti();
			std::cout << poti << '\n';

			sprintf(potiTxt, "%04i ", poti);
			dsp.drawText( gelesen_xPos + 14, text_yPos + 29, 0x00, 0x00, 0xff, 0xff, sizeof(potiTxt), potiTxt);

			potiVolt = map(poti, 0, 1023, 0, 500);
			sprintf(voltTxt, "%i.%i", potiVolt/100, potiVolt%100);
			dsp.drawText(volt_xPos + 15, text_yPos + 29, 0x00, 0x00, 0xff, 0xff, sizeof(voltTxt), voltTxt);

			diaWidth = map(poti, 0, 1023, gelesen_xPos + 4, volt_xPos + sizeof(sVolt) * 7 - 4);
			dsp.drawRectangle(diaWidth, dia_yPos + 4 + 2, volt_xPos + sizeof(sVolt) * 7 - 4, dia_yPos + 14, 0xff, 0xff);
			dsp.drawRectangle(gelesen_xPos + 4, dia_yPos + 4 + 2, diaWidth, dia_yPos + 14, 0x1f, 0x00);

			Sleep(10);
			runMainloop = false;
		}

	}

	dsp.close();


	int i;
	std::cin >> i;

}
