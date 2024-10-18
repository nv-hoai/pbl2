#include "device.h"

Device::id_type Device::device_count = 0;

Device::Device(string name, bool state): name(name), current_state(state) {
    id = device_count++;
}

Device::Device(const Device& other) {
    id = device_count++;
    name = other.name;
    current_state = 1;
}

Device::~Device() {
    device_count--;
}

ostream& operator<<(ostream& os, const Device& dv) {
    os << "\t\tDevice ID: " << dv.id;
    os << "\tDevice name: " << dv.name;
    os << "\tDevice state: " << ((dv.current_state)?"Working":"Cracked") << "\n";
    return os;
}