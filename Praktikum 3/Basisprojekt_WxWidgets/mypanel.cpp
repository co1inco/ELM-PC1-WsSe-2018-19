//***************************************************
// Methoden der Klassen MyPanel                     *
// 3.Tag - für Studenten                            *
// Lu Franzen 3.12.2013                             *
//***************************************************

#include "mypanel.h"

BEGIN_EVENT_TABLE(MyPanel, wxPanel)     // Die Event-Table verbindet die Events mit den Event-Handlern
	EVT_LEFT_DOWN(MyPanel::OnMouseLeftDown)
END_EVENT_TABLE()
    
                                        // Konstruktor
MyPanel::MyPanel(wxWindow *parent, wxWindowID id, const wxPoint& pos, const wxSize& size)
	: wxPanel(parent, id, pos, size)
{
}


void MyPanel::OnMouseLeftDown(wxMouseEvent& event)
{
}