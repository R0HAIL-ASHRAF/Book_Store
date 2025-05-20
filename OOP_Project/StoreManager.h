#pragma once

#include "Person.h"
#include "Store.h"

class StoreManager : public Person
{
private:
	Store* store;
};

