#ifndef employee_h
#define employee_h


#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "human.h"

using namespace std;

class employee : public human
{
public:
    typedef unsigned int id_type;

    employee(string = "", string = "", int = 0 , bool = false, string = "", int = 0, int = 0, int = 0);
    employee( const employee &x);
    ~employee();

    id_type get_id() {
        return id;
    }

    void checking_start(int time_start);
    void checking_end(int time_end);
    void change_position(string newpos);
    void change_base_salary(int newsalary);
    void cal_final_salary();

    friend istream& operator>>(istream&, employee&);
    friend stringstream& operator>>(stringstream&, employee&);
    friend ostream& operator<<(ostream&, const employee&);
private:
    static id_type employee_cout;
    id_type id;
    string position;
    int month_worked;
    int days_month;
    int total_earning;
    int start_time;
    int base_salary;
    int time_worked;
};

#endif