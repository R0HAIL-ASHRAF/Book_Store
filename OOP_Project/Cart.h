#pragma once
#include "Payment.h"
#include "Product.h"
#include"MyVector.h"

class Cart
{
private:
	Payment* payment;
	MyVector<Product*> products;
	int totalPrice;
public:
	Cart();
	Cart(const Cart& other);
	Cart& operator=(const Cart& other);
	
	// void writeToFile(fstream& fout) const;
	// void readFromFile(fstream& fin) const;
	
	//setters
	void SetPayment(Payment payment);
	void AddProductToCart(Product* product);
	void ClearCart();
	void RemoveProduct(Product* product);

	//getters
	MyVector<Product*> GetPoducts() const;
	int GetProductCount() const;
	MyString GetPrductList() const; // need to define 
	Payment* GetPaymentInfo() const;
	int GetTotalPrice();

	// display nor defined yet
	void DisplayProducts()const;

};

