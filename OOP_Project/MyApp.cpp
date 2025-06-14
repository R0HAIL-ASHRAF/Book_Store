
#include "MyApp.h"  
#include <wx/sizer.h>  
#include "MainFrame.h" 
#include"log.h"

// Ensure proper annotations for WinMain  

#ifdef __WXMSW__  
#include <wx/msw/winundef.h>
#endif  

wxIMPLEMENT_APP(MyApp);
bool MyApp::OnInit()
{
    
    Logger& logger = Logger::getInstance();
    logger.cleanup();
    logger.initialize("TexTFiles/Logger/log.txt");
    logger.writeError("MyApp OnInit started");

    MainFrame* frame = new MainFrame("BOOK CONNECT");

    admin = Admin::GetInstance(frame);
    

    
   

  
    frame->SetClientSize(800, 600);
    frame->Center();
    frame->Show();

    return true;
}

MyApp::~MyApp()
{
    Admin::DestroyInstance();
}
