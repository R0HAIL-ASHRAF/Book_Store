#pragma once
#include "MyString.h"

class Login
{
	MyString username;
	MyString password;
public:
	Login();
	Login(const MyString& username, const MyString& password);
	Login(const Login& other);
	Login& operator=(const Login& other);
	bool operator==(const Login& other) const;
	bool operator!=(const Login& other) const;
	void setUsername(const MyString& _username);
	void setPassword(const MyString& _password);
	MyString getUsername() const;
	MyString getPassword() const;
};

