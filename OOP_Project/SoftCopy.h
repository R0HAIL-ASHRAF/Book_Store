#pragma once

#include "Book.h"
#include "MyString.h"

class SoftCopy : public Book
{
private:
	MyString fileFormat;
	float fileSize;
	MyString fileLink;
public:
};

