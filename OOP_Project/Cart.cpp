#include "Cart.h"

Cart::Cart()
	:payment(nullptr), totalPrice(0),
	products(MyVector<Product*>()),
	cartId(GenerateCartID())
{
	fileName = "TextFiles/Carts/Cart_";
	fileName.AppendArray(cartId);
	fileName.AppendArray(".bin");

	ofstream fout(fileName.ToCharArray(),
		std::ios::binary | std::ios::app);
	fout.close();
}

Cart::Cart(Payment* payment, const MyVector<Product*>& prods, int price)
	:cartId(GenerateCartID()), payment(payment),
	products(prods), totalPrice(price)
{
	fileName = "TextFiles/Carts/Cart_";
	fileName.AppendArray(cartId);
	fileName.AppendArray(".bin");

	ofstream fout(fileName.ToCharArray(),
		std::ios::binary | std::ios::app);
	fout.close();
}

Cart::Cart(const Cart& other)
	: payment(new Payment(*other.payment)), totalPrice(other.totalPrice),
	products(MyVector<Product*>(other.products)), cartId(GenerateCartID())

{
	fileName = "TextFiles/Carts/Cart_";
	fileName.AppendArray(cartId);
	fileName.AppendArray(".bin");
	ofstream fout(fileName.ToCharArray(),
		std::ios::binary | std::ios::app);
	fout.close();

}

Cart& Cart::operator=(const Cart& other)
{
	if(this == &other)
		return *this;
	if(payment != nullptr)
		delete payment;
	payment = new Payment(*other.payment);
	cartId = other.cartId;
	totalPrice = other.totalPrice;
	products = MyVector<Product*>(other.products);
	return *this;
}

void Cart::WriteIntoFile(std::ofstream& fout)
{
	if (payment == nullptr)
		wxLogError("payment is null ");
	payment->WriteIntoFile(fout);
	MyString(totalPrice).WriteToStream(fout);
	
	for (int i = 0; i < products.size(); i++) {
		products.at(i)->WriteProductIntoFileCart(fout);
	}
}

void Cart::ReadFromFile(std::ifstream& fin)
{
	if (payment == nullptr) {
		payment = new Payment();
	}
	payment->ReadFromFile(fin);
	products.clear();

	MyString priceStr;
	priceStr.ReadFromStream(fin);
	if (!fin) {
		totalPrice = 0;
	}
	else {
		totalPrice = priceStr.StringToInt();
	}
	while (!fin.eof()) {
		Product* p = new Product();
		p = p->ReadProductFromFileCart(fin);

		if (!fin) {
			delete p;
			break;
		}
		products.push(p);
	}
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
	totalPrice = 0;
	for(int i = 0 ; i < products.size(); i++)
	{
		totalPrice += products[i]->getPrice();
	}
	return totalPrice;
}

MyString Cart::GetFileName()
{
	return fileName;
}


void Cart::DisplayProducts() const
{
}


MyString Cart::GenerateCartID() {
	wxConfig config("MyStoreApp");

	long lastID = 0;
	config.Read("LastCartID", &lastID);
	long newID = lastID + 1;

	if (newID > 9999) {
		wxLogError("All cart IDs used.");
		return MyString("----");
	}

	config.Write("LastCartID", newID);
	config.Flush();

	return MyString(wxString::Format("%04ld", newID));
}

Cart::~Cart()
{
}

