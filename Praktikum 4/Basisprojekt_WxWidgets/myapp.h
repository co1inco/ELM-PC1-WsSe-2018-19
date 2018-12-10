//***************************************************
// Deklaration der Klasse MyApp (Hauptprogramm)     *
// f�r eine Anwendung mit grafischer Oberfl�che     *
// 3.Tag - f�r Studenten                            *
// Lu Franzen 3.12.2013                             *
//***************************************************

#ifndef MYAPP
#define MYAPP

#include "wx/wx.h"                      // wxWidgets Header
#include "myframe.h" 

class MyApp : public wxApp              // Neue eigene Klasse, erbt von wxApp
{
private:
    MyFrame *frame;                     // Frame

public:
    virtual bool OnInit();              // Initialisierung der Anwendung, ist flexibler
                                        // als der Konstruktor, weil R�ckgabewert m�glich
};

#endif