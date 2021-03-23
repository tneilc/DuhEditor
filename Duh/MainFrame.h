#pragma once
#include "wx/wx.h"
#include "wx/fontdlg.h"
#include <iostream>



class MainFrame : public wxFrame
{
public:
	MainFrame();
	~MainFrame();
public:
    wxMenuBar* menu; 
    wxMenu* file; 
    wxMenu* settings;
    wxTextCtrl* text;
    
    
    void OnSave(wxCommandEvent& event);
    void OnSaveAs(wxCommandEvent& event); // the click event for "save"
    void OnOpen(wxCommandEvent& event); // the click event for "open"
    void OnChangeStyle(wxCommandEvent& event);

    wxString OpenFilePath;

    enum MenuIDs {
        IdStyle,IdPreferences,IdSave = 1000,IdSaveAs,IdOpen
    };

	wxDECLARE_EVENT_TABLE();

};
