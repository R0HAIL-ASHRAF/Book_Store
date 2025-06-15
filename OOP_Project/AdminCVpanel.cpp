#include "AdminCVpanel.h"

AdminCVpanel::AdminCVpanel(wxWindow* parent)
	: wxPanel(parent, wxID_ANY), 
    admin(Admin::GetInstance(parent))
{
    SetupUI(); 
    UpdateCustomers();
}
void AdminCVpanel::SetupUI()
{
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

   
    m_headLabel = new wxStaticText(this, wxID_ANY, "CUSTOMERS LIST");
    m_headLabel->SetFont(wxFont(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    mainSizer->Add(m_headLabel, 0, wxALIGN_CENTER | wxTOP, 30);

    mainSizer->AddSpacer(20);
    
   
    m_customersListView = new wxListView(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
        wxLC_REPORT | wxLC_SINGLE_SEL | wxLC_HRULES | wxLC_VRULES);

    m_customersListView->AppendColumn("No.", wxLIST_FORMAT_CENTRE, 80);
    m_customersListView->AppendColumn("Name", wxLIST_FORMAT_LEFT, 250);
    m_customersListView->AppendColumn("UserName", wxLIST_FORMAT_CENTER, 170);
    m_customersListView->AppendColumn("Email", wxLIST_FORMAT_CENTER, 250);
    m_customersListView->AppendColumn("Orders", wxLIST_FORMAT_CENTER, 100);
    m_customersListView->AppendColumn("DOB", wxLIST_FORMAT_CENTER, 150);
    m_customersListView->AppendColumn("Type", wxLIST_FORMAT_CENTER, 200);




    mainSizer->Add(m_customersListView, 1, wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM, 15);

    mainSizer->AddStretchSpacer();
    wxButton* backBtn = new wxButton(this, ID_LogoutButton, "back");

    backBtn->SetBackgroundColour(wxColour(219, 0, 107));
    backBtn->SetForegroundColour(*wxWHITE);
    backBtn->SetWindowStyle(wxBORDER_NONE);

    mainSizer->Add(backBtn, 0, wxALIGN_RIGHT | wxRIGHT | wxBOTTOM, 10);

    SetSizer(mainSizer);
}
void AdminCVpanel::UpdateCustomers()
{
   

    for (int i = 0; i < admin->GetCustomers().size(); i++) {

        long index = m_customersListView->InsertItem(i, MyString(i + 1));
        m_customersListView->SetItem(index, 1, admin->GetCustomers().at(i)->GetName().ToString());
        m_customersListView->SetItem(index, 2, admin->GetCustomers().at(i)->getUserName());
        m_customersListView->SetItem(index, 3, admin->GetCustomers().at(i)->GetEmail());
        m_customersListView->SetItem(index, 4, wxString::Format("%d", admin->GetCustomers().at(i)->GetOrders().size()));
        m_customersListView->SetItem(index, 5,  admin->GetCustomers().at(i)->GetDate().ToString());
        m_customersListView->SetItem(index, 6, admin->GetCustomers().at(i)->GetPersonType());


        if (i % 2 == 0) {
            m_customersListView->SetItemBackgroundColour(i, wxColour(255, 230, 235));

        }
    }
}
