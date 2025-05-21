#ifndef DASHBOARDPANEL_H
#define DASHBOARDPANEL_H

#include <wx/wx.h>
#include"StoreManager.h"

class DashboardUser : public wxPanel
{
public:
    DashboardUser(wxWindow* parent);

    void SetWelcomeMessage(const wxString& username);

private:
    wxStaticText* m_welcomeLabel;
    wxButton* m_logoutButton;
    Store* store;

    void OnLogout(wxCommandEvent& event);
    void SetupUI();

    
};

#endif 
