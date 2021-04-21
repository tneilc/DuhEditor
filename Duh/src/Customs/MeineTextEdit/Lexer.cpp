#include "MeineTextEdit.h"


void MeineTextEdit::SetupLexer() {
    
    //C Lexer
    
    this->StyleSetForeground(wxSTC_C_DEFAULT, wxColour(255, 255, 255));
    this->StyleSetForeground(wxSTC_C_STRING, wxColour(150, 0, 0));
    this->StyleSetForeground(wxSTC_C_PREPROCESSOR, wxColour(165, 105, 0));
    this->StyleSetForeground(wxSTC_C_IDENTIFIER, wxColour(40, 0, 60));
    this->StyleSetForeground(wxSTC_C_NUMBER, wxColour(0, 150, 0));
    this->StyleSetForeground(wxSTC_C_CHARACTER, wxColour(255, 0, 0));
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

    //Python Lexer
    this->StyleSetForeground(wxSTC_P_DEFAULT, wxColour(0, 0, 0));
    this->StyleSetForeground(wxSTC_P_COMMENTLINE, wxColour(150, 150, 150));
    this->StyleSetForeground(wxSTC_P_NUMBER, wxColour(180, 142, 170));
    this->StyleSetForeground(wxSTC_P_STRING, wxColour(140, 190, 140));
    this->StyleSetForeground(wxSTC_P_CHARACTER, wxColour(140, 190, 140));

    this->StyleSetForeground(wxSTC_P_WORD, wxColour(140, 190, 140));
    this->StyleSetForeground(wxSTC_P_TRIPLE, wxColour(140, 190, 140));
    this->StyleSetForeground(wxSTC_P_TRIPLEDOUBLE, wxColour(140, 190, 140));
    this->StyleSetForeground(wxSTC_P_WORD2, wxColour(140, 190, 140));

    this->StyleSetForeground(wxSTC_P_CLASSNAME, wxColour(143, 188, 183));
    this->StyleSetForeground(wxSTC_P_DEFNAME, wxColour(136, 192, 208));
    this->StyleSetForeground(wxSTC_P_OPERATOR, wxColour(129, 161, 193));

    this->StyleSetForeground(wxSTC_P_IDENTIFIER, wxColour(0, 0, 0));
    this->StyleSetForeground(wxSTC_P_COMMENTBLOCK, wxColour(150, 150, 150));
    this->StyleSetForeground(wxSTC_P_STRINGEOL, wxColour(140, 190, 140));
    this->StyleSetForeground(wxSTC_P_DECORATOR, wxColour(199, 106, 87));
}

void MeineTextEdit::FindLexer() {

}