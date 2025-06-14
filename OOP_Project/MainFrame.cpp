#include "MainFrame.h"
#include "IDs.h"

MainFrame::MainFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title),
    admin(Admin::GetInstance(this)), 
    prods(MyVector<Product*>())
{

    this->SetBackgroundColour(wxColour(255, 188, 217));
    m_mainSizer = new wxBoxSizer(wxVERTICAL);

    //  panels
    m_loginPanel = loginPanel::GetInstance(this);
    m_dashboardUser = new DashboardUser(this);
    m_signupPanel = new SignupPanel(this);
    m_adminPanel = new DashboardAdmin(this);
	m_addBookPanel = new AddBook(this);
	m_bookDisplayPanel = new BookDisplayPanel(this);
    m_addStorePanel = new AddStorePanel(this);
	m_addStationaryPanel = new AddStationary(this);
    m_viewStorePanel = new ViewStorePanel(this, new StoreManager());
    m_stationaryDisplayPanel = new StationaryDisplayPanel(this);
    m_viewCartPanel = new ViewCartPanel(this);
    Order* order = new Order();
    Customer* customer = new Customer();
    m_orderPanel = new OrderPanel(this, order);
    m_displayOrderPanel = new DisplayOrderPanel(this, customer);

	

    m_addStorePanel->Hide();
    m_bookDisplayPanel->Hide();
    m_adminPanel->Hide();
    m_signupPanel->Hide();
	m_loginPanel->Show();

    m_dashboardUser->Hide();
	m_addBookPanel->Hide();
    m_viewStorePanel->Hide();
    m_addStationaryPanel->Hide();
    m_stationaryDisplayPanel->Hide();
    m_viewCartPanel->Hide();
    m_orderPanel->Hide();
    m_displayOrderPanel->Hide();



    
    m_mainSizer->Add(m_loginPanel, 1, wxEXPAND);
    m_mainSizer->Add(m_dashboardUser, 1, wxEXPAND);
    m_mainSizer->Add(m_signupPanel, 1, wxEXPAND);
    m_mainSizer->Add(m_adminPanel, 1, wxEXPAND);
	m_mainSizer->Add(m_addBookPanel, 1, wxEXPAND);
    m_mainSizer->Add(m_bookDisplayPanel, 1, wxEXPAND);
    m_mainSizer->Add(m_addStorePanel, 1, wxEXPAND);
    m_mainSizer->Add(m_viewStorePanel, 1, wxEXPAND);
	m_mainSizer->Add(m_addStationaryPanel, 1, wxEXPAND);
    m_mainSizer->Add(m_stationaryDisplayPanel, 1, wxEXPAND);
    m_mainSizer->Add(m_viewCartPanel, 1, wxEXPAND);
    m_mainSizer->Add(m_orderPanel, 1, wxEXPAND);
    m_mainSizer->Add(m_displayOrderPanel, 1, wxEXPAND);

    sizeFrame = wxSize(1250, 700);
    m_loginPanel->SetMinSize(sizeFrame);
    m_dashboardUser->SetMinSize(sizeFrame);
    m_signupPanel->SetMinSize(sizeFrame);
    m_adminPanel->SetMinSize(sizeFrame);
	m_addBookPanel->SetMinSize(sizeFrame);
    m_bookDisplayPanel->SetMinSize(sizeFrame);
    m_addStorePanel->SetMinSize(sizeFrame);
    m_viewStorePanel->SetMinSize(sizeFrame);
	m_addStationaryPanel->SetMinSize(sizeFrame);
    m_stationaryDisplayPanel->SetMinSize(sizeFrame);
    m_viewCartPanel->SetMinSize(sizeFrame);
    m_orderPanel->SetMinSize(sizeFrame);
    m_displayOrderPanel->SetMinSize(sizeFrame);



    SetSizer(m_mainSizer);
    SetMinSize(sizeFrame);
        
	// binding events 
    Bind(wxEVT_BUTTON, &MainFrame::OnLoginSuccess, this, ID_LoginButton);
    Bind(wxEVT_BUTTON, &MainFrame::OnShowSignup, this, ID_SignupButton);
    Bind(wxEVT_BUTTON, &MainFrame::OnSignupComplete, this, ID_SignupSubmitButton);
    
    Bind(wxEVT_BUTTON, &MainFrame::SignUpLoginBtnSuccess, this, ID_LoginSignupButton);
    Bind(wxEVT_BUTTON, &MainFrame::OnLogout, this, ID_LogoutButtonAdmin);
    Bind(wxEVT_BUTTON, &MainFrame::OnAddBook, this, ID_AddBook);
    Bind(wxEVT_BUTTON, &MainFrame::OnSaveProductStationary, this, ID_SaveBtnAddStat);

	Bind(wxEVT_BUTTON, &MainFrame::OnSaveProductBook, this, ID_SaveProductButton);
    Bind(wxEVT_BUTTON, &MainFrame::OnAddBook, this, ID_AddProductBtnStoreView);
    Bind(wxEVT_BUTTON, &MainFrame::OnAddBookViaViewStoreClear, this, ID_CANCEL);
    Bind(wxEVT_BUTTON, &MainFrame::OnAddBookViaViewStoreClear, this, ID_CancelBtnAddStat);
    Bind(wxEVT_BUTTON, &MainFrame::OnAddStationary, this, ID_AddStatBtnStoreView);
    Bind(wxEVT_BUTTON, &MainFrame::OnSaveStoreManager, this, ID_SubmitStore);
    Bind(wxEVT_BUTTON, &MainFrame::OnAddStationary, this, ID_AddStatAdmin);
    Bind(wxEVT_BUTTON, &MainFrame::OnAddStoreManager, this, ID_AddStore);
    Bind(wxEVT_BUTTON, &MainFrame::OnAddBook, this, ID_AddBookInStore);
    Bind(wxEVT_BUTTON, &MainFrame::OnAddStationary, this, ID_AddStationery);

    Bind(wxEVT_BUTTON, &MainFrame::OnBackButton, this, ID_BackViewStore);

   
   // Bind(wxEVT_BUTTON, &MainFrame::OnOrderBtnPressed, this, ID_OrderDU);
    Bind(wxEVT_BUTTON, &MainFrame::OnLogout, this, ID_LogoutDU);
    Bind(wxEVT_BUTTON, &MainFrame::OnBackToOrderPanel, this, ID_BackDisplayOrder);
    
    Bind(wxEVT_BUTTON, &MainFrame::SwitchToDisplayOrder, this, ID_OrderDU);
    Bind(wxEVT_BUTTON, &MainFrame::OnBackToOrderPanel, this, ID_BackButtonOP);
    Bind(wxEVT_BUTTON, &MainFrame::OnProceedCart, this, ID_ProceedCart);
    Bind(wxEVT_BUTTON, &MainFrame::OnPlaceOrder, this, ID_PlaceOrderOP);
    Bind(wxEVT_BUTTON, &MainFrame::OnBackToUser, this, ID_BackCart);
    Bind(wxEVT_BUTTON, &MainFrame::OnViewCart, this, ID_ViewCartDU);
    Bind(wxEVT_BUTTON, &MainFrame::OnAddToCartClicked, this);
    Bind(wxEVT_BUTTON, &MainFrame::OnViewProductPanel, this);
    Bind(wxEVT_MENU, &MainFrame::OnRightClickDashboardAdmin, this, ID_RightClickDashboardAdmin);
    Bind(wxEVT_MENU, &MainFrame::OnRightClickViewStore, this, ID_RightClickViewStore);
    Bind(wxEVT_MENU, &MainFrame::OnRightClickViewOrder, this, ID_RightClickViewOrder);
    


    
}

MainFrame::~MainFrame()
{
    Unbind(wxEVT_BUTTON, &MainFrame::OnLoginSuccess, this, ID_LoginButton);
    Unbind(wxEVT_BUTTON, &MainFrame::OnShowSignup, this, ID_SignupButton);
    Unbind(wxEVT_BUTTON, &MainFrame::OnSignupComplete, this, ID_SignupSubmitButton);
    Unbind(wxEVT_BUTTON, &MainFrame::OnLogout, this, ID_LogoutButton);
    Unbind(wxEVT_BUTTON, &MainFrame::SignUpLoginBtnSuccess, this, ID_LoginSignupButton);
    Unbind(wxEVT_BUTTON, &MainFrame::OnLogout, this, ID_LogoutButtonAdmin);
    Unbind(wxEVT_BUTTON, &MainFrame::OnAddBook, this, ID_AddBook);
    Unbind(wxEVT_BUTTON, &MainFrame::OnSaveProductStationary, this, ID_SaveBtnAddStat);
    Unbind(wxEVT_BUTTON, &MainFrame::OnSaveProductBook, this, ID_SaveProductButton);
    Unbind(wxEVT_BUTTON, &MainFrame::OnAddBook, this, ID_AddProductBtnStoreView);
    Unbind(wxEVT_BUTTON, &MainFrame::OnAddBookViaViewStoreClear, this, ID_CANCEL);
    Unbind(wxEVT_BUTTON, &MainFrame::OnAddBookViaViewStoreClear, this, ID_CancelBtnAddStat);
    Unbind(wxEVT_BUTTON, &MainFrame::OnAddStationary, this, ID_AddStatBtnStoreView);
    Unbind(wxEVT_BUTTON, &MainFrame::OnSaveStoreManager, this, ID_SubmitStore);
    Unbind(wxEVT_BUTTON, &MainFrame::OnAddStationary, this, ID_AddStatAdmin);
    Unbind(wxEVT_BUTTON, &MainFrame::OnAddStoreManager, this, ID_AddStore);
    Unbind(wxEVT_BUTTON, &MainFrame::OnAddBook, this, ID_AddBookInStore);
    Unbind(wxEVT_BUTTON, &MainFrame::OnAddStationary, this, ID_AddStationery);
    Unbind(wxEVT_BUTTON, &MainFrame::OnBackButton, this, ID_BackViewStore);
    Unbind(wxEVT_BUTTON, &MainFrame::OnBackButtonProduct, this, ID_BackBtnVS);
    Unbind(wxEVT_BUTTON, &MainFrame::OnBackButtonProduct, this, ID_BackBtnVB);
    Unbind(wxEVT_BUTTON, &MainFrame::OnLogout, this, ID_LogoutDU);
    Unbind(wxEVT_BUTTON, &MainFrame::OnBackToOrderPanel, this, ID_BackDisplayOrder);
    Unbind(wxEVT_BUTTON, &MainFrame::SwitchToDisplayOrder, this, ID_OrderDU);
    Unbind(wxEVT_BUTTON, &MainFrame::OnBackToOrderPanel, this, ID_BackButtonOP);
    Unbind(wxEVT_BUTTON, &MainFrame::OnProceedCart, this, ID_ProceedCart);
    Unbind(wxEVT_BUTTON, &MainFrame::OnPlaceOrder, this, ID_PlaceOrderOP);
    Unbind(wxEVT_BUTTON, &MainFrame::OnBackToUser, this, ID_BackCart);
    Unbind(wxEVT_BUTTON, &MainFrame::OnViewCart, this, ID_ViewCartDU);
    Unbind(wxEVT_BUTTON, &MainFrame::OnAddToCartClicked, this);

    Unbind(wxEVT_MENU, &MainFrame::OnRightClickDashboardAdmin, this, ID_RightClickDashboardAdmin);
    Unbind(wxEVT_MENU, &MainFrame::OnRightClickViewStore, this, ID_RightClickViewStore);
    Unbind(wxEVT_MENU, &MainFrame::OnRightClickViewOrder, this, ID_RightClickViewOrder);

    
}

void MainFrame::OnAddToCartClicked(wxCommandEvent& event) {
    wxObject* obj = event.GetEventObject();
    wxButton* btn = dynamic_cast<wxButton*>(obj);

    if (btn && btn->GetLabel() == "Add to Cart") {
        Product* product = static_cast<Product*>(btn->GetClientData());
        if (product) {
            m_viewCartPanel->AddProducts(product);
            wxLogMessage("Product Added: %s", product->getProductName().ToCharArray());
        }
    }
    event.Skip();
}

void MainFrame::OnViewProductPanel(wxCommandEvent& event) 
{
    wxObject* obj = event.GetEventObject();
    wxButton* btn = dynamic_cast<wxButton*>(obj);

    if (btn && btn->GetLabel() == "View") {
        Product* product = static_cast<Product*>(btn->GetClientData());
        if (product->getProductCategory() == "book") {
            Book* book = dynamic_cast<Book*>(product);
            if (book) {
                m_bookDisplayPanel->SetBookInfo(*book);
                SwitchToDisplayBook();
            }
        }
        else if (product->getProductCategory() == "stationary") {
            Stationary* stat = dynamic_cast<Stationary*>(product);

            if (stat) {
                m_stationaryDisplayPanel->SetStationaryInfo(*stat);
                SwitchToDisplayStationary();
            }
        }
    }
    event.Skip();

}

void MainFrame::OnBackToOrderPanel(wxCommandEvent& event)
{
    SwitchToDashboardUser();

}

void MainFrame::OnBackButtonProductUser(wxCommandEvent& event)
{
    SwitchToDashboardUser();
}

void MainFrame::OnViewStore(wxCommandEvent& event)
{
    int index = m_adminPanel->GetMenuListIndex();
    m_viewStorePanel->SetStore(
        admin->GetStores().at(index)
    );
    m_viewStorePanel->OnRefresh(event);

    SwitchToViewStore();
}


void MainFrame::OnViewProduct(wxCommandEvent& event)
{
    int index = m_viewStorePanel->GetMenuListIndex();
    Product* product = reinterpret_cast<Product*>(m_viewStorePanel->storeManager->GetStore()->GetProducts().at(index));
    if (m_viewStorePanel->storeManager->GetStore()->GetProducts().at(index)->getProductCategory()
        == "book") {
        Book* book = dynamic_cast<Book*>(product);
        if (book == nullptr) {
            Logger::getInstance().writeError("Book was pointing to null MainFrame::OnViewProduct()");
            return;
        }
        m_bookDisplayPanel->SetBookInfo(*book);
        SwitchToDisplayBook();
    }
    else if (m_viewStorePanel->storeManager->GetStore()->GetProducts().at(index)->getProductCategory()
        == "stationary"){
        
        wxLogMessage("stationary is showing up");
        Stationary* stationary = dynamic_cast<Stationary*>(product);
        if (stationary == nullptr) {
            Logger::getInstance().writeError("Stationary was pointing to the null MainFrame::OnViewProduct()");
            return;
        }
        m_stationaryDisplayPanel->SetStationaryInfo(*stationary);
        SwitchToDisplayStationary();
    }
}


void MainFrame::OnViewOrder(wxCommandEvent& event)
{
    int index = m_displayOrderPanel->indexMenuList;
    const MyVector<Order*>& orders = m_loginPanel->GetActiveCustomer()->GetOrders();

    if (index < 0 || index >= orders.size()) {
        Logger::getInstance().writeError("Index got out of range MainFrame::OnViewOrder()");
        return;
    }

    Order* orderPtr = orders.at(index);
    if (!orderPtr) {
        Logger::getInstance().writeError("Order was pointing to the null MainFrame::OnViewOrder() -> orderPtr");
        return;
    }

    Cart* cart = orderPtr->GetCart();
    
    if (!cart) {
        Logger::getInstance().writeError("Cart was pointing to null MainFrame::OnViewProduct()");
        return;
    }
    else {
        m_orderPanel->RefreshCart(cart);
    }

    MyVector<Product*> products = cart->GetPoducts();
    m_viewCartPanel->SetCartItems(products);

    m_viewCartPanel->SetPaymentInfo(
        m_orderPanel->GetCardNumber(),
        m_orderPanel->GetCardHolderName(),
        m_orderPanel->GetExpiryDate(),
        m_orderPanel->GetCVV()
    );
    m_viewCartPanel->SetProductsCart(
        cart->GetPoducts()
    );

    m_viewCartPanel->SetCartItems(cart->GetPoducts());
    m_viewCartPanel->UpdateTotal();

    SwitchToViewCartPanel();

}

void MainFrame::OnRightClickDashboardAdmin(wxCommandEvent& event) {

    int index = event.GetInt();
    wxMenu menu;
    menu.Append(1001, "Delete Store");
    menu.Append(ID_ViewStoreRC, "View");

    menu.Bind(wxEVT_MENU, &MainFrame::OnDeleteItem, this, 1001);
    menu.Bind(wxEVT_MENU, &MainFrame::OnViewStore, this, ID_ViewStoreRC);

    PopupMenu(&menu);
}

void MainFrame::OnDeleteItem(wxCommandEvent& event)
{
    if (m_adminPanel->GetMenuListIndex() != -1)
    {
        int confirm = wxMessageBox("Delete this store?", "Confirm Deletion", wxYES_NO | wxICON_QUESTION);
        if (confirm == wxYES)
        {
            m_adminPanel->m_storeList->DeleteItem(m_adminPanel->GetMenuListIndex());
            m_adminPanel->stores.delete_at(m_adminPanel->GetMenuListIndex());
            admin->WriteStoreManagersToFile();
            m_adminPanel->SetMenuListIndex(-1);
        }
    }
}

void MainFrame::OnBackButtonProduct(wxCommandEvent& event)
{
    SwitchToViewStore();
}

void MainFrame::OnOrderBtnPressed(wxCommandEvent& event)
{
   MyString userName =  m_loginPanel->GetUsername();
   Cart* cart = GetCurrentCustomerCart();
   m_orderPanel->RefreshCart(cart);
   
   SwitchToOrderPanel();

}

Cart* MainFrame::GetCurrentCustomerCart()
{
    MyString userName = m_loginPanel->GetUsername();
    
    for (int i = 0; i < admin->GetCustomers().size(); i++)
    {
        if (userName == admin->GetCustomers().at(i)->getUserName())
            return admin->GetCustomers().at(i)->GetOrders().at(i)->GetCart();
    }
    Logger::getInstance().writeError("No Customer in MainFrame::GetCurrentCustomer()");
    return nullptr; 
}

void MainFrame::OnRightClickViewStore(wxCommandEvent& event) {

    int index = event.GetInt();
    wxMenu menu;
    menu.Append(1001, "Delete Product");
    menu.Append(ID_ViewStoreVC, "View");

    menu.Bind(wxEVT_MENU, &MainFrame::OnDeleteItemProduct, this, 1001);
    menu.Bind(wxEVT_MENU, &MainFrame::OnViewProduct, this, ID_ViewStoreVC);

    PopupMenu(&menu);
}

void MainFrame::OnRightClickViewOrder(wxCommandEvent& event) {

    int index = event.GetInt();
    wxMenu menu;

    menu.Append(ID_deleteOrder, "Delete Order");
    menu.Append(ID_ViewOrder, "View Order");

    menu.Bind(wxEVT_MENU, &MainFrame::OnDeleteOrder, this, ID_deleteOrder);
    menu.Bind(wxEVT_MENU, &MainFrame::OnViewOrder, this, ID_ViewOrder);
    
   PopupMenu(&menu);

}

void MainFrame::OnDeleteOrder(wxCommandEvent& event)
{
    if (m_displayOrderPanel->indexMenuList != -1)
    {
        
        int confirm = wxMessageBox("Delete this order?", "Confirm Deletion", wxYES_NO | wxICON_QUESTION);
        if (confirm == wxYES)
        {
            m_displayOrderPanel->m_ordersList->DeleteItem(m_displayOrderPanel->indexMenuList);
            m_loginPanel->GetActiveCustomer()->GetOrders().delete_at(m_displayOrderPanel->indexMenuList);
            m_loginPanel->GetActiveCustomer()->WriteOrdersToFile();

        }
        m_displayOrderPanel->indexMenuList = -1;
    }
}


void MainFrame::OnDeleteItemProduct(wxCommandEvent& event)
{
    if (m_viewStorePanel->GetMenuListIndex() != -1)
    {
        int confirm = wxMessageBox("Delete this product?", "Confirm Deletion", wxYES_NO | wxICON_QUESTION);
        if (confirm == wxYES)
        {
            m_viewStorePanel->productsList->DeleteItem(m_viewStorePanel->GetMenuListIndex());
            m_viewStorePanel->storeManager->GetStore()->GetProducts().delete_at(m_viewStorePanel->GetMenuListIndex());

        }
        m_viewStorePanel->SetMenuListIndex(-1);
    }
}

void MainFrame::OnLoginSuccess(wxCommandEvent& event)
{
    Bind(wxEVT_BUTTON, &MainFrame::OnLogout, this, ID_LogoutButton);

    m_adminPanel->OnRefreshStoreList(event);
    
    if (m_loginPanel->ValidateLoginForCustomers())
    {
        //Bind(wxEVT_BUTTON, &MainFrame::OnViewProductPanel, this);
        Bind(wxEVT_BUTTON, &MainFrame::OnBackButtonProductUser, this, ID_BackBtnVS);
        Bind(wxEVT_BUTTON, &MainFrame::OnBackButtonProductUser, this, ID_BackBtnVB);


        m_adminPanel->OnRefreshStoreList(event);
        prods.clear();
        for (int i = 0; i < admin->GetStores().size(); i++) {
            for (int j = 0; j < admin->GetStores().at(i)->GetStore()->GetProducts().size(); j++) {
                prods.push(admin->GetStores().at(i)->GetStore()->GetProducts().at(j));
            }
        }
        m_dashboardUser->SetProducts(prods);
        SwitchToDashboard();
    }
   
    else if (m_loginPanel->GetUsername() == m_adminPanel->GetAdminUserName() &&
             m_loginPanel->GetPassword() == m_adminPanel->GetAdminPassword())
    {
        Bind(wxEVT_BUTTON, &MainFrame::OnBackButton, this, ID_BackViewStore);
        Bind(wxEVT_BUTTON, &MainFrame::OnBackButtonProduct, this, ID_BackBtnVS);
        Bind(wxEVT_BUTTON, &MainFrame::OnBackButtonProduct, this, ID_BackBtnVB);

		SwitchToAdminDashboard();
    }
    else if (admin->ValidateStoreManagers()) 
    {
        Unbind(wxEVT_BUTTON, &MainFrame::OnBackButton, this, ID_BackViewStore);
        Bind(wxEVT_BUTTON, &MainFrame::OnBackButtonProduct, this, ID_BackBtnVS);
        Bind(wxEVT_BUTTON, &MainFrame::OnBackButtonProduct, this, ID_BackBtnVB);

        int index = admin->GetIndexOfUser();
        m_viewStorePanel->SetStore(
            admin->GetStores().at(index)
        );
        
        SwitchToViewStore();
    }
    else
    {
        wxMessageBox("Invalid credentials", "Login Error", wxOK | wxICON_ERROR);
    }
    if(m_loginPanel->GetActiveCustomer() != nullptr) 
        m_displayOrderPanel->SetCustomer(m_loginPanel->GetActiveCustomer());
    else {
        Logger::getInstance().writeError("Null Active Customer MainFrame::OnLoginSuccess()");
    }

    Customer* cust = m_loginPanel->GetActiveCustomer();
    if (!cust) {
        
        return;
    }
    m_displayOrderPanel->SetCustomer(cust);

}

void MainFrame::OnShowSignup(wxCommandEvent& event)
{
    SwitchToSignupPage();
    
}

void MainFrame::OnSignupComplete(wxCommandEvent& event)
{
   
    if (!m_signupPanel->ValidateSignup()) {
        m_signupPanel->OnSignup();
    }
    else {
        wxMessageBox("Signup successful! Please log in.", "Success", wxOK | wxICON_INFORMATION);

        Classic* tempPerson = new Classic(*m_signupPanel->getPerson());
        m_loginPanel->AddCustomer(tempPerson);
        m_signupPanel->IntoFile();
        m_signupPanel->clearTextCtrls();
        SwitchToLoginPage();

    }
}

void MainFrame::SignUpLoginBtnSuccess(wxCommandEvent& event) {

    m_loginPanel->Show();
    m_signupPanel->Hide();
    m_dashboardUser->Hide();
    Layout();

}

void MainFrame::OnSaveProductBook(wxCommandEvent& event)
{
    if(!m_addBookPanel->ValidateBook())
    {
        return;
    }
    m_addBookPanel->IntoFile(m_viewStorePanel->GetBookFileName().ToCharArray());
    wxMessageBox("Book saved successfully!", "Success", wxOK | wxICON_INFORMATION);
    m_addBookPanel->ClearForm();
    SwitchToViewStore();
}

void MainFrame::OnSaveProductStationary(wxCommandEvent& event)
{
    if (!m_addStationaryPanel->ValidateStationary())
    {
        return;
    }
    m_addStationaryPanel->IntoFile(m_viewStorePanel->GetStationaryFileName().ToCharArray());
    wxMessageBox("Stationary saved successfully!", "Success", wxOK | wxICON_INFORMATION);
    m_addStationaryPanel->Clear();
    SwitchToViewStore();
}

void MainFrame::OnSaveStoreManager(wxCommandEvent& event)
{
    if (!m_addStorePanel->Validate()) {
        return;
    }
    if (!IsStoreExists()) {
        StoreManager storeManager = m_addStorePanel->GetStoreManager();

        admin->AddStoreManager(
            new StoreManager(storeManager)
        );
        storeManager.AppendStorManagersToFile();

        wxLogError("size of StoreMangers now is %d", admin->GetStores().size());
        wxMessageBox("StoreManager created successfully!", "Success", wxOK | wxICON_INFORMATION);
    }
    SwitchToAdminDashboard();
}

void MainFrame::OnBackButton(wxCommandEvent& event)
{
    SwitchToAdminDashboard();
}

bool MainFrame::IsStoreExists()
{
    
    for (int i = 0; i < admin->GetStores().size(); i++) {

        if (admin->GetStores().at(i)->GetStore()->GetStoreId() == "")
            return true;

        if((m_addStorePanel->GetStoreId() == admin->GetStores().at(i)->GetStore()->GetStoreId()))
            return true;
    }
    return false;
}

void MainFrame::OnAddStoreManager(wxCommandEvent& event)
{
    m_addStationaryPanel->Hide();
    m_loginPanel->Hide();
    m_dashboardUser->Hide();
    m_signupPanel->Hide();
    m_adminPanel->Hide();
    m_viewStorePanel->Hide();
	m_addStorePanel->Show();
    Layout();

}

void MainFrame::SwitchToDashboard()
{

    m_loginPanel->Hide();
    m_signupPanel->Hide();
    m_dashboardUser->Show();
    m_adminPanel->Hide();
    m_addBookPanel->Hide();

    Layout();
}

void MainFrame::SwitchToLoginPage()
{
    m_dashboardUser->Hide();
    m_signupPanel->Hide();
    m_loginPanel->Show();
    m_adminPanel->Hide();
    m_addBookPanel->Hide();

    Layout();
}
void MainFrame::SwitchToDisplayBook()
{
    m_addBookPanel->Hide();
    m_loginPanel->Hide();
    m_dashboardUser->Hide();
    m_signupPanel->Hide();
    m_adminPanel->Hide();
    m_addStorePanel->Hide();
    m_viewStorePanel->Hide();
    m_bookDisplayPanel->Show();
    m_stationaryDisplayPanel->Hide();

    Layout();
}
void MainFrame::SwitchToViewStore()
{
    m_addBookPanel->Hide();
    m_loginPanel->Hide();
    m_dashboardUser->Hide();
    m_signupPanel->Hide();
    m_adminPanel->Hide();
    m_addStorePanel->Hide();
    m_bookDisplayPanel->Hide();
    m_stationaryDisplayPanel->Hide();
    m_viewStorePanel->Show();
    Layout();

}
void MainFrame::SwitchToSignupPage()
{
    m_loginPanel->Hide();
    m_dashboardUser->Hide();
    m_signupPanel->Show();
    m_adminPanel->Hide();
    m_addBookPanel->Hide();


    Layout();
}

void MainFrame::SwitchToAdminDashboard()
{
    m_loginPanel->Hide();
    m_signupPanel->Hide();
    m_dashboardUser->Hide();
    m_adminPanel->Show();
    m_addBookPanel->Hide();

	Layout();
}

void MainFrame::SwitchToDisplayStationary()
{
    m_addBookPanel->Hide();
    m_loginPanel->Hide();
    m_dashboardUser->Hide();
    m_signupPanel->Hide();
    m_adminPanel->Hide();
    m_addStorePanel->Hide();
    m_viewStorePanel->Hide();
    m_bookDisplayPanel->Hide();
    m_stationaryDisplayPanel->Show();
    Layout();
}

void MainFrame::SwitchToOrderPanel()
{
    m_addBookPanel->Hide();
    m_loginPanel->Hide();
    m_dashboardUser->Hide();
    m_signupPanel->Hide();
    m_adminPanel->Hide();
    m_addStorePanel->Hide();
    m_viewStorePanel->Hide();
    m_bookDisplayPanel->Hide();
    m_stationaryDisplayPanel->Hide();
    m_orderPanel->Show();
    Layout();

}

void MainFrame::SwitchToDashboardUser()
{
    m_displayOrderPanel->Hide();
    m_addBookPanel->Hide();
    m_loginPanel->Hide();
    m_dashboardUser->Show();
    m_signupPanel->Hide();
    m_adminPanel->Hide();
    m_addStorePanel->Hide();
    m_viewStorePanel->Hide();
    m_bookDisplayPanel->Hide();
    m_stationaryDisplayPanel->Hide();
    m_orderPanel->Hide();
    Layout();
}

void MainFrame::SwtichToCartPanel()
{
    m_displayOrderPanel->Hide();
    m_addBookPanel->Hide();
    m_loginPanel->Hide();
    m_dashboardUser->Hide();
    m_signupPanel->Hide();
    m_adminPanel->Hide();
    m_addStorePanel->Hide();
    m_viewStorePanel->Hide();
    m_bookDisplayPanel->Hide();
    m_stationaryDisplayPanel->Hide();
    m_orderPanel->Hide();
    m_viewCartPanel->Show();
    Layout();
}

void MainFrame::SwitchToOrderProceed()
{
    m_orderPanel->UpdateOrderSummary();

    m_displayOrderPanel->Hide();
    m_addBookPanel->Hide();
    m_loginPanel->Hide();
    m_dashboardUser->Hide();
    m_signupPanel->Hide();
    m_adminPanel->Hide();
    m_addStorePanel->Hide();
    m_viewStorePanel->Hide();
    m_bookDisplayPanel->Hide();
    m_stationaryDisplayPanel->Hide();
    m_orderPanel->Show();
    m_viewCartPanel->Hide();
    Layout();
}

void MainFrame::SwitchToOrderDisplay()
{
    m_displayOrderPanel->Hide();
    m_addBookPanel->Hide();
    m_loginPanel->Hide();
    m_dashboardUser->Hide();
    m_signupPanel->Hide();
    m_adminPanel->Hide();
    m_addStorePanel->Hide();
    m_viewStorePanel->Hide();
    m_bookDisplayPanel->Hide();
    m_stationaryDisplayPanel->Hide();
    m_orderPanel->Hide();
    m_viewCartPanel->Hide();
    m_displayOrderPanel->Show();
    Layout();
}

void MainFrame::SwitchToViewCartPanel()
{
    m_displayOrderPanel->Hide();
    m_addBookPanel->Hide();
    m_loginPanel->Hide();
    m_dashboardUser->Hide();
    m_signupPanel->Hide();
    m_adminPanel->Hide();
    m_addStorePanel->Hide();
    m_viewStorePanel->Hide();
    m_bookDisplayPanel->Hide();
    m_stationaryDisplayPanel->Hide();
    m_orderPanel->Hide();
    m_viewCartPanel->Hide();
    m_displayOrderPanel->Hide();
    m_viewCartPanel->Show();
    Layout();
}

void MainFrame::OnLogout(wxCommandEvent& event) {
    m_dashboardUser->Hide();
    m_loginPanel->clearTextCtrl();
    m_signupPanel->Hide();
    m_adminPanel->Hide();
    m_addBookPanel->Hide();
    m_loginPanel->Show();
    m_viewCartPanel->Hide();

    Layout();
}

void MainFrame::OnAddBook(wxCommandEvent& event) {
    
    OnSaveStoreManager(event);
    m_viewCartPanel->Hide();

    m_addBookPanel->Show();
    m_loginPanel->Hide();
    m_dashboardUser->Hide();
    m_signupPanel->Hide();
    m_adminPanel->Hide();
    m_viewStorePanel->Hide();
    Layout();
}

void MainFrame::OnAddBookViaViewStoreClear(wxCommandEvent& event) {
    m_addBookPanel->Hide();
    m_loginPanel->Hide();
    m_dashboardUser->Hide();
    m_signupPanel->Hide();
    m_adminPanel->Hide();
    m_viewStorePanel->Show();
    m_viewCartPanel->Hide();

    Layout();
}

void MainFrame::OnAddStationary(wxCommandEvent& event) {

    OnSaveStoreManager(event);
    m_viewCartPanel->Hide();

    m_addStorePanel->Hide();
    m_addStationaryPanel->Show();

    m_loginPanel->Hide();
    m_dashboardUser->Hide();
    m_signupPanel->Hide();
    m_adminPanel->Hide();
    m_viewStorePanel->Hide();
    Layout();
}

void MainFrame::SwitchToDisplayOrder(wxCommandEvent& event)
{
    Customer* cust = m_loginPanel->GetActiveCustomer();
    if (!cust) {
        wxLogError("No active customer!");
        return;
    }

    wxLogMessage("current user: %s", cust->getUserName().ToCharArray());
    m_displayOrderPanel->SetCustomer(cust);

    m_addStorePanel->Hide();
    m_addStationaryPanel->Hide();
    m_displayOrderPanel->Show();
    m_dashboardUser->Hide();
    m_loginPanel->Hide();
    m_dashboardUser->Hide();
    m_signupPanel->Hide();
    m_adminPanel->Hide();
    m_viewStorePanel->Hide();
    m_viewCartPanel->Hide();

    Layout();

}


void MainFrame::OnViewCart(wxCommandEvent& event) {
    m_viewCartPanel->OnRefreshClicked(event);
    SwtichToCartPanel();
}

void MainFrame::OnProceedCart(wxCommandEvent& event)
{
    m_orderPanel->SetCartOrderPanel(m_viewCartPanel->GetCart());
    m_orderPanel->UpdateOrderSummary();
    SwitchToOrderProceed();
}


void MainFrame::OnPlaceOrder(wxCommandEvent& event)
{
    m_orderPanel->UpdateOrderSummary();
    m_orderPanel->SetCartOrderPanel(m_viewCartPanel->GetCart());
    if (!m_orderPanel->ValidateOrder())
    {
        return;
    }
    
    MyString fileName = "TextFiles/Users/";
    fileName.AppendArray(m_loginPanel->GetUsername());
    fileName.AppendArray(".bin");

    Order* order = m_orderPanel->ValidateOrder();
    
    if (m_viewCartPanel->GetCart()) {

        wxLogMessage("Get Cart %s", m_viewCartPanel->GetCart()->GetFileName().ToCharArray());
        order->SetCart(*m_viewCartPanel->GetCart());
        m_orderPanel->RefreshCart(m_viewCartPanel->GetCart());
    }

    std::ofstream fout(fileName.ToCharArray(),
        std::ios::app | std::ios::binary);

    int totalPrice = 0;
    for (int i = 0; i < order->GetCart()->GetPoducts().size(); i++) {
        totalPrice += order->GetCart()->GetPoducts().at(i)->getPrice();
    }
    order->SetPrice(totalPrice);

    order->WriteIntoFile(fout);
    fout.close();
    
    wxMessageBox("Order placed successfully!", "Success", wxOK | wxICON_INFORMATION);
    
    
    SwitchToOrderDisplay();
}

void MainFrame::OnBackToUser(wxCommandEvent& event)
{
    SwitchToDashboardUser();
}


