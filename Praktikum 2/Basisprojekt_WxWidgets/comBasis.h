//***************************************
// ComBasis.h							*
// Com-Basisklasse: Klassendefinition	*
// Lu Franzen, 24.10.2011				*
//***************************************

#ifndef COMBASIS
#define COMBASIS

#include "wx/ctb-0.13/iobase.h"			// interne H-Dateien 
#include "wx/ctb-0.13/serport.h"
#include "wx/ctb-0.13/timer.h"

class comBasis
{
private:
	wxIOBase* port;						// notwenidg für die I/O-Befehle
		
public:
	comBasis();
	~comBasis();

	wxIOBase* givePort();				// gibt den Port zurück
	bool openCom ();					// Öffnen des COM-Ports
	void closeCom ();					// Schließen des COM-Ports
};

#endif
