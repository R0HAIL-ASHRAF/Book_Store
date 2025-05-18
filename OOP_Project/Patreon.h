#pragma once
#include "Customer.h"
class Patreon :
    public Customer
{
private:
    int discountRate;
    MyString PatreonId;
    bool isActivePatreon;
};

