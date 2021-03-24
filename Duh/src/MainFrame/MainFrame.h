#pragma once
#include "wx/wx.h"
#include "wx/fontdlg.h"
#include "../Preferences/prefDialog.h"
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
    void OnSaveAs(wxCommandEvent& event); 
    void OnOpen(wxCommandEvent& event); 
    void OnChangeStyle(wxCommandEvent& event);
    void PreferencesOpen(wxCommandEvent& event);

    wxString OpenFilePath;
    bool doesExist = false;

    enum MenuIDs {
        IdStyle,IdPreferences,IdSave = 1000,IdSaveAs,IdOpen
    };

	wxDECLARE_EVENT_TABLE();

};
