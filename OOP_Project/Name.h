#ifndef NAME_H
#define NAME_H

#include "MyString.h"
using namespace std;

class Name {
public:
    MyString firstName;
    MyString lastName;

    Name();
    Name(const MyString& f, const MyString& l);
    Name(const Name& other);
    Name& operator=(const Name& other);
    bool operator==(const Name& other) const;
    bool operator!=(const Name& other) const;
    MyString ToString() const;
    friend ostream& operator<<(ostream& os, const Name& n);
};

#endif
