#ifndef employ_h
#define employ_h

#include <iostream>
#include "human.h"
#include <string>
using namespace std;

class employee : public human
{
private:
    static int employ_cout;
    int employee_id;
    string position;
    int month_worked;
    int days_month;
    int total_earning;
    int start_time;
    int base_salary;
public:
    employee();
    employee(string a, string b, string c, int d, string e,string position, int month, int days, int time, int salary, int total);
    employee( const employee &x);
    void checking_start();
    void checking_end();
    void cal_final_salary();
};

#endif