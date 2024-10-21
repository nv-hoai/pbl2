#include "HireComputer.h"

HireComputer::HireComputer(customer::id_type customer_id, int cost, string name,
                Computer::id_type computer_id, int start_time, int end_time):
                service(customer_id, cost, name), computer_id(computer_id),
                start_time(start_time), end_time(end_time) {
}

HireComputer::HireComputer(const HireComputer& other): service((service&)other) {
    computer_id = other.computer_id;
    start_time = other.start_time;
    end_time = other.end_time;
}

HireComputer::~HireComputer() {
    //do nothing
}

istream& operator>>(istream& is, HireComputer& hc) {
    is >> (service&)hc;
    cout << "Enter computer's id which you want to hire: "; is >> hc.computer_id;
    cout << "Enter start hiring time: "; is >> hc.start_time;
    cout << "Enter end hiring time: "; is >> hc.end_time;
    return is;
}
ostream& operator<<(ostream& os, const HireComputer& hc) {
    os << (service&)hc;
    os << setw(10) << "Cost: " << hc.cost << "vnd/h\n";
    os << "Currently hiring computer's id: " << hc.computer_id << "\n";
    os << "Time start to hire: " << hc.start_time;
    os << setw(15) <<  "Time end: " << hc.end_time << "\n";
    return os;
}

stringstream& operator>>(stringstream& ss, HireComputer& hc) {
    char t;
    string str;

    ss >> (service&)hc;
    ss >> t >> hc.computer_id >> t >> hc.start_time >> t >> hc.end_time;
    return ss;
}


void HireComputer::start_use() {
    //start to count time
}
void HireComputer::end_use() {
    //end count;
}

int HireComputer::cal_total_cost() {
    int total_cost = cost*total_time_use;
    return total_cost;
}