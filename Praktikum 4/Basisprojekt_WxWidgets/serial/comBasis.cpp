//*******************************************
// ComBasis.cpp								*
// Com-Basisklasse: Definition der Methoden	*
// Lu Franzen, 24.10.2011					*
//*******************************************

#include "comBasis.h"

comBasis::comBasis()					// Konstruktor
{
//	port = new wxSerialPort();			// serial port anlegen
}

comBasis::~comBasis()					// Destruktor
{
	delete port;	
}

wxIOBase* comBasis::givePort()			// gibt den Port zur�ck
{
	return port;
}

bool comBasis::openCom ()				// �ffnen des COM-Ports
{
	wxBaud baudrate;
	char devname[64];

	baudrate = wxBAUD_9600;
	sprintf (devname, wxCOM6);

	if(port -> Open(devname) < 0)		// Versuch, COM-Port zu �ffnen
	{
		return false;
	}
	else
	{	
		((wxSerialPort*)port) -> SetBaudRate(baudrate);		// baudrate setzten
		return true;
	}
}

void comBasis::closeCom ()				// Schlie�en des COM-Ports
{
	port -> Close();
}

