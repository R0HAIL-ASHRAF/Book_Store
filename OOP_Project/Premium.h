#pragma once

#include "Customer.h"

class Premium
	:public Customer
{
private:
	int discountRate;
	bool isActivePremiumMember;
};

