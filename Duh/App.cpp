#include "App.h"

wxIMPLEMENT_APP(App);

App::App()
{

}

App::~App()
{

}

bool App::OnInit()
{
	frame1 = new MainFrame();
	frame1->Show();
	

	return true;
}

//Duh