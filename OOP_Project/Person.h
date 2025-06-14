#pragma once
#ifndef PERSON_H
#define PERSON_H

#include "MyString.h"
#include "Date.h"
#include"Name.h"
#include "Address.h"
#include "Login.h"
#include"log.h"

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

    // virtual void writeToFile(fstream& fout) const;
    // virtual void readFromFile(fstream& fin) const;


    //getter
    virtual MyString GetPersonType() const = 0;
    virtual MyString getUserName() const = 0;
    virtual MyString getPassword() const = 0;
	virtual Name GetName() const = 0;
    virtual MyString GetEmail() const = 0;
   

    //setter
	virtual void SetLogin(const Login& _login) = 0;
    virtual void SetName(const Name& _name) = 0;
    virtual void SetEmail(const MyString& _email) = 0;
    virtual void SetAddress(const Address& addr) =0;
    virtual void SetPerson(const Person& _person)= 0;
};

#endif 