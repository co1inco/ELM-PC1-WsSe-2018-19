//***************************************************
// Methoden der Klasse MyApp                        *
// 3.Tag - für Studenten                            *
// Lu Franzen 3.12.2013                             *
//***************************************************

#include "myapp.h" 
#include "myframe.h"

IMPLEMENT_APP(MyApp)                        // Dieses Makro erzeugt das Hauptprogramm

// ============================================================================
// Implementierung
// ============================================================================

bool MyApp::OnInit()                        // Das Hauptprogramm startet hier
{
    if (!wxApp::OnInit())                   // Initialisierung
        return false;

                                            // Frame wird erzeugt (Name, Position, Größe)
    frame = new MyFrame("meine erste Test-Anwendung", wxPoint (150,150), wxSize(600,600));
        
    frame->Show(true);                      // und angezeigt

    return true;
}
