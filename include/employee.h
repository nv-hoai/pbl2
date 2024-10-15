#ifndef employee_h
#define employee_h

#include <iostream>
#include "human.h"
#include <string>
using namespace std;

class employee : public human
{
private:
    static int employee_cout;
    int employee_id;
    string position;
    int month_worked;
    int days_month;
    int total_earning;
    int start_time;
    int base_salary;
    int time_worked;
public:
    employee();
    employee(string a, string b, string c, int d, string e,string position, int month, int days, int salary);
    employee( const employee &x);
    void checking_start(int time_start);
    void checking_end(int time_end);
    void cal_final_salary();
};

#endif