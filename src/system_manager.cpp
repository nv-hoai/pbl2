#include "SystemManager.h"

SystemManager::SystemManager(const SystemManager& other){

}

SystemManager::~SystemManager(){};

Computer& SystemManager::add_computer(bool add_type) {
    /* add_type means which way do you want to get input from, add_type = false means
    you want to get input from file, add_type = true means you want to get input from keyboard */
    Computer* new_computer = new Computer;
    if (add_type == 1) std::cin >> *new_computer;
    computers.append(new_computer);
    return *new_computer;
}

void SystemManager::show_all_computers() {
    for(auto iter=computers.begin(); iter!=computers.end(); ++iter) {
        std::cout<< *iter;
        (*iter).show_all_devices();
    }
}

void SystemManager::update_computer_device_state(Computer::id_type computer_id, Device::id_type device_id, bool state) {
    auto c_iter = computers.find(computer_id);
    if (c_iter != computers.end())
        (*c_iter).update_device_state(device_id, state);
}

customer& SystemManager::add_customer(bool add_type) {
    customer* new_customer = new customer;
    if (add_type == 1) std::cin >> *new_customer;
    customers.append(new_customer);
    return *new_customer;
}

employee& SystemManager::add_employee(bool add_type) {
    employee* new_employee = new employee;
    if (add_type == 1) std::cin >> *new_employee;
    employees.append(new_employee);
    return *new_employee;
}

void SystemManager::load_data(const char* path[]) {
    std::ifstream file;

    file.open(path[0], ios_base::in);
    if (!file.is_open()) {
        std::cout << "Can't not open file with the specific path!\n";
        return;
    }
  
    std::string str;
    while (getline(file, str)) {
        std::stringstream ss(str);
        Computer& c = add_computer();
        ss >> c;
    }

    file.close();

    file.open(path[1], ios_base::in);
    if (!file.is_open()) {
        std::cout << "Can't not open file with the specific path!\n";
        return;
    }

    while (getline(file, str)) {
        std::stringstream ss(str);
        customer& c = add_customer();
        ss >> c;
    }

    file.close();

    file.open(path[2], ios_base::in);
    if (!file.is_open()) {
        std::cout << "Can't not open file with the specific path!\n";
        return;
    }

    while (getline(file, str)) {
        std::stringstream ss(str);
        employee& e = add_employee();
        ss >> e;
    }

    file.close();
}

void SystemManager::show_customers() {
    for(auto iter=customers.begin(); iter!=customers.end(); ++iter)
        std::cout << *iter;
}

void SystemManager::show_employees() {
    for(auto iter=employees.begin(); iter!=employees.end(); ++iter)
        std::cout << *iter;
}
