#pragma once
#ifndef DATE_H
#define DATE_H

#include<iostream>
#include"MyString.h"

class Date {
public:
    int day;
    int month;
    int year;

    Date();
    Date(int d, int m, int y);
    Date(const Date& other);
    Date& operator=(const Date& other);
	bool operator==(const Date& other) const;
	bool operator!=(const Date& other) const;

    MyString ToStringForFile() const;
    MyString ToString() const;

    friend std::ostream& operator<<(std::ostream& os, const Date& date);
};

#endif