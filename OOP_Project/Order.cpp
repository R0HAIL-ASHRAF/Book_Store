#include "Order.h"

Order::Order()
	:shippingAddress(Address()), status(MyString()),
	orderDate(Date()), deliveryDate(Date()),
	totalPrice(0), cart(nullptr)
{
}

Order::Order(const Order& other)
	: shippingAddress(other.shippingAddress), status(other.status),
	  orderDate(other.orderDate), deliveryDate(other.deliveryDate),
	  totalPrice(other.totalPrice), cart(new Cart(*other.cart))
{
}

Order::Order(const Address& addr, const MyString& shipStat, const Date& orderDate, const int& price)
	: shippingAddress(addr), status(shipStat),
	  orderDate(orderDate), deliveryDate(Date()),
	  totalPrice(price), cart(nullptr)
{
}

Order& Order::operator=(const Order& other)
{
	if(this == &other)
		return *this;

	if (cart != nullptr)
		delete cart;
	cart = new Cart(*other.cart);
	shippingAddress = other.shippingAddress;
	status = other.status;
	orderDate = other.orderDate;
	deliveryDate = other.deliveryDate;
	totalPrice = other.totalPrice;
	return *this;
}

void Order::SetShippingAddress(const Address& addr)
{
	shippingAddress = addr;
}

void Order::SetStatus(const MyString& _status)
{
	this->status = _status;
}

void Order::SetDeliveryDate(const Date& date)
{
	deliveryDate = date;
}

void Order::SetCart(const Cart& cart)
{
	if (this->cart != nullptr)
		delete this->cart;
	this->cart = new Cart(cart);
}




void Order::AddProductToCart(Product* prod)
{
	if (cart == nullptr)
		cart = new Cart();
	cart->AddProductToCart(prod);
}

MyString Order::GetOrderStatus() const
{
	return status;
}

Date Order::GetOrderDate() const
{
	return orderDate;
}

int Order::GetTotalPrice()
{
	if (cart == nullptr)
		return 0;
	totalPrice = cart->GetTotalPrice();
	return totalPrice;
}

Date Order::GetDeliveryDate() const
{
	return deliveryDate;
}

Address Order::GetShippingAddress() const
{
	return shippingAddress;
}

void Order::DisplayCartProduct() const
{

}

void Order::CartInfo() const
{
}

void Order::DisplayOrder() const
{
}



