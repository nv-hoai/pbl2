#include "customer.h"
#include "human.h"
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

customer::customer(string a, string b, int x, string c )
{
    human(a, b, x, c);
    customer_id= ++ cout_customer;
}
customer::customer(const customer&h): human(h) {
    customer_id= h.customer_id;
}
void customer::diplay_customer() const{
    cout<<"Customer ID: "<<customer_id<<endl;
    displayHuman();
   
}

void customer::register_service(){
    cout<<"Customer "<<customer_id<<" register for a service."<<endl;

}
void customer::use_service(){
      cout<<"Customer "<<customer_id<<" is using the service."<<endl;
}
int customer::pay(){
    cout <<"Customer "<<customer_id<<" has paid for the service."<<endl;
    return 0;
}
void customer::stop_use_service(){
    cout<<"Customer "<<customer_id<<" stopped using the service."<<endl;
}
int customer::getCustomerID() const{
    return customer_id;
}