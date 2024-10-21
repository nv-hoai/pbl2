#include "order_food.h"

OrderFood::OrderFood(customer::id_type customer_id , 
                    int cost, string name, int number_order):
                    service(customer_id, cost, name), number_order(number_order) {
}

OrderFood::OrderFood(const OrderFood& other): service((service&)other) {
    number_order = other.number_order;
}

OrderFood::~OrderFood() {

}

int OrderFood::cal_total_cost() {
    return number_order*cost;
}

istream& operator>>(istream& is, OrderFood& of) {
    is >> (service&)of;
    cout << "Enter the number you want to order: "; is >> of.number_order;
    return is;
}

ostream& operator<<(ostream& os, const OrderFood& of) {
    os << (service&)of;
    os << setw(10) << "Cost: " << of.cost << " vnd per one";
    os << setw(20) << "Number ordered: " << of.number_order << "\n";
    return os;
}

stringstream& operator>>(stringstream& ss, OrderFood& of) {
    char t;
    string str;

    ss >> (service&)of;
    ss >> t >> of.number_order;
    return ss;
}