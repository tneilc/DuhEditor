#pragma once
#include "wx/wx.h"
#include "wx/fontdlg.h"
#include "wx/notebook.h"
#include "wx/string.h"
#include "wx/stc/stc.h"

class MeineTextEdit : public wxStyledTextCtrl
{
public:
    MeineTextEdit(wxWindow* parent, wxWindowID id = wxID_ANY,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize, long style = 0,
        const wxString& name = wxSTCNameStr);

public:
    bool isSaved;
    wxString filepath;

 
};

