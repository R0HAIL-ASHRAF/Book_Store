#include "MyApp.h"
#include <wx/sizer.h>
#include"MainFrame.h"


wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    // wxMessageBox("OnInit called");

    MainFrame* frame = new MainFrame("BOOK CONNECT");
    
    admin = Admin::GetInstance(frame);
    // wxLogMessage("Customer count in myApp: %d", admin->GetCustomers().size());
    frame->SetClientSize(800, 600);
    frame->Center();
    frame->Show();
    
    
    return true;
}