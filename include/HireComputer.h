#ifndef HIRE_COMPUTER_H
#define HIRE_COMPUTER_H

#include "service.h"
#include "Computer.h"


class HireComputer: public service {
public:
    HireComputer(customer::id_type customer_id = -1 , int cost = 0, string name = "", 
                Computer::id_type computer_id = -1,int start_time = 0, int end_time = 0);
    HireComputer(const HireComputer&);
    ~HireComputer();

    void start_use() override;
    void end_use() override;
    int cal_total_cost() override;

    friend istream& operator>>(istream&, HireComputer&);
    friend ostream& operator<<(ostream&, const HireComputer&);
    friend stringstream& operator>>(stringstream&, HireComputer&);
private:
    Computer::id_type computer_id;
    int start_time;
    int end_time;
    int total_time_use;
};

#endif