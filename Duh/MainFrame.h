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
    
    void OnSave(wxCommandEvent& event);
    void OnSaveAs(wxCommandEvent& event); // the click event for "save"
    void OnOpen(wxCommandEvent& event); // the click event for "open"

    wxString OpenFilePath;

    enum MenuIDs {
        IdSave = 1000,IdSaveAs,IdOpen
    };

	wxDECLARE_EVENT_TABLE();

};
