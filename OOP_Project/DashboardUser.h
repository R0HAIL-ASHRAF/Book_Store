#ifndef DASHBOARDPANEL_H
#define DASHBOARDPANEL_H

#include <wx/wx.h>
#include"Admin.h"
#include "CustomerListView.h"

class DashboardUser : public wxPanel
{
public:
    DashboardUser(wxWindow* parent);

    void SetWelcomeMessage(const wxString& username);

private:
    wxStaticText* m_welcomeLabel;
    wxButton* m_logoutButton;
    CustomerListView* m_customerListView;
    Store* store;

    void OnLogout(wxCommandEvent& event);
    void SetupUI();

    
};

#endif 
