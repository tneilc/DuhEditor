#include "MainFrame.h"



wxBEGIN_EVENT_TABLE(MainFrame,wxFrame)
	EVT_MENU(IdSave, MainFrame::OnSave)
	EVT_MENU(IdSaveAs, MainFrame::OnSaveAs)
	EVT_MENU(IdOpen, MainFrame::OnOpen)
	EVT_MENU(IdPreferences, MainFrame::PreferencesOpen)
	EVT_MENU(IdNewFile, MainFrame::OnNewFile)
	EVT_MENU(IdCloseFile,MainFrame::CloseFile)
wxEND_EVENT_TABLE()


MainFrame::MainFrame() : wxFrame(nullptr, wxID_ANY, "Cyka", wxPoint(30, 30), wxSize(800, 900)){
	this->menu = new wxMenuBar();
	this->file = new wxMenu();
	this->settings = new wxMenu();
	this->panel = new wxPanel(this, wxID_ANY);
	this->noteBook = new wxNotebook(panel, wxID_ANY);
	this->panelSizer = new wxBoxSizer(wxHORIZONTAL);
	this->Sizer = new wxBoxSizer(wxHORIZONTAL);

	this->file->Append(IdSave, wxT("&Save File\tCtrl-S"));
	this->file->Append(IdSaveAs, wxT("&Save File As\tCtrl-Alt-S"));
	this->file->Append(IdOpen, wxT("&Open File\tCtrl-O"));
	this->file->Append(IdNewFile, wxT("&New File\tCtrl-N"));
	this->file->AppendSeparator();
	this->file->Append(IdCloseFile, wxT("&Close File\tCtrl-Del"));


	this->settings->Append(IdPreferences, wxT("&Preferences"));

	this->menu->Append(file, wxT("&File")); 
	this->menu->Append(settings, wxT("&Settings"));
	this->SetMenuBar(menu);


	panelSizer->Add(noteBook, 1, wxEXPAND);
	panel->SetSizer(panelSizer);

	Sizer->Add(panel, 1, wxEXPAND);
	this->SetSizer(Sizer);

	MeineTextEdit* textField = new MeineTextEdit(noteBook,123);
	textField->SetMarginType(1, wxSTC_MARGIN_NUMBER); 
	textField->SetMarginWidth(1, 24);
	
	noteBook->AddPage(textField, L"Untitled", true);
	

}




//FIX THIS FUNCTION
void MainFrame::OnSave(wxCommandEvent& event) {
	if (doesExist() == true) {
		MeineTextEdit* toChange = (MeineTextEdit*)noteBook->GetCurrentPage();
		toChange->SaveFile(toChange->filepath);
	}
	else {
		OnSaveAs(event);
	}
}

void MainFrame::OnSaveAs(wxCommandEvent& event) {
	wxFileDialog* saveDialog = new wxFileDialog(this, wxT("Save File~"), wxT(""), wxT(""),wxT("Text Files (*.txt)|*.txt|C++ Files (*.cpp)|*.cpp|Python Files (*.py)|*.py"), wxFD_SAVE);
	MeineTextEdit* toSave = (MeineTextEdit*)noteBook->GetCurrentPage();
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



void MainFrame::PreferencesOpen(wxCommandEvent& event) {
	prefDialog dialog(this, -1, _("Empty Lol"), wxPoint(100, 100), wxSize(400, 400));

	dialog.ShowModal();

}


void MainFrame::AddToNoteBook(wxCommandEvent& event, wxFileDialog* openDialog) {
	MeineTextEdit* textField = new MeineTextEdit(noteBook, wxID_ANY, wxDefaultPosition, wxDefaultSize);
	textField->isSaved = true;
	textField->filepath = openDialog->GetPath();
	textField->LoadFile(openDialog->GetPath());
	noteBook->AddPage(textField, openDialog->GetFilename());
}


void MainFrame::OnNewFile(wxCommandEvent& event) {
	MeineTextEdit* textField = new MeineTextEdit(noteBook, wxID_ANY, wxDefaultPosition, wxDefaultSize);
	noteBook->AddPage(textField,L"Untitled",true);
	event.Skip();
	
}

void MainFrame::CloseFile(wxCommandEvent& event) {
	noteBook->DeletePage(noteBook->GetSelection());
	if (noteBook->GetPageCount() == 0)
	{
		OnNewFile(event);
	}
	
}

bool MainFrame::doesExist() {
	MeineTextEdit* wad = (MeineTextEdit*)noteBook->GetCurrentPage();
	return wad->isSaved;
	
}


MainFrame::~MainFrame() {

}

/*

#define MAX 0
int main(int argc, char *argv[])\n"
{
	for (int n=0; n<MAX; n++)
    {
		printf("Hello World ");
    }
    return 0;
};

*/