#pragma once
#ifndef ADDRESS_H
#define ADDRESS_H

#include "MyString.h"


class Address {
public:
    MyString houseNumber;
    MyString city;
    MyString province;
    MyString country;

    Address();
    Address(MyString _houseNumber,const MyString& c,const MyString& province, const MyString& co);
    Address(const Address& other);
    Address& operator=(const Address& other);
    friend ostream& operator<<(ostream& os, const Address& a);
	bool operator==(const Address& other) const;
	bool operator!=(const Address& other) const;
    MyString ToString() const;
    // void writeToFile(fstream& fout) const;
    // void readFromFile(fstream& fin) const;

};

#endif
