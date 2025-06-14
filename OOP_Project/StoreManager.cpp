#include "StoreManager.h"


StoreManager::StoreManager()
	:Person(), store(Store("", "", Address()))
{
}

StoreManager::StoreManager(const Login& _login, const MyString& email, const Date& dob, const Name& name, const Address& addr, Store store)
	:Person(_login, email, dob, name, addr), store{store}
{
}

StoreManager::StoreManager(const StoreManager& other)
	:Person(other), store{other.store}
{
}
StoreManager& StoreManager::operator=(const StoreManager& other) 
{
	if (this == &other)
		return *this;

	static_cast<Person&>(*this) = other;
	store = other.store;
	return *this;
}
Store* StoreManager::GetStore() const
{
	return new Store(store);
}

wxArrayString StoreManager::DisplayCustomer() const
{
	return wxArrayString();
}

void StoreManager::SetStore(Store store)
{
	this->store = store;
}

MyString StoreManager::getUserName() const
{
	return login.getUsername();
}

MyString StoreManager::getPassword() const
{
	return login.getPassword();
}
MyString StoreManager::GetPersonType() const
{
	return "StoreManager";
}


Name StoreManager::GetName() const
{
	return fullName;
}

void StoreManager::SetLogin(const Login& _login)
{
	login = _login;
}

void StoreManager::SetName(const Name& _name)
{
	fullName = _name;
}

void StoreManager::SetEmail(const MyString& _email)
{
	email = _email;
}

void StoreManager::SetAddress(const Address& addr)
{
	address = addr;
}

void StoreManager::SetPerson(const Person& _person)
{
	Person::operator=(_person);
}
MyString StoreManager::GetStoreName() const
{
	return fullName.ToString();

}

MyString StoreManager::GetEmail() const
{
	return email;
}

void StoreManager::WriteStorManagersToFile(std::ofstream& fout)
{

	email.WriteToStream(fout);
	fullName.firstName.WriteToStream(fout);
	fullName.lastName.WriteToStream(fout);
	address.houseNumber.WriteToStream(fout);
	address.city.WriteToStream(fout);
	address.province.WriteToStream(fout);
	address.country.WriteToStream(fout);
	MyString(birthDate.day).WriteToStream(fout);
	MyString(birthDate.month).WriteToStream(fout);
	MyString(birthDate.year).WriteToStream(fout);
	login.getUsername().WriteToStream(fout);
	login.getPassword().WriteToStream(fout);
	store.WriteStoreInfoIntoFile(fout);

	store.WriteIntoFile();
}


void StoreManager::AppendStorManagersToFile()
{
	std::ofstream fout("TextFiles/StoreManagers/StoreManagers.bin", 
		std::ios::binary | std::ios::app);
	if (!fout.is_open()) {
		wxLogError("Failed to open TextFiles/StoreManagers/StoreManagers.bin while appending.");
		return;
	}
	email.WriteToStream(fout);
	fullName.firstName.WriteToStream(fout);
	fullName.lastName.WriteToStream(fout);
	address.houseNumber.WriteToStream(fout);
	address.city.WriteToStream(fout);
	address.province.WriteToStream(fout);
	address.country.WriteToStream(fout);
	MyString(birthDate.day).WriteToStream(fout);
	MyString(birthDate.month).WriteToStream(fout);
	MyString(birthDate.year).WriteToStream(fout);
	login.getUsername().WriteToStream(fout);
	login.getPassword().WriteToStream(fout);
	store.WriteStoreInfoIntoFile(fout);
	store.WriteIntoFile();
	fout.close();
}
 void StoreManager::ReadStoreManagerFromFile(std::ifstream& fin)
{
	email.ReadFromStream(fin);
	fullName.firstName.ReadFromStream(fin);
	fullName.lastName.ReadFromStream(fin);
	address.houseNumber.ReadFromStream(fin);
	address.city.ReadFromStream(fin);
	address.province.ReadFromStream(fin);
	address.country.ReadFromStream(fin);
	MyString tempString;
	tempString.ReadFromStream(fin);
	birthDate.day = tempString.StringToInt();

	tempString.ReadFromStream(fin);
	birthDate.month = tempString.StringToInt();

	tempString.ReadFromStream(fin);
	birthDate.year = tempString.StringToInt();

	tempString.ReadFromStream(fin);

	login.setUsername(tempString);
	tempString.ReadFromStream(fin);

	login.setPassword(tempString);

	store.ReadStoreInfoFromFile(fin);

	store.LoadAllProductsFromFile();
}
