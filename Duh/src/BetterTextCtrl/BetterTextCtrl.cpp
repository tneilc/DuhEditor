#include "BetterTextCtrl.h"

BetterTextCtrl::BetterTextCtrl(wxWindow* parent, wxWindowID id,
    const wxString& value,
    const wxPoint& pos,
    const wxSize& size,
    long style,
    const wxValidator& validator,
    const wxString& name) : wxTextCtrl(parent, id, value, pos, size, style, validator, name) {

    this->isSaved = false;
    this->filepath = " ";
}