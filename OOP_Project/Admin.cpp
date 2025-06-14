#include "Admin.h"

Admin* Admin::instance = nullptr;

Admin::Admin(wxWindow* window)
	:Person(), stores(MyVector<StoreManager*>())
{
	SetMainWindow(window);
	
	
}
void Admin::DestroyInstance()
{
	
	if (instance != nullptr) {
		delete instance;
		instance = nullptr;
	} 
	
}
Admin* Admin::GetInstance(wxWindow* window)
{
	if (instance == nullptr) {
		instance = new Admin(window);
	}
	return instance;
}
void Admin::SetMainWindow(wxWindow* window) {
	if (window == nullptr) {
		Logger::getInstance().writeError("SetMainWindow recievednull wxWindow Pointer ");
		return;
	}

	mainWindowPointer = window;
	loginPanelInstance = loginPanel::GetInstance(mainWindowPointer);
	SetCustomers(*loginPanelInstance->GetCustomers());
	SetLogin(Login("admin", "admin123"));
	SetName(Name("Rohail ", "Ashraf"));
	SetEmail("rohailashraf087@gmail.com");
	SetAddress(Address("House # 123", "Lahore", "Punjab", "Pakistan"));

	// setting date of the admin is missing
}

MyString Admin::GetPersonType() const
{
	return "Admin";
}

void Admin::DisplayProducts() const
{

}

void Admin::DisplayStores() const
{
}

void Admin::DisplayStoreManagers() const
{
}


void Admin::DisplayCustomers() const
{

}

void Admin::DisplayStoreManager(StoreManager* storeManager) const
{
}

void Admin::DisplayAllStoreManagers() const
{
}

Admin::~Admin()
{
	for (int i = 0; i < customers.size(); i++) {
		delete customers.at(i);
	}
}

Name Admin::GetName() const
{
	return fullName;
}

MyString Admin::getUserName() const
{
	return login.getUsername();
}
MyString Admin::getPassword() const
{
	return login.getPassword();
}

void Admin::SetLogin(const Login& _login)
{
	login = _login;
}

void Admin::SetName(const Name& _name)
{
	fullName = _name;
}

void Admin::SetEmail(const MyString& _email)
{
	email = _email;
}

void Admin::SetAddress(const Address& addr)
{
	address = addr;
}

void Admin::SetPerson(const Person& _person)
{
	Person::operator=(_person);
}

void Admin::SetCustomers(const MyVector<Classic*>& _customers)
{
	for(int i = 0; i< _customers.size(); i++)
	{
		customers.push(_customers[i]);
	}
}
void Admin::AddStoreManager(StoreManager* storeManager)
{
	if(storeManager == nullptr) {
	}
	stores.push(storeManager);
}
MyVector <Customer*> Admin::GetCustomers() const
{
	return customers;
}

MyVector<StoreManager*> Admin::GetStores() const
{
	return stores;
}


MyString Admin::GetEmail() const
{
	return email;
}

void Admin::WriteStoreManagersToFile() const
{
	std::ofstream fout("TextFiles/StoreManagers/StoreManagers.bin",
		std::ios::binary);
	
	if(!fout.is_open()) {
		Logger::getInstance().writeError("Failed to open TextFiles/StoreManagers/StoreManagers.bin");
		return;
	}

	for(int i = 0; i< stores.size(); i++) {
		if (stores.at(i)->GetStore()->GetStatFileName() != "TextFiles/Stores/Stat_.bin"
			|| stores.at(i)->GetStore()->GetStatFileName() != "")
		stores.at(i)->WriteStorManagersToFile(fout);
	}
}

void Admin::ReadStoreManagersFromFile()
{
	wxLogError("inside admin");

	stores.clear();
	std::ifstream fin("TextFiles/StoreManagers/StoreManagers.bin", std::ios::binary);
	if (!fin.is_open()) {
		Logger::getInstance().writeError("Failed to open TextFiles/StoreManagers/StoreManagers.bin");
		return;
	}

	while (true) {
		std::streampos pos = fin.tellg();
		if (!fin.good()) break;

		StoreManager* storeManager = new StoreManager();
		storeManager->ReadStoreManagerFromFile(fin);

		if (!fin.good() || fin.eof()) {
			delete storeManager;
			break;
		}

		if (fin.tellg() == pos) {
			Logger::getInstance().writeError("Error ocuured while reading from file");
			Logger::getInstance().writeError("StoreManager.bin");
			delete storeManager;
			break;
		}

		stores.push(storeManager);
	}


	fin.close();
}


bool Admin::ValidateStoreManagers() const
{
	MyString username = loginPanelInstance->GetUsername();
	MyString password = loginPanelInstance->GetPassword();

	for (int i = 0; i < stores.size(); i++) {
		if (username == stores.at(i)->getUserName() &&
			password == stores.at(i)->getPassword())
			return true;
	}
	return false;
}

int Admin::GetIndexOfUser() const
{
	MyString username = loginPanelInstance->GetUsername();
	MyString password = loginPanelInstance->GetPassword();

	for (int i = 0; i < stores.size(); i++) {
		if (username == stores.at(i)->getUserName() &&
			password == stores.at(i)->getPassword())
			return i;
	}
	wxLogMessage("Store dooesnot Exists", wxOK | wxICON_ERROR);
	return 0;
}
void Admin::ConvertStatus()
{
	for (int i = 0; i < customers.size(); i++)
	{
		if (customers.at(i)->GetOrders().size() > 50) {
			Premium* prem = new Premium(

				Login(customers.at(i)->getUserName(), customers.at(i)->getPassword()),
				customers.at(i)->GetEmail(), customers.at(i)->GetDate(),
				customers.at(i)->GetName(), customers.at(i)->GetAddress()
			);
			customers.at(i) = prem;
		}
	}

}


// void Admin::WriteAdmin() const 
//{
//	email.WriteToStream(fout);
//	fullName.firstName.WriteToStream(fout);
//	fullName.lastName.WriteToStream(fout);
//	address.houseNumber.WriteToStream(fout);
//	address.city.WriteToStream(fout);
//	address.province.WriteToStream(fout);
//	address.country.WriteToStream(fout);
//	birthDate.ToStringForFile().WriteToStream(fout);
//	login.getUsername().WriteToStream(fout);
//	login.getPassword().WriteToStream(fout);
//}
