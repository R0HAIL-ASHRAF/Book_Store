#include "Order.h"

Order::Order()
	:shippingAddress(Address()), status(MyString()),
	orderDate(Date()), deliveryDate(Date()),
	totalPrice(0), cart(nullptr), cartFileName("")
{
}

Order::Order(const Order& other)
	: shippingAddress(other.shippingAddress), status(other.status),
	  orderDate(other.orderDate), deliveryDate(other.deliveryDate),
	  totalPrice(other.totalPrice), cart(new Cart(*other.cart)), 
	cartFileName(other.cartFileName)

{
}

Order::Order(const Address& addr, const MyString& shipStat, const Date& orderDate, const int& price)
	: shippingAddress(addr), status(shipStat),
	orderDate(orderDate), deliveryDate(Date()),
	totalPrice(price), cart(nullptr), cartFileName("")
{
}

Order::Order(const Address& addr, const MyString& shipStat, const Date& orderDate, const Date& deliveryDate, const int& price)
	:shippingAddress(addr), status(shipStat),
	orderDate(orderDate), cartFileName(""),
	totalPrice(price), cart(nullptr), deliveryDate(deliveryDate)
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
	cartFileName = other.cartFileName;
	deliveryDate = other.deliveryDate;
	totalPrice = other.totalPrice;
	return *this;
}

void Order::WriteIntoFile(std::ofstream& fout)
{
	shippingAddress.houseNumber.WriteToStream(fout);
	shippingAddress.city.WriteToStream(fout);
	shippingAddress.province.WriteToStream(fout);
	shippingAddress.country.WriteToStream(fout);
	status.WriteToStream(fout);
	MyString(orderDate.day).WriteToStream(fout);
	MyString(orderDate.month).WriteToStream(fout);
	MyString(orderDate.year).WriteToStream(fout);
	MyString(deliveryDate.day).WriteToStream(fout);
	MyString(deliveryDate.month).WriteToStream(fout);
	MyString(deliveryDate.year).WriteToStream(fout);
	

	MyString(totalPrice).WriteToStream(fout);
	cartFileName = cart->GetFileName();
	cartFileName.WriteToStream(fout);

	std::ofstream fout2(cartFileName.ToCharArray(), std::ios::binary);
	cart->WriteIntoFile(fout2);

	fout2.close();
}

Order* Order::ReadFromFile(std::ifstream& fin)
{
	shippingAddress.houseNumber.ReadFromStream(fin);
	shippingAddress.city.ReadFromStream(fin);
	shippingAddress.province.ReadFromStream(fin);
	shippingAddress.country.ReadFromStream(fin);
	status.ReadFromStream(fin);
	MyString(orderDate.day).ReadFromStream(fin);
	MyString(orderDate.month).ReadFromStream(fin);
	MyString(orderDate.year).ReadFromStream(fin);
	MyString(deliveryDate.day).ReadFromStream(fin);
	MyString(deliveryDate.month).ReadFromStream(fin);
	MyString(deliveryDate.year).ReadFromStream(fin);
	MyString(totalPrice).ReadFromStream(fin);
	return this;

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

void Order::SetOrderDate(const Date& date)
{
	orderDate = date;
}

void Order::SetPrice(const int& price)
{
	totalPrice = price;
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

Cart* Order::GetCart() const
{
	return cart;
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



