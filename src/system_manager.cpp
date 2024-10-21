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

    
    file.open(path[3], ios_base::in);
    if (!file.is_open()) {
        std::cout << "Can't not open file with the specific path!\n";
        return;
    }

    char t;
    int service_type;

    while (getline(file, str)) {
        std::stringstream ss(str);
        ss >> service_type >> t;
        service &s = add_service(service_type);
        if (service_type == 1) {
            ss >> (HireComputer&)s;
        }
        else if (service_type == 0) {
            ss >> (OrderFood&)s;
        }
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

void SystemManager::show_available_computer() {
    for(auto iter=computers.begin(); iter!=computers.end(); ++iter)
        if ((*iter).get_state() == Idle)
            std::cout << *iter;
}


void SystemManager::show_registerd_service() {
    for(auto iter=services.begin(); iter!=services.end(); ++iter) {
        std::cout << "---------------service-info---------------\n";
        if ((*iter).get_type() == 1)
            std::cout << (HireComputer&)(*iter);
        else 
            std::cout << (OrderFood&)(*iter);
        auto c_iter = customers.find((*iter).get_customer_id());
        std::cout << *c_iter;
        std::cout << "------------------------------------------\n";
    }
}

void SystemManager::show_available_service() {
    cout << "Two available services are: hire computer and order food\n";
}

service& SystemManager::add_service(int service_type, bool add_type) {
    service *new_service = nullptr;
    if (service_type == 1) {
        new_service = new HireComputer;
        if (add_type == 1) std::cin >> *(HireComputer*)new_service;
        new_service->change_name("hire computer");
    } else if (service_type == 0) {
        new_service = new OrderFood;
        if (add_type == 1) std::cin >> *(OrderFood*)new_service;
        new_service->change_name("order food");
    }
    services.append(new_service);
    return *new_service;
}

void SystemManager::change_service_cost(service::id_type service_id, int newcost) {
    auto s_iter = services.find(service_id);
    if (s_iter != services.end())
        (*s_iter).change_cost(newcost);
}

void SystemManager::change_employee_salary(employee::id_type employee_id, int newsalary) {
    auto e_iter = employees.find(employee_id);
    if (e_iter != employees.end())
        (*e_iter).change_base_salary(newsalary);
}

void SystemManager::change_employee_position(employee::id_type employee_id, string newpos) {
    auto e_iter = employees.find(employee_id);
    if (e_iter != employees.end())
        (*e_iter).change_position(newpos);
}

void SystemManager::register_service_for_customer() {
    int service_type;
    std::cout << "Enter your service you want to register: "; std::cin >> service_type;
    add_service(service_type, 1);
}

void SystemManager::use_service(service::id_type service_id) {
    auto s_iter = services.find(service_id);
    if (s_iter != services.end())
        (*s_iter).start_use();
}

void SystemManager::stop_use_service(service::id_type service_id) {
    auto s_iter = services.find(service_id);
    if (s_iter != services.end())
        (*s_iter).end_use();
}

void SystemManager::change_service_name(service::id_type service_id, std::string newname) {
    auto s_iter = services.find(service_id);
    if (s_iter != services.end())
        (*s_iter).change_name(newname);
}