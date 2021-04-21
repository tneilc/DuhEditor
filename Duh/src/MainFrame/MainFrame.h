#pragma once
#include "wx/wx.h"
#include "wx/fontdlg.h"
#include "wx/notebook.h"
#include "wx/string.h"
#include "wx/stc/stc.h"
#include "../Customs/MeineTextEdit/MeineTextEdit.h"
#include "../Preferences/prefDialog.h"
#include "../BetterTextCtrl/BetterTextCtrl.h"
#include <wx/filename.h>
#include <wx/aui/auibook.h>
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
    wxAuiNotebook* noteBook;
    wxBoxSizer* panelSizer;
    wxBoxSizer* Sizer;

    

    void OnSave(wxCommandEvent& event);
    void OnSaveAs(wxCommandEvent& event); 
    void OnOpen(wxCommandEvent& event); 
    void OnNewFile(wxCommandEvent& event);
    void PreferencesOpen(wxCommandEvent& event);
    void AddToNoteBook(wxCommandEvent& event, wxFileDialog* openDialog);
    void CloseFile(wxCommandEvent& event);


    bool doesExist();



    enum MenuIDs {
        IdStyle,IdPreferences,
        IdSave = 1000,IdSaveAs,IdOpen,IdNewFile,
        IdCloseFile,
        MenuID,NoteBookID
    };

	wxDECLARE_EVENT_TABLE();

};
