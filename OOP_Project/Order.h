#pragma once

#include"Cart.h"
#include"Address.h"
#include"Date.h"
class Order
{
private:
	Cart* cart;
	Address shippingAddress;
	MyString status;
	Date orderDate;
	Date deliveryDate;
	int totalPrice;
public:
	Order();
	Order(const Order& other);
	Order(const Address& addr, const MyString& shipStat,
		const Date& orderDate, const int& price);
	Order& operator=(const Order& other);

	//setters
	void SetShippingAddress(const Address& addr);
	void SetStatus(const MyString& status);
	void SetDeliveryDate(const Date& date);
	void SetCart(const Cart& cart);
	void AddProductToCart(Product* prod);

	//getters
	MyString GetOrderStatus() const;
	Date GetOrderDate() const;
	int GetTotalPrice();
	Date GetDeliveryDate() const;
	Address GetShippingAddress() const;

	//display (not defined yet (all 3))
	void DisplayCartProduct() const;
	void CartInfo() const;
	void DisplayOrder() const;

};

