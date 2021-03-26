#pragma once
#include "wx/wx.h"
#include "wx/string.h"

class BetterTextCtrl : public wxTextCtrl
{
public:
    BetterTextCtrl(wxWindow* parent, wxWindowID id,
        const wxString& value = wxEmptyString,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = 0,
        const wxValidator& validator = wxDefaultValidator,
        const wxString& name = wxASCII_STR(wxTextCtrlNameStr));
public:
    
    bool isSaved;
    wxString filepath;
    
};

