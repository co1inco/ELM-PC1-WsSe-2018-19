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
	void initMenubar();
	void initStatusbar();
	void initBody();

    wxMenuBar *menuBar;                 // Menu-Zeile 
    wxMenu* dateiMenu;                  // Eintrag in der Menu-Zeile
	wxMenu* editMenu;
	wxMenu* extraMenu;

	wxButton *but1;
	wxButton *but2;

	wxPanel *panel1; 
	wxPanel *panel2;
                                            
    void OnExit(wxCommandEvent& event); // Event Handler

	void Edit(wxCommandEvent& event);
	void Help(wxCommandEvent& event);
	void test(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	void RedoAct(wxCommandEvent& event);
	void UndoAct(wxCommandEvent& event);

    DECLARE_EVENT_TABLE()               // Makro, notwendig für Events, wie Mausklicks, etc.

public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);     // Konstruktor
	
};


#endif