#include "MainFrame.h"


wxBEGIN_EVENT_TABLE(MainFrame,wxFrame)
	EVT_MENU(IdSave, MainFrame::OnSave)
	EVT_MENU(IdSaveAs, MainFrame::OnSaveAs)
	EVT_MENU(IdOpen, MainFrame::OnOpen)
wxEND_EVENT_TABLE()



MainFrame::MainFrame() : wxFrame(nullptr, wxID_ANY, "Cyka", wxPoint(30, 30), wxSize(600, 600)){
	this->menu = new wxMenuBar();
	this->file = new wxMenu();

	this->file->Append(IdSave, wxT("&Save File\tCtrl-S"));
	this->file->Append(IdSaveAs, wxT("&Save File As\tCtrl-Alt-S"));
	this->file->Append(IdOpen, wxT("&Open File\tCtrl-O"));

	this->menu->Append(file, wxT("&File")); 
	this->SetMenuBar(menu);

	this->text = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER | wxTE_MULTILINE);
	wxFont textFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false);
	this->text->SetFont(textFont);
	this->text->SetForegroundColour(wxColour(145, 116, 116));




}

void MainFrame::OnSave(wxCommandEvent& event) {
	this->text->SaveFile(OpenFilePath);
}

void MainFrame::OnSaveAs(wxCommandEvent& event) {
	wxFileDialog* saveDialog = new wxFileDialog(this, wxT("Save File~"), wxT(""), wxT(""),wxT("Text Files (*.txt)|*.txt|C++ Files (*.cpp)|*.cpp|Python Files (*.py)|*.py"), wxFD_SAVE);
	
	int response = saveDialog->ShowModal();

	if (response == wxID_OK) 
		this->text->SaveFile(saveDialog->GetPath());
	
}



void MainFrame::OnOpen(wxCommandEvent& event) {
	wxFileDialog* openDialog = new wxFileDialog(this, wxT("Open File~"), wxT(""), wxT(""),wxT("Text Files (*.txt)|*.txt|C++ Files (*.cpp)|*.cpp|Python Files (*.py)|*.py"), wxFD_OPEN);
	int response = openDialog->ShowModal();
	if (response == wxID_OK) {
		this->text->LoadFile(openDialog->GetPath());
		OpenFilePath = openDialog->GetPath();
	}
}




MainFrame::~MainFrame() {

}