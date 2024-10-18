#include "customer.h"
#include <iostream>
#include <string>

using namespace std;

customer::id_type customer::customer_count=0;

customer::customer(string first_name, string last_name, int age, bool gender ): human(first_name, last_name, age, gender) {
    id = customer_count++;
}

customer::customer(const customer&h): human(h) {
    id = customer_count++;
}

istream& operator>>(istream& is, customer& c) {
    //use to get keyboard input only
    is >> (human&)c;
    return is;
}

ostream& operator<<(ostream& os, const customer& c) {
    os << "Customer ID: "<< c.id << endl;
    os << (human&)c;
    return os;
}