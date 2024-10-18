#include "Computer.h"

Computer::id_type Computer::computer_count = 0;

Computer::Computer(std::string c_info, ComputerState c_state): info(c_info), current_state(c_state) {
    id = computer_count++;
    position = -1;
    add_device("monitor");
    add_device("keyboard");
    add_device("mouse");
}

Computer::Computer(const Computer& other) {
    id = computer_count++;
    info = other.info;
    current_state = Idle;
    position = -1;
    //additional work needed for devices
}

Computer::~Computer() {
    computer_count--;
}

void Computer::add_device(std::string device_name) {
    Device* new_device = new Device(device_name);
    devices.append(new_device);
}

void Computer::update_device_state(Device::id_type id, bool state) {
    auto iter = devices.find(id);
    if (iter != devices.end()) 
        (*iter).update_state(state);
}

void Computer::show_all_devices() {
    for(auto iter=devices.begin(); iter != devices.end(); ++iter) {
        std::cout << *iter;
    }
}

istream& operator>>(istream& is, Computer& c) {
    std::cout << "Enter info for the computer: ";
    std::getline(is, c.info);
    return is;
}
ostream& operator<<(ostream& os, const Computer& c) {
    os << "Computer ID: "<< c.id;
    os << "\tComputer position: " << c.position;
    if (c.position == -1)
        os << " (Default position if don't set)";
    os << "\tComputer state: " << ((c.current_state == Idle)?"Idle":(c.current_state == Busy)?"Busy":"Cracked") << "\n"; 
    os << "\tComputer infomation: " << c.info << "\n";
    return os;
}