#ifndef customer_h
#define customer_h

#include "human.h"
#include <iostream>
#include <string>
using namespace std;

class customer : public human
{
private:
    static int cout_customer;
    int customer_id;
public:
    customer();
    customer(string first_name, string last_name, int age, bool gender);
    customer(const customer& other);
    void diplay_customer() const;
    int getCustomerID() const;
};

#endif