//***************************************************
// Deklaration der Klasse MyPanel (Teil einer Frame)*
// 3.Tag - für Studenten                            *
// Lu Franzen 3.12.2013                             *
//***************************************************

#ifndef MYPANEL
#define MYPANEL

#include <wx\wx.h>

class MyPanel : public wxPanel
{
public:
	MyPanel(wxWindow *parent, wxWindowID id, const wxPoint& pos, const wxSize& size);

	DECLARE_EVENT_TABLE()

private:
	void OnMouseLeftDown(wxMouseEvent& event);
	void OnMouseRightDown(wxMouseEvent& event);
	void OnMouseEnter(wxMouseEvent& event);
	void OnMouseLeave(wxMouseEvent& event);
};


class MyPanel2 : public wxPanel
{
public:
	MyPanel2(wxWindow *parent, wxWindowID id, const wxPoint& pos, const wxSize& size);

	DECLARE_EVENT_TABLE()

private:
	void OnMouseLeftDown(wxMouseEvent& event);
	void OnMouseRightDown(wxMouseEvent& event);
	void OnMouseEnter(wxMouseEvent& event);
	void OnMouseLeave(wxMouseEvent& event);
};

#endif