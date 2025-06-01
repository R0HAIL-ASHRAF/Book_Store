#include "Cart.h"

Cart::Cart()
	:payment(nullptr),totalPrice(0),
	products(MyVector<Product*>())
{
}

Cart::Cart(const Cart& other)
	: payment(new Payment(*other.payment)), totalPrice(other.totalPrice),
	products(MyVector<Product*>(other.products))
{
}

Cart& Cart::operator=(const Cart& other)
{
	if(this == &other)
		return *this;
	if(payment != nullptr)
		delete payment;
	payment = new Payment(*other.payment);
	totalPrice = other.totalPrice;
	products = MyVector<Product*>(other.products);
	return *this;
}


void Cart::SetPayment(Payment payment)
{
	if(this->payment != nullptr)
		delete this->payment;
	this->payment = new Payment(payment);
}

void Cart::AddProductToCart(Product* product)
{
	products.push(product);
}

void Cart::ClearCart()
{
	products.clear();
}

void Cart::RemoveProduct(Product* product)
{
	int index = products.find(product);
	products.delete_at(index);
}

MyVector<Product*> Cart::GetPoducts() const
{
	return products;
}

int Cart::GetProductCount() const
{
	return products.size();
}

MyString Cart::GetPrductList() const
{
	return MyString();
}

Payment* Cart::GetPaymentInfo() const
{
	return new Payment(*payment);
}

int Cart::GetTotalPrice() 
{
	for(int i = 0 ; i < products.size(); i++)
	{
		totalPrice += products[i]->getPrice();
	}
	return totalPrice;
}

void Cart::DisplayProducts() const
{
}
