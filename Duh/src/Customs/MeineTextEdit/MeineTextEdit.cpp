#include "MeineTextEdit.h"

enum
{
    MARGIN_LINE_NUMBERS,
    MARGIN_FOLD
};




MeineTextEdit::MeineTextEdit(wxWindow* parent, wxWindowID id,
    const wxPoint& pos,
    const wxSize& size, long style,
    const wxString& name) : wxStyledTextCtrl(parent,id,pos,size,style,name){

    this->SetMarginType(1, wxSTC_MARGIN_NUMBER);
    this->SetMarginWidth(1, 24);

    this->isSaved = false;

    this->SetLexer(wxSTC_LEX_PYTHON);

 
    this->SetupLexer();

    this->ClearBackground();
    this->SetBackgroundColour(*wxBLACK);

    this->SetKeyWords(0, wxT("return for while break continue"));
    this->SetKeyWords(1, wxT("const int float void char double"));

    

}

