#pragma once
#include "wx/wx.h"
#include "MainFrame/MainFrame.h"



class App : public wxApp
{
public:
	App();
	~App();

private:
	MainFrame* frame1 = nullptr;
	

public:
	virtual bool OnInit();

};
