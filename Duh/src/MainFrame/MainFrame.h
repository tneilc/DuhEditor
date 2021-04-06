#pragma once
#include "wx/wx.h"
#include "wx/fontdlg.h"
#include "wx/notebook.h"
#include "wx/string.h"
#include "wx/stc/stc.h"
#include "../MeineTextEdit/MeineTextEdit.h"
#include "../Preferences/prefDialog.h"
#include "../BetterTextCtrl/BetterTextCtrl.h"
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
    wxPanel* panel;
    wxNotebook* noteBook;
    wxBoxSizer* panelSizer;

    

    void OnSave(wxCommandEvent& event);
    void OnSaveAs(wxCommandEvent& event); 
    void OnOpen(wxCommandEvent& event); 
    void OnNewFile(wxCommandEvent& event);
    void OnChangeStyle(wxCommandEvent& event);
    void PreferencesOpen(wxCommandEvent& event);
    void AddToNoteBook(wxCommandEvent& event, wxFileDialog* openDialog);
    bool doesExist();



    enum MenuIDs {
        IdStyle,IdPreferences,IdSave = 1000,IdSaveAs,IdOpen,IdNewFile
    };

	wxDECLARE_EVENT_TABLE();

};
