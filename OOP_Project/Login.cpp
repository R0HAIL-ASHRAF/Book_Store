#include "Login.h"

Login::Login()
	:username(MyString()), 
	password(MyString()) 
{
}

Login::Login(const MyString& username, const MyString& password)
	:username(username),
	password(password)
{
}

Login::Login(const Login& other)
	:username(other.username),
	password(other.password)
{
}

Login& Login::operator=(const Login& other)
{
	if (this == &other)
		return *this;
	username = other.username;
	password = other.password;
	return *this;
}

bool Login::operator==(const Login& other) const
{
	if(username == other.username && 
		password == other.password)
		return true;
	return false;
}

bool Login::operator!=(const Login& other) const
{
	if(*this == other)
		return false;
	return true;
}

void Login::setUsername(const MyString& _username)
{
	username = _username;
}

void Login::setPassword(const MyString& _password)
{
	password = _password;
}

MyString Login::getUsername() const
{
	return username;
}


MyString Login::getPassword() const
{
	return password;
}
