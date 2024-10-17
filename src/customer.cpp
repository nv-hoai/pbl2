#include "customer.h"
#include <iostream>
#include <string>

using namespace std;

int customer:: cout_customer=0;
customer::customer()
{
    human();
    cout_customer++;
    customer_id= cout_customer;
}

customer::customer(string first_name, string last_name, int age, bool gender ): human(first_name, last_name, age, gender) {
    customer_id= ++ cout_customer;
}
customer::customer(const customer&h): human(h) {
    customer_id= h.customer_id;
}
void customer::diplay_customer() const{
    cout<<"Customer ID: "<<customer_id<<endl;
    displayHuman();
   
}

int customer::getCustomerID() const{
    return customer_id;
}