#pragma once
#include "wx/wx.h"
#include <iostream>



class MainFrame : public wxFrame
{
public:
	MainFrame();
	~MainFrame();
public:
    wxMenuBar* menu; 
    wxMenu* file; 
    wxTextCtrl* text;

    void OnSave(wxCommandEvent& event); // the click event for "save"
    void OnOpen(wxCommandEvent& event); // the click event for "open"



    enum MenuIDs {
        IdSave = 1000,IdOpen
    };

	wxDECLARE_EVENT_TABLE();

};
