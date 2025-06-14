#pragma once

#include <wx/wx.h>
#include "CustomerListView.h"
#include"Admin.h"
#include"IDs.h"

class AdminCVpanel :public wxPanel
{
private:
	wxStaticText* m_welcomeLabel;
	wxButton* m_logoutButton;
	CustomerListView* m_customerListView;

	void SetupUI(wxWindow* parent);
public:
	AdminCVpanel(wxWindow* parent);

};

