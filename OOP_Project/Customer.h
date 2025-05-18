#pragma once

#include "Person.h"
#include "Order.h"
#include "MyVector.h"

class Customer :
    public Person
{
protected:
	MyVector<Order*> orders;
public:

};

