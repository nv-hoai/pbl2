#include "service.h"

using namespace std;

service::id_type service::service_count = 0;

service::service(customer::id_type customer_id, int cost, string name):
                 customer_id(customer_id), cost(cost), name(name){
    id=service_count++;
}

service::service(const service&f){
    id=service_count++;
    customer_id=f.customer_id;
    cost=f.cost;
    name=f.name;
}

service::~service() {
    service_count--;
}

void service::change_cost(int new_cost){
    cost= new_cost;
}
void service::change_name(string new_name){
    name= new_name;
}

int service::cal_total_cost(){ return -1;}

void service::start_use(){};

void service::end_use(){};

istream& operator>>(istream& is, service& s) {
    cout << "Enter customer id: "; is >> s.customer_id;
    cout << "Enter service cost: "; is >> s.cost;
    return is;
}

ostream& operator<<(ostream& os, const service& s) {
    os << "Service ID: " << s.id;
    os << setw(20) <<"Service name: " << s.name;
    return os;
}

stringstream& operator>>(stringstream& ss, service& s) {
    char t;
    string str;

    ss >> s.cost >> t;
    ss >> s.customer_id;
    return ss;
}