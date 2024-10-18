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
    MyManager.show_customers();
    MyManager.show_employees();

    return 0;
}