//***************************************************
// Methoden der Klassen MyPanel                     *
// 3.Tag - für Studenten                            *
// Lu Franzen 3.12.2013                             *
//***************************************************

#include "mypanel.h"

BEGIN_EVENT_TABLE(MyPanel, wxPanel)     // Die Event-Table verbindet die Events mit den Event-Handlern
	EVT_LEFT_DOWN(MyPanel::OnMouseLeftDown)
	EVT_RIGHT_DOWN(MyPanel::OnMouseRightDown)
	EVT_ENTER_WINDOW(MyPanel::OnMouseEnter)
	EVT_LEAVE_WINDOW(MyPanel::OnMouseLeave)
END_EVENT_TABLE()
    
                                        // Konstruktor
MyPanel::MyPanel(wxWindow *parent, wxWindowID id, const wxPoint& pos, const wxSize& size)
	: wxPanel(parent, id, pos, size)
{
}


void MyPanel::OnMouseLeftDown(wxMouseEvent& event)
{
	wxMessageBox(wxT("Left"));
}

void MyPanel::OnMouseRightDown(wxMouseEvent& event)
{
	wxMessageBox(wxT("Right mouse"));
}

void MyPanel::OnMouseEnter(wxMouseEvent& event) {
	SetBackgroundColour(*wxGREEN);
	Refresh();
}

void MyPanel::OnMouseLeave(wxMouseEvent& event) {
	SetBackgroundColour(*wxWHITE);
	Refresh();
}



BEGIN_EVENT_TABLE(MyPanel2, wxPanel)     // Die Event-Table verbindet die Events mit den Event-Handlern
	EVT_LEFT_DOWN(MyPanel2::OnMouseLeftDown)
	EVT_RIGHT_DOWN(MyPanel2::OnMouseRightDown)
	EVT_ENTER_WINDOW(MyPanel2::OnMouseEnter)
	EVT_LEAVE_WINDOW(MyPanel2::OnMouseLeave)
END_EVENT_TABLE()

// Konstruktor
MyPanel2::MyPanel2(wxWindow *parent, wxWindowID id, const wxPoint& pos, const wxSize& size)
	: wxPanel(parent, id, pos, size)
{
	SetBackgroundColour(*wxBLUE);
}


void MyPanel2::OnMouseLeftDown(wxMouseEvent& event)
{
	wxMessageBox(wxT("Left"));
}

void MyPanel2::OnMouseRightDown(wxMouseEvent& event)
{
	wxMessageBox(wxT("Right (Panel2)"));
}
void MyPanel2::OnMouseEnter(wxMouseEvent& event) {
	SetBackgroundColour(*wxRED);
	Refresh();
}
void MyPanel2::OnMouseLeave(wxMouseEvent& event) {
	SetBackgroundColour(*wxBLUE);
	Refresh();
}