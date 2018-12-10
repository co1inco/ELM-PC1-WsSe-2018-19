//***************************************************
// Methoden der Klasse MyFrame                      *
// 3.Tag - für Studenten                            *
// Lu Franzen 3.12.2013                             *
//***************************************************

#include <iostream>
#include <string>

#include "myapp.h"
#include "myframe.h"
#include "mypanel.h"

BEGIN_EVENT_TABLE(MyFrame, wxFrame)         // Die Event-Table verbindet die Events mit den Event-Handlern
    EVT_MENU(EventExit,  MyFrame::OnExit)   // Klickt man im Datei-Menü auf Exit, so 
                                            // wird der Event-Handler OnExit ausgeführt
	EVT_MENU(wxID_HELP, MyFrame::Help)
	EVT_MENU(wxID_SAVE, MyFrame::test)
	EVT_MENU(wxID_NEW, MyFrame::test)
	EVT_MENU(wxID_UNDO, MyFrame::UndoAct)
	EVT_MENU(wxID_INFO, MyFrame::OnAbout)
	EVT_MENU(wxID_REDO, MyFrame::RedoAct)
	EVT_BUTTON(666, MyFrame::test)
	EVT_BUTTON(667, MyFrame::test)
	END_EVENT_TABLE()

// ----------------------------------------------------------------------------
// Frame-Definition
// ----------------------------------------------------------------------------

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)     // Konstruktor
       : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    SetIcon(wxICON(sample));                // setze das frame icon

    // die Menu-Zeile aubauen
    
	initMenubar();

    // Status-Zeile
	initStatusbar();

	initBody();
}

void MyFrame::initStatusbar() {
	CreateStatusBar(3);

	SetStatusText("Das ist die Statuszeile", 0);

	wxDateTime ActualTime = wxDateTime::Now();	// aktuelles Datum + Uhrzeit holen
	wxString stringDate = ActualTime.FormatISODate();   // Datum herausfiltern 
	SetStatusText(stringDate, 1);               // und anzeigen

	wxString stringTime = ActualTime.FormatISOTime();
	SetStatusText(stringTime, 2);

}

void MyFrame::initMenubar() {
	menuBar = new wxMenuBar(); 

	dateiMenu = new wxMenu;                
	menuBar->Append(dateiMenu, "&Datei");
	dateiMenu->Append(wxID_SAVE, "&Speichern");
	dateiMenu->Append(wxID_NEW, "&Neu", "Python wäre besser");
	dateiMenu->Append(EventExit, "E&xit\tAlt-X", "Programm beenden");

	editMenu = new wxMenu;
	menuBar->Append(editMenu, "&Bearbeiten");
	editMenu->Append(wxID_UNDO, "&Rückgängig", "Mach C++ Rückgängig");
	editMenu->Append(wxID_REDO, "&Wiederherstellen", "Falsche richtung buddy");

	extraMenu = new wxMenu;
	menuBar->Append(extraMenu, "&Extra");
	extraMenu->Append(wxID_HELP, "&Hilfe", "Die brauchst du auch. Du benutzt C++.");
	extraMenu->Append(wxID_INFO, "&Info", "Comment not available");

	SetMenuBar(menuBar);

}

void MyFrame::initBody() {

	but1 = new wxButton(this, 666, "Button1", wxPoint(20, 20));
	but2 = new wxButton(this, 667, "Button2", wxPoint(80, 60), wxSize(60, 60));

	panel1 = new MyPanel(this, 801, wxPoint(200, 5), wxSize(200, 490));
	panel2 = new MyPanel2(this, 802, wxPoint(450, 5), wxSize(50, 490));
}

// ----------------------------------------------------------------------------
// Event Handler: was passiert, wenn man mit der Maus auf ein Event klickt
// ----------------------------------------------------------------------------

void MyFrame::OnExit(wxCommandEvent& WXUNUSED(event))
{
    Close(true);                            // Frame wird geschlossen
}

void MyFrame::Help(wxCommandEvent& WXUNUSED(event))
{
	return;
}

void MyFrame::RedoAct(wxCommandEvent& WXUNUSED(event)) {
	if (wxID_YES == wxMessageDialog(this, wxT("Do you realy want do redo your action"), wxT("REDO"), wxYES_NO).ShowModal()) {
		while (true) {
			if (wxID_NO == wxMessageDialog(this, wxT("Are you sure"), wxT("REDO"), wxYES_NO).ShowModal()) {
				break;
			}
		}
	}

}

void MyFrame::UndoAct(wxCommandEvent& WXUNUSED(event)) {
	if (wxID_NO == wxMessageDialog(this, wxT("Do you realy want to undo your action"), wxT("UNDO"), wxYES_NO).ShowModal()) {
		while (true) {
			if (wxID_YES == wxMessageDialog(this, wxT("Are you sure"), wxT("UNDO"), wxYES_NO).ShowModal()) {
				break;
			}
		}
	}

}

void MyFrame::test(wxCommandEvent& WXUNUSED(event)) {
	wxMessageBox(wxString::Format("test"));
}

                                           // Dieser Event-Handler wird später gebraucht
void MyFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    wxMessageBox(wxString::Format         // Ausgabe einer Messagebox
                 ("Die %d. Zeile der Messagebox\n"
                  "es koennen noch weitere folgen", 1),
                  "Titelzeile der Messagebox");
}

