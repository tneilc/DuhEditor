#include "MainFrame.h"



wxBEGIN_EVENT_TABLE(MainFrame,wxFrame)
	EVT_MENU(IdSave, MainFrame::OnSave)
	EVT_MENU(IdSaveAs, MainFrame::OnSaveAs)
	EVT_MENU(IdOpen, MainFrame::OnOpen)
	EVT_MENU(IdStyle, MainFrame::OnChangeStyle)
	EVT_MENU(IdPreferences, MainFrame::PreferencesOpen)
	EVT_MENU(IdNewFile, MainFrame::OnNewFile)
wxEND_EVENT_TABLE()



MainFrame::MainFrame() : wxFrame(nullptr, wxID_ANY, "Cyka", wxPoint(30, 30), wxSize(600, 600)){
	this->menu = new wxMenuBar();
	this->file = new wxMenu();
	this->settings = new wxMenu();
	this->panel = new wxPanel(this, wxID_ANY,wxDefaultPosition,wxDefaultSize);
	this->noteBook = new wxNotebook(panel, wxID_ANY);
	this->panelSizer = new wxBoxSizer(wxHORIZONTAL);
	//this->text = new wxTextCtrl(noteBook, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER | wxTE_MULTILINE);

	this->file->Append(IdSave, wxT("&Save File\tCtrl-S"));
	this->file->Append(IdSaveAs, wxT("&Save File As\tCtrl-Alt-S"));
	this->file->Append(IdOpen, wxT("&Open File\tCtrl-O"));
	this->file->Append(IdNewFile, wxT("&New File\tCtrl-N"));
	
	this->settings->Append(IdStyle, wxT("&Edit Style"));
	this->settings->Append(IdPreferences, wxT("&Preferences"));

	this->menu->Append(file, wxT("&File")); 
	this->menu->Append(settings, wxT("&Settings"));
	this->SetMenuBar(menu);


	/*wxFont textFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false);
	this->text->SetFont(textFont);
	noteBook->AddPage(text,L"wtf");*/
	panelSizer->Add(noteBook, 1, wxEXPAND);
	panel->SetSizer(panelSizer);


}


//FIX THIS FUNCTION
void MainFrame::OnSave(wxCommandEvent& event) {
	if (doesExist() == true) {
		BetterTextCtrl* toChange = (BetterTextCtrl*)noteBook->GetCurrentPage();
		toChange->SaveFile(toChange->filepath);
	}
	else {
		OnSaveAs(event);
	}
}

void MainFrame::OnSaveAs(wxCommandEvent& event) {
	wxFileDialog* saveDialog = new wxFileDialog(this, wxT("Save File~"), wxT(""), wxT(""),wxT("Text Files (*.txt)|*.txt|C++ Files (*.cpp)|*.cpp|Python Files (*.py)|*.py"), wxFD_SAVE);
	BetterTextCtrl* toSave = (BetterTextCtrl*)noteBook->GetCurrentPage();
	int response = saveDialog->ShowModal();

	if (response == wxID_OK) {
		toSave->isSaved = true;
		toSave->filepath = saveDialog->GetPath();
		toSave->SaveFile(saveDialog->GetPath());
		saveDialog->Close();
	}
}


//ADD IS OPEN CHECK
void MainFrame::OnOpen(wxCommandEvent& event) {
	wxFileDialog* openDialog = new wxFileDialog(this, wxT("Open File~"), wxT(""), wxT(""),wxT("Text Files (*.txt)|*.txt|C++ Files (*.cpp)|*.cpp|Python Files (*.py)|*.py"), wxFD_OPEN);
	int response = openDialog->ShowModal();
	if (response == wxID_OK) {
		AddToNoteBook(event, openDialog);

	}
}


void MainFrame::OnChangeStyle(wxCommandEvent& event) {
	wxFontDialog* fontDialog = new wxFontDialog(this);
	if (fontDialog->ShowModal() == wxID_OK) {
		text->SetFont(fontDialog->GetFontData().GetChosenFont());
		text->SetForegroundColour(fontDialog->GetFontData().GetColour());
	}

	
}

void MainFrame::PreferencesOpen(wxCommandEvent& event) {
	prefDialog dialog(this, -1, _("Empty Lol"), wxPoint(100, 100), wxSize(400, 400));

	dialog.ShowModal();

}


void MainFrame::AddToNoteBook(wxCommandEvent& event, wxFileDialog* openDialog) {
	BetterTextCtrl* textField = new BetterTextCtrl(noteBook, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER | wxTE_MULTILINE);
	textField->isSaved = true;
	textField->filepath = openDialog->GetPath();
	noteBook->AddPage(textField, openDialog->GetFilename());
}


void MainFrame::OnNewFile(wxCommandEvent& event) {
	BetterTextCtrl* textField = new BetterTextCtrl(noteBook, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER | wxTE_MULTILINE);
	noteBook->AddPage(textField,L"Untitled",true);
	event.Skip();
	
}


bool MainFrame::doesExist() {
	BetterTextCtrl* wad = (BetterTextCtrl*)noteBook->GetCurrentPage();
	return wad->isSaved;
	
}


MainFrame::~MainFrame() {

}

