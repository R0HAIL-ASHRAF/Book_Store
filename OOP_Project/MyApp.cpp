#include "MyApp.h"
#include <wx/sizer.h>
#include"MainFrame.h"


wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    MainFrame* frame = new MainFrame("BOOK CONNECT");
    Admin::GetInstance()->SetMainWindow(frame);
    admin = Admin::GetInstance();
    frame->SetClientSize(800, 600);
    frame->Center();
    frame->Show();
    
    
    return true;
}