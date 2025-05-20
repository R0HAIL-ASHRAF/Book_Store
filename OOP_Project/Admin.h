#pragma once

#include "Person.h"
#include"MyVector.h"
#include "Store.h"

class Admin : public Person
{
private:
	MyVector<Store**> stores;
};

