//***************************************************
// Methoden der Klasse MyFrame                      *
// 3.Tag - f�r Studenten                            *
// Lu Franzen 3.12.2013                             *
//***************************************************

#include "myapp.h"
#include "myframe.h"

BEGIN_EVENT_TABLE(MyFrame, wxFrame)         // Die Event-Table verbindet die Events mit den Event-Handlern
    EVT_MENU(EventExit,  MyFrame::OnExit)   // Klickt man im Datei-Men� auf Exit, so 
                                            // wird der Event-Handler OnExit ausgef�hrt
END_EVENT_TABLE()

// ----------------------------------------------------------------------------
// Frame-Definition
// ----------------------------------------------------------------------------

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)     // Konstruktor
       : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    SetIcon(wxICON(sample));                // setze das frame icon

    // die Menu-Zeile aubauen
    menuBar = new wxMenuBar();              // hier wird die Men�-Zeile erzeugt
                                            
    dateiMenu = new wxMenu;                 // neuer Eintrag in der Men�-Zeile
    menuBar->Append(dateiMenu, "&Datei");
    SetMenuBar(menuBar);  


    // Pulldown-Men� aufbauen 
    dateiMenu->Append(EventExit, "E&xit\tAlt-X", "Programm beenden"); 
                                            // f�r jede neue Zeile 1x Append

    // Status-Zeile
    CreateStatusBar(2);                         // erzeugt die Statuszeile 
    SetStatusText("Das ist die Statuszeile",0); 
    
    wxDateTime ActualTime = wxDateTime::Now();	// aktuelles Datum + Uhrzeit holen
    wxString stringDate = ActualTime.FormatISODate();   // Datum herausfiltern 
    SetStatusText(stringDate, 1);               // und anzeigen
}

// ----------------------------------------------------------------------------
// Event Handler: was passiert, wenn man mit der Maus auf ein Event klickt
// ----------------------------------------------------------------------------

void MyFrame::OnExit(wxCommandEvent& WXUNUSED(event))
{
    Close(true);                            // Frame wird geschlossen
}

/*                                            // Dieser Event-Handler wird sp�ter gebraucht
void MyFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    wxMessageBox(wxString::Format         // Ausgabe einer Messagebox
                 ("Die %i. Zeile der Messagebox\n"
                  "es koennen noch weitere folgen", 1),
                  "Titelzeile der Messagebox");
}*/
