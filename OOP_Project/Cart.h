#pragma once
#include "Payment.h"
#include "Product.h"
#include"MyVector.h"

class Cart
{
private:
	Payment* payment;
	MyVector<Product**> products;
	int totalPrice;
public:

};

