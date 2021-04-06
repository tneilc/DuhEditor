#include "MeineTextEdit.h"

MeineTextEdit::MeineTextEdit(wxWindow* parent, wxWindowID id,
    const wxPoint& pos,
    const wxSize& size, long style,
    const wxString& name) : wxStyledTextCtrl(parent,id,pos,size,style,name){

    this->SetMarginType(1, wxSTC_MARGIN_NUMBER);
    this->SetMarginWidth(1, 24);

    this->isSaved = false;
    this->filepath = " ";
}