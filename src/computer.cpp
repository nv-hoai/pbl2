#include "Computer.h"

Computer::id_type Computer::computer_count = 0;

Computer::Computer(string c_info, ComputerState c_state): info(c_info), current_state(c_state) {
    id = computer_count++;
    position = -1;
    add_device("monitor");
    add_device("keyboard");
    add_device("mouse");
    add_device("headphone");
}

Computer::Computer(const Computer& other) {
    id = computer_count++;
    info = other.info;
    current_state = Idle;
    position = -1;
    add_device("monitor");
    add_device("keyboard");
    add_device("mouse");
    add_device("headphone");
}

Computer::~Computer() {
    computer_count--;
}

void Computer::add_device(string device_name) {
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
        cout << *iter;
    }
}

istream& operator>>(istream& is, Computer& c) {
    //use to get input from keyboard only
    cout << "Enter info for the computer: ";
    getline(is, c.info);
    cout << "Enter the position of computer: ";
    is >> c.position;
    string t;
    cout << "Enter the computer's state (Idle/Busy/Cracked): ";
    is >> t;
    (t=="Idle")?c.current_state=Idle:(t=="Busy")?c.current_state=Busy:c.current_state=Cracked;
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

stringstream& operator>>(stringstream& ss, Computer& c) {
    //use to get input from file only
    char t = 0;
    string str;

    while (t != ';') {
        ss >> str;
        c.info += t+str+" ";
        ss >> t;
    }

    ss >> c.position; ss >> t;
    ss >> str; ss >> t;
    c.current_state = (str=="Idle")?Idle:(str=="Busy")?Busy:Cracked;

    bool dv_states[4];
    for(int i=0; i<4; i++)
        ss >> dv_states[i];

    int i=0;
    for(auto iter=c.devices.begin(); iter!=c.devices.end(); ++iter)
        (*iter).update_state(dv_states[i++]);

    return ss;
}