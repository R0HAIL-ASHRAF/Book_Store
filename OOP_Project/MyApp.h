#pragma once

#include"wx/wx.h"
#include"Admin.h"

class MyApp : public wxApp
{
private:
	Admin* admin;
	
public: 
	virtual bool OnInit() override;
	~MyApp();

};

