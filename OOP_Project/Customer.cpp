#include "Customer.h"
#include "Patreon.h"

Customer::Customer()
	:Person(), orders{MyVector<Order*>()}, 
	fileName("")
{
}

Customer::Customer(const Customer& other)
	:Person(other)
{
	for (int i = 0; i < other.orders.size(); i++) {
		orders.at(i) = other.orders.at(i);
	}
}

Customer::Customer(const Login& _login, const MyString& email, const Date& dob, const Name& name, const Address& addr)
	:Person(_login, email, dob, name, addr), 
	orders{MyVector<Order*>()}, fileName("")
{
	OpenFile();
}

Customer& Customer::operator=(const Customer& other)
{
	if (this == &other)
		return *this;
	static_cast<Person&>(*this) = other;
	for (int i = 0; i < other.orders.size(); i++) {
		orders.push(other.orders.at(i));
	}
	return *this;
}

void Customer::WriteOrdersToFile()
{
	if (fileName == "")
		OpenFile();

	std::ofstream fout(fileName.ToCharArray(), std::ios::binary);

	if (!fout.is_open()) {
		Logger::getInstance().writeError("fail to open file");
		Logger::getInstance().writeError(fileName);
		return;
	}

	for (int i = 0; i < orders.size(); ++i) {
		orders.at(i)->WriteIntoFile(fout);
	}

	fout.close();
}

void Customer::ReadOrdersFromFile() {
	


	if (fileName == "")
		OpenFile();

	orders.clear();

	std::ifstream fin(fileName.ToCharArray(), std::ios::binary);
	if (!fin.is_open()) {
		Logger::getInstance().writeError("fail to open file");
		Logger::getInstance().writeError(fileName);
		return ;
	}

	Order* order = new Order();
	while (true) {
		order = ReadOrderFromFile(fin);

		if (!fin || fin.eof()) {
			break;
		}
		if (order == nullptr) {
			Logger::getInstance().writeError("Order is null");
		}
		else {
			orders.push(order);
		}	
	}

	fin.close();
	
}



Order* Customer::ReadOrderFromFile(std::ifstream& fin)
{
	MyString houseNumber, city, province, country, status;
	MyString orderDay, orderMonth, orderYear;
	MyString delDay, delMonth, delYear;
	MyString totalPrice;

	houseNumber.ReadFromStream(fin);
	city.ReadFromStream(fin);
	province.ReadFromStream(fin);
	country.ReadFromStream(fin);
	status.ReadFromStream(fin);
	orderDay.ReadFromStream(fin);
	orderMonth.ReadFromStream(fin);
	orderYear.ReadFromStream(fin);
	delDay.ReadFromStream(fin);
	delMonth.ReadFromStream(fin);
	delYear.ReadFromStream(fin);
	totalPrice.ReadFromStream(fin);
	MyString fileName;
	fileName.ReadFromStream(fin);
	
	Cart* cart = new Cart();
	std::ifstream fin2(fileName.ToCharArray(), std::ios::binary);
	if (!fin.is_open()) {
		Logger::getInstance().writeError("Could not open cart file for reading");
		Logger::getInstance().writeError(fileName);
	}

	cart->ReadFromFile(fin2);
	fin2.close();
	
	
	Order* order = new Order(
		Address(houseNumber, city, province, country),
		status,
		Date(orderDay.StringToInt(), orderMonth.StringToInt(), orderYear.StringToInt()),
		Date(delDay.StringToInt(), delMonth.StringToInt(), delYear.StringToInt()),
		totalPrice.StringToInt()
	);
	order->SetCart(*cart);
	return order;
}




MyString Customer::GetPersonType() const
{
	return "Customer";
}

void Customer::AddOrder(Order*& order)
{
	orders.push(order);
}

MyVector<Order*>& Customer::GetOrders()
{
	return orders;
}

MyString Customer::getUserName() const
{
	return login.getUsername();
}
MyString Customer::getPassword() const
{
	return login.getPassword();
}
Name Customer::GetName() const
{
	return fullName;
}

void Customer::DisplayOrders() const
{
	for (int i = 0; i < orders.size(); i++) {
		if (orders.at(i) != nullptr) {
			orders.at(i)->DisplayOrder();
		}
	}
}

Customer::~Customer()
{
	WriteOrdersToFile();
}

void Customer::SetLogin(const Login& _login)
{
	login = _login;
}

void Customer::SetName(const Name& _name)
{
	fullName = _name;
}

void Customer::SetEmail(const MyString& _email)
{
	email = _email;
}

void Customer::SetAddress(const Address& addr)
{
	address = addr;
}

void Customer::SetPerson(const Person& _person)
{
	Person::operator=(_person);
}

void Customer::DisplayCustomer() const
{

}

MyString Customer::GetEmail() const
{
	return email;
}

void Customer::OpenFile()
{
	fileName = "TextFiles/Users/";
	fileName.AppendArray(login.getUsername());
	fileName.AppendArray(".bin");

	std::ofstream fout(fileName.ToCharArray(),
		std::ios::app | std::ios::binary);

	fout.close();
}

Date Customer::GetDate() {
	return birthDate;
}
Address Customer::GetAddress() {
	return address;
 }