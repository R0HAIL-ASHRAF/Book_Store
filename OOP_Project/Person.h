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
    Person(const Login& _login, 
        const MyString& email, const Date& dob, 
        const Name& name, const Address& addr);
    Person& operator=(const Person& other);
    bool operator==(const Person& other) const;
    bool operator!=(const Person& other) const;

    virtual void writeToFile(fstream& fout) const;
    virtual void readFromFile(fstream& fin) const;


    //getter
    virtual MyString GetPersonType() const = 0;
    virtual MyString getUserName() const;
    virtual MyString getPassword() const;
	virtual Name GetName() const;
   

    //setter
	virtual void SetLogin(const Login& _login);
    virtual void SetName(const Name& _name);
    virtual void SetEmail(const MyString& _email);
    virtual void SetAddress(const Address& addr);
    virtual void SetPerson(const Person& _person);
};

#endif 