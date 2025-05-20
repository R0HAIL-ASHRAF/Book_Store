#pragma once

#include "Product.h"
#include"MyString.h"

class Stationary : public Product
{
private:
	MyString StationaryId;
	MyString StationaryName;
	MyString StationaryType;
	MyString StationaryBrand;
	MyString StationaryColor;

};

