#include"DashboardUser.h"


DashboardUser::DashboardUser(wxWindow* parent)
    : wxPanel(parent, wxID_ANY) {
    CreateControls();
    LoadProducts();
}

void DashboardUser::CreateControls() {

    m_mainSizer = new wxBoxSizer(wxVERTICAL);

    SetupButtonSizer();

    m_mainSizer->Add(new wxStaticLine(this, wxID_ANY),
        0, wxEXPAND | wxTOP | wxBOTTOM, 5);

    m_productsScroller = new wxScrolledWindow(this, wxID_ANY);
    m_productsScroller->SetScrollRate(10, 10);

    wxBoxSizer* scrollerSizer = new wxBoxSizer(wxVERTICAL);
    m_productsScroller->SetSizer(scrollerSizer);

    m_mainSizer->Add(m_productsScroller, 1, wxEXPAND);

    SetSizer(m_mainSizer);
}

void DashboardUser::SetupButtonSizer() {
    wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);

    wxButton* logoutBtn = new wxButton(this, ID_LogoutDU, "Logout");
    wxButton* cartBtn = new wxButton(this, ID_ViewCartDU, "View Cart");
    wxButton* orderBtn = new wxButton(this, ID_OrderDU, "Orders");
    
    buttonSizer->Add(logoutBtn, 0, wxALL, 5);
    buttonSizer->Add(cartBtn, 0, wxALL, 5);
    buttonSizer->Add(orderBtn, 0, wxALL, 5);

    m_mainSizer->Add(buttonSizer, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 10);
}

void DashboardUser::LoadProducts() {

    wxSizer* scrollerSizer = m_productsScroller->GetSizer();

 
    scrollerSizer->Clear(true);

    wxFlexGridSizer* productGrid = new wxFlexGridSizer(3, 10, 10);
    productGrid->AddGrowableCol(0, 1);
    productGrid->AddGrowableCol(1, 1);
    productGrid->AddGrowableCol(2, 1);

    for (size_t i = 0; i < m_products.size(); i++) {
        const Product& product = *m_products.at(i);
        wxPanel* productPanel = CreateProductPanel(m_productsScroller, product);
        productGrid->Add(productPanel, 0, wxEXPAND | wxALL, 5);
    }

    scrollerSizer->Add(productGrid, 1, wxEXPAND | wxALL, 10);
    m_productsScroller->FitInside();
    m_productsScroller->Layout();

    this->Layout();
    this->Refresh();
}


wxPanel* DashboardUser::CreateProductPanel(wxWindow* parent, const Product& product) {
    wxPanel* panel = new wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(250, 300));
    panel->SetBackgroundColour(*wxWHITE);
    panel->SetWindowStyle(wxSIMPLE_BORDER);

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

    wxStaticBitmap* productImageCtrl = new wxStaticBitmap(panel, wxID_ANY, wxNullBitmap,
        wxDefaultPosition, wxSize(200, 150));

    wxImage* productImage = product.GetProductImage();

    if (productImage && productImage->IsOk()) {
        wxImage scaledImage = productImage->Copy();

        const int targetWidth = 200;
        const int targetHeight = 150;

        wxSize originalSize = scaledImage.GetSize();
        wxSize newSize = originalSize;

        double widthRatio = (double)targetWidth / originalSize.GetWidth();
        double heightRatio = (double)targetHeight / originalSize.GetHeight();
        double scaleRatio = std::min(widthRatio, heightRatio);

        newSize.SetWidth(originalSize.GetWidth() * scaleRatio);
        newSize.SetHeight(originalSize.GetHeight() * scaleRatio);

        scaledImage.Rescale(newSize.GetWidth(), newSize.GetHeight(), wxIMAGE_QUALITY_HIGH);

        wxBitmap bitmap(scaledImage);
        if (newSize.GetWidth() < targetWidth || newSize.GetHeight() < targetHeight) {
            wxBitmap centeredBitmap(targetWidth, targetHeight);
            wxMemoryDC dc;
            dc.SelectObject(centeredBitmap);
            dc.SetBackground(*wxWHITE_BRUSH);
            dc.Clear();

            int x = (targetWidth - newSize.GetWidth()) / 2;
            int y = (targetHeight - newSize.GetHeight()) / 2;
            dc.DrawBitmap(bitmap, x, y, true);

            dc.SelectObject(wxNullBitmap);
            productImageCtrl->SetBitmap(centeredBitmap);
        }
        else {
            productImageCtrl->SetBitmap(bitmap);
        }
    }
    else {
        productImageCtrl->SetBitmap(wxArtProvider::GetBitmap(wxART_MISSING_IMAGE));
    }

    sizer->Add(productImageCtrl, 0, wxALIGN_CENTER | wxTOP, 10);

    wxStaticText* nameLabel = new wxStaticText(panel, wxID_ANY,
        product.getProductName(), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
    nameLabel->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    sizer->Add(nameLabel, 0, wxALIGN_CENTER | wxTOP, 10);

    wxStaticText* descLabel = new wxStaticText(panel, wxID_ANY,
        product.getDescription(), wxDefaultPosition, wxSize(200, -1), wxALIGN_CENTER);
    descLabel->Wrap(200);
    sizer->Add(descLabel, 0, wxALIGN_CENTER | wxTOP, 5);

    wxStaticText* priceLabel = new wxStaticText(panel, wxID_ANY,
        wxString::Format("Rs%d", product.getPrice()), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
    priceLabel->SetFont(wxFont(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    priceLabel->SetForegroundColour(wxColour(0, 100, 0));
    sizer->Add(priceLabel, 0, wxALIGN_CENTER | wxTOP, 10);

    wxButton* addBtn = new wxButton(panel, wxID_ANY, "Add to Cart",
        wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    addBtn->SetBackgroundColour(wxColour(170, 51, 106));
    addBtn->SetForegroundColour(*wxWHITE);
    sizer->Add(addBtn, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 10);
    addBtn->SetClientData((void*)&product);

    panel->SetSizer(sizer);
    return panel;
}

void DashboardUser::SetProducts(const MyVector<Product*>& prods)
{
    m_products = prods;
    LoadProducts();

}
