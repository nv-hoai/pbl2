#ifndef HIRE_COMPUTER_H
#define HIRE_COMPUTER_H

typedef unsigned int uint32;

class HireComputer {
    uint32 computer_id;
    uint32 start_time;
    uint32 end_time;
    uint32 total_time_use;
public:
    HireComputer(uint32 = 0, uint32 = 0,  uint32 = 0, uint32 = 0);
    HireComputer(const HireComputer&);
    ~HireComputer();

    //add more methods here
};

#endif