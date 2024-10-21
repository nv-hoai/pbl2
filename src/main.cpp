#include <iostream>
#include "SystemManager.h"

using namespace std;

//add input files here
const char* path[10] = {"../data/computer.txt", "../data/customer.txt", "../data/employee.txt"};

// Example usage
int main() {

    SystemManager MyManager;

    MyManager.load_data(path);

    MyManager.show_all_computers();
    MyManager.show_available_computer();
    MyManager.show_customers();
    MyManager.show_employees();
    MyManager.show_available_service();
    MyManager.register_service_for_customer();
    MyManager.show_registerd_service();

    return 0;
}