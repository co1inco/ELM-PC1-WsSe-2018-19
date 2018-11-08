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

//Aufgabe 4.3.2
void clearScreen(wxIOBase* port){
	char command[4];
	sprintf(command, "%c%c%c", 0x00, 0x00, 0x00);
	port->Write(command, 3);
}
void clearScreen(wxIOBase* port, char clow, char chigh){
	char command[4];
	sprintf(command, "%c%c%c", 0x00, clow, chigh);
	port->Write(command, 3);
}

void drawRectangle(wxIOBase* port, int posx1, int posy1, int posx2, int posy2, char clow, char chigh, int width){
	char command[9];
	sprintf(command, "%c%c%c%c%c%c%c%c",0x03, posx1, posy1, posx2, posy2, clow, chigh, width);
	port->Write(command, 8);
}

void drawRectangle(wxIOBase* port, int posx1, int posy1, int posx2, int posy2, char clow, char chigh){
	char command[8];
	sprintf(command, "%c%c%c%c%c%c%c", 0x02, posx1, posy1, posx2, posy2, clow, chigh);
	port->Write(command, 7);
}

void drawText(wxIOBase* port, int posx, int posy, int fglow, int fghigh, int bglow, int bghigh, int tSize, char* text){
	char command[100];
	sprintf(command, "%c%c%c%c%c%c%c%c", 0x05, posx, posy, tSize, fglow, fghigh, bglow, bghigh);
	
	int i;
	for (i = 0; (i < tSize) && (i < 8+tSize); i++){
		command[8 + i] = text[i];
	}
	port->Write(command, 8+tSize);
}

int readPoti(wxIOBase* port){
	char command[1] = { 0x06 };
	port->Write(command, 1);
	
	char receive[2];
	port->Readv(receive, 2, NULL, false);

	int i = receive[1]*256 + receive[0];
	return i;
}

void main()
{
	wxIOBase* port;			    // notwendig für die I/O-Befehle

	comBasis com1;                    // Objekt für die Kommunkikation anlegen

	port = com1.givePort();           // hole die Port-Adresse


	bool openSuccsess = false;

	//Aufgabe 4.3.1
	openSuccsess = com1.openCom();

	std::cout << openSuccsess;

	if (openSuccsess){
		//Aufgabe 4.3.2
		clearScreen(port, 0xff, 0xff);

		//Aufgabe 4.3.3

		drawRectangle(port, 0, 0, DISP_WIDTH, DISP_HEIGHT, 0x00, 0x00, 5);
		
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
		drawText(port, gelesen_xPos, text_yPos, 0x00, 0x00, 0xff, 0xff, sizeof(gelesen), gelesen);
		drawRectangle(port, gelesen_xPos, num_xPos, gelesen_xPos + sizeof(gelesen) * 7, 70, 0x00, 0xf8, 3);


		char sVolt[] = "in Volt";
		drawText(port, volt_xPos, text_yPos, 0x00, 0x00, 0xff, 0xff, sizeof(sVolt), sVolt);
		drawRectangle(port, volt_xPos, num_xPos, volt_xPos+sizeof(sVolt) * 7, 70, 0x1f, 0x00, 3);
		

		drawRectangle(port, gelesen_xPos, dia_yPos, volt_xPos+sizeof(sVolt)*7, dia_yPos + 20, 0x00, 0x00, 4);

		while (true){

			poti = readPoti(port);
			std::cout << poti << '\n';

			sprintf(potiTxt, "%04i ", poti);
			drawText(port, gelesen_xPos + 14, text_yPos + 29, 0x00, 0x00, 0xff, 0xff, sizeof(potiTxt), potiTxt);

			potiVolt = map(poti, 0, 1023, 0, 500);
			sprintf(voltTxt, "%i.%i", potiVolt/100, potiVolt%100);
			drawText(port, volt_xPos + 15, text_yPos + 29, 0x00, 0x00, 0xff, 0xff, sizeof(voltTxt), voltTxt);

			diaWidth = map(poti, 0, 1023, gelesen_xPos + 4, volt_xPos + sizeof(sVolt) * 7 - 4);
			drawRectangle(port, diaWidth, dia_yPos + 4 + 2, volt_xPos + sizeof(sVolt) * 7 - 4, dia_yPos + 14, 0xff, 0xff);
			drawRectangle(port, gelesen_xPos + 4, dia_yPos + 4 + 2, diaWidth, dia_yPos + 14, 0x1f, 0x00);

			Sleep(10);
		}

	}

	com1.closeCom();

	// als erstes muss jetzt die serielle Schnittstelle geöffnet werden
	// das geht mit der openCom-Methode aus der Klasse comBasis

	// und dann kommt der Rest des Algorrithmus
}
