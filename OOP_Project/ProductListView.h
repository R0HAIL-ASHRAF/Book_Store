#pragma once

#include <wx/wx.h>
#include <wx/listctrl.h>
#include"Book.h"
#include"Stationary.h"
#include"Product.h"
#include"MyVector.h"

class ProductListView : public wxListView
{
private:
	MyVector<Product*> m_products;
public:
	ProductListView(wxWindow* parent, const MyVector<Product*>& products);
	void RefreshList();

};
