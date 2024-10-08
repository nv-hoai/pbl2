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
    customer(string a, string b, int x, string c);
    customer(const customer& h);
    int pay();
    void use_service();
    void stop_use_service();
    void register_service();
    void diplay_customer() const;
    int getCustomerID() const;
};

#endif