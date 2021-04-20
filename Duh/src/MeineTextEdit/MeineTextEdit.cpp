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
    this->filepath = " ";

    this->SetLexer(wxSTC_LEX_CPP);

 

    this->StyleSetForeground(wxSTC_C_STRING, wxColour(150, 0, 0));
    this->StyleSetForeground(wxSTC_C_PREPROCESSOR, wxColour(165, 105, 0));
    this->StyleSetForeground(wxSTC_C_IDENTIFIER, wxColour(40, 0, 60));
    this->StyleSetForeground(wxSTC_C_NUMBER, wxColour(0, 150, 0));
    this->StyleSetForeground(wxSTC_C_CHARACTER, wxColour(150, 0, 0));
    this->StyleSetForeground(wxSTC_C_WORD, wxColour(0, 0, 150));
    this->StyleSetForeground(wxSTC_C_WORD2, wxColour(0, 150, 0));
    this->StyleSetForeground(wxSTC_C_COMMENT, wxColour(150, 150, 150));
    this->StyleSetForeground(wxSTC_C_COMMENTLINE, wxColour(150, 150, 150));
    this->StyleSetForeground(wxSTC_C_COMMENTDOC, wxColour(150, 150, 150));
    this->StyleSetForeground(wxSTC_C_COMMENTDOCKEYWORD, wxColour(0, 0, 200));
    this->StyleSetForeground(wxSTC_C_COMMENTDOCKEYWORDERROR, wxColour(0, 0, 200));
    this->StyleSetBold(wxSTC_C_WORD, true);
    this->StyleSetBold(wxSTC_C_WORD2, true);
    this->StyleSetBold(wxSTC_C_COMMENTDOCKEYWORD, true);

    
    this->SetKeyWords(0, wxT("return for while break continue"));
    this->SetKeyWords(1, wxT("const int float void char double"));

    

}

