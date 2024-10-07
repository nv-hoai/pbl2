#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>
#include "double_linked_list.h"

typedef unsigned int uint32;

class Device;

class Computer {
    uint32 computer_id;
    std::string computer_info;
    DoublyLinkedList<Device> dv;
    bool current_state;

    static uint32 count;
public:
    Computer();
    Computer(const Computer&);
    ~Computer();
};

#endif