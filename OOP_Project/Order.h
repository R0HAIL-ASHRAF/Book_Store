#pragma once

#include"Cart.h"
#include"Address.h"
#include"Date.h"
class Order
{
private:
	MyVector<Cart*> cartList;
	Address shippingAddress;
	MyString status;
	Date orderDate;
	Date deliveryDate;
	int totalPrice;
public:

};

