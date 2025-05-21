#pragma once

#include "MyString.h"
#include <wx/image.h>

class Product
{
private:
	wxImage productImage;
	MyString productID;
	MyString productName;
	MyString description;
	int price;

};

