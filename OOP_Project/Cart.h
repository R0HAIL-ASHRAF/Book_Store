#pragma once
#include "Payment.h"
#include "Product.h"
#include"MyVector.h"
#include <wx/config.h>

class Cart
{
private:
	MyString cartId;
	Payment* payment;
	MyVector<Product*> products;
	int totalPrice;
	MyString fileName;
	
public:
	Cart();
	Cart(Payment* payment,
		const MyVector<Product*>& prods,
		int price);
	Cart(const Cart& other);
	Cart& operator=(const Cart& other);
	
	void WriteIntoFile(std::ofstream& fout);
	void ReadFromFile(std::ifstream& fin);

	void AppendProduct(std::ofstream& fout);
	
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
	MyString GetFileName();
	// display nor defined yet
	void DisplayProducts()const;

	MyString GenerateCartID();
	~Cart();


};

