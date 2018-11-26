//***************************************************
// Deklaration der Klasse MyFrame (Hauptrahmen)     *
// 3.Tag - für Studenten                            *
// Lu Franzen 3.12.2013                             *
//***************************************************

#ifndef MYFRAME
#define MYFRAME

#include "wx/wx.h"                      // wxWidgets Header

enum                                    // Namen definieren für die Ereignisse (Events)
{
    EventExit                           // Zeile Exit (im Datei-Menü)
};

class MyFrame : public wxFrame          // Definition der Klasse MyFrame (abgeleitet von wxFrame)
{
private:
    wxMenuBar *menuBar;                 // Menu-Zeile 
    wxMenu* dateiMenu;                  // Eintrag in der Menu-Zeile
                                            
    void OnExit(wxCommandEvent& event); // Event Handler

	void Edit(wxCommandEvent& event);
	void Help(wxCommandEvent& event);

    DECLARE_EVENT_TABLE()               // Makro, notwendig für Events, wie Mausklicks, etc.

public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);     // Konstruktor
};

#endif