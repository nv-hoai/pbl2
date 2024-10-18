#include "SystemManager.h"

SystemManager::SystemManager(const SystemManager& other){

}

SystemManager::~SystemManager(){};

void SystemManager::add_computer() {
    Computer* new_computer = new Computer;
    std::cin >> *new_computer;
    computers.append(new_computer);
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

void SystemManager::add_customer() {
    customer* new_customer = new customer;
}
