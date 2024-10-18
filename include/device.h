#ifndef DEVICE_H
#define DEVICE_H

#include <iostream>
#include <string>

using namespace std;

class Device {
public:
    typedef unsigned int id_type;

    Device(string device_name = "", bool state = "1");
    Device(const Device&);
    ~Device();

    id_type get_id() {
        return id;
    }

    bool get_state() {
        return current_state;
    }

    void update_state(bool state) {
        current_state = state;
    }

    friend ostream& operator<<(ostream& os, const Device& dv);

private:
    id_type id;
    string name;
    bool current_state;
    static id_type device_count;
};


#endif