#pragma once
#ifndef PERSON_H
#define PERSON_H

#include "MyString.h"
#include "Date.h"
#include"Name.h"
#include "Address.h"
#include "Login.h"

class Person {
protected:
    MyString email;
    Date birthDate;
    Name fullName;
    Address address;
    Login login;

public:
    Person();
    Person(const Person& other);
    Person(const Login& _login, const MyString& email, const Date& dob, const Name& name, const Address& addr);
    Person& operator=(const Person& other);
    bool operator==(const Person& other) const;
    bool operator!=(const Person& other) const;
    MyString getUserName() const;
    MyString getPassword() const;

};

#endif 