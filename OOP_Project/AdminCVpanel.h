#pragma once

#include <wx/wx.h>
#include"Admin.h"
#include"IDs.h"
#include <wx/listctrl.h>


class AdminCVpanel :public wxPanel
{
private:
	Admin* admin;
	wxStaticText* m_headLabel;
	wxListView* m_customersListView;

	void SetupUI();
	
public:
	AdminCVpanel(wxWindow* parent);
	void UpdateCustomers();
};

