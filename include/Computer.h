#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>
#include "double_linked_list.h"
#include "device.h"
#include <iostream>
#include <sstream>

using namespace std;

enum ComputerState {
    Idle, Busy, Cracked
};

class Computer {
public:
    typedef unsigned int id_type;

    Computer(string c_info = "", ComputerState c_state = Idle);
    Computer(const Computer&);
    ~Computer();

    id_type get_id() const {
        return id;
    }

    ComputerState get_state() const {
        return current_state;
    }

    void add_device(string device_name);
    void update_device_state(Device::id_type id, bool state);
    void show_all_devices();
    void update_position(int position) {
        position = position;
    }

    friend istream& operator>>(istream&, Computer&);
    friend stringstream& operator>>(stringstream&, Computer&);
    friend ostream& operator<<(ostream&, const Computer&);
private:
    id_type id;
    int position;
    string info;
    DoublyLinkedList<Device> devices;
    ComputerState current_state;

    static id_type computer_count;
};

#endif