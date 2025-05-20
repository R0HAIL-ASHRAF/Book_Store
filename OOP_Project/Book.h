#pragma once

#include "Product.h"
#include"MyString.h"
#include "Person.h"

class Book :public Product
{
private:
	MyString bookId;
	MyString bookName;
	MyString authorName;
	MyString publisherName;
	MyString bookType;
	MyString bookLanguage;
	MyString bookEdition;
	int pages;

};

