#pragma once

#include "comBasis.h"
#include <iostream>

class Serial {
public:
	Serial(int d) : dummy(d) {};

	bool  open() {
		port = ser.givePort();           // hole die Port-Adresse
		return ser.openCom();
	}
	void close() {
		ser.closeCom();
	}

	void write(char* command, int length) {
		port->Write(command, length);
		Sleep(1);
	}
	void Write(char* command, int length) {
		write(command, length);
	}
	void writeCom(char* command, int length) {
		write(command, length);
	}

	void read(char* receive, int length) {
		port->Readv(receive, length, NULL, false);
	}
	void Read(char* receive, int length) {
		read(receive, length);
	}
	void Readv(char* receive, int length) {
		read(receive, length);
	}
	void readCom(char* receive, int length) {
		read(receive, length);
	}

private:
	int dummy;
	wxIOBase * port;			    // notwendig für die I/O-Befehle
	comBasis ser;                    // Objekt für die Kommunkikation anlegen
};





class SerialDummy {
public:
	SerialDummy(int d) : dummy(d) {};

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
		sprintf_s(s, 8, "%2i | ", length);
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
