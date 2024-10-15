#include "employee.h"
#include <iostream>
#include <string>
using namespace std;

int employee::employ_cout =0;
employee::employee(){
    human();
    employ_cout++;
    position ="Unknow";
    employee_id=employ_cout;
    month_worked=0;
    days_month=0;
    total_earning=0;
    start_time=0;
    base_salary=0;
    time_worked=0;
}
employee::employee(string a, string b, string c, int d, string e,string position, int month, int days, int salary){
    human(a,b,d,c);
    employ_cout++;
    this->position= position;
    this->month_worked=month;
    this->days_month=days;
    this->start_time=0;
    this->base_salary=salary;
    this->total_earning=0;
    employee_id=employ_cout;
    time_worked=0;
}
employee::employee(const employee& x):human(x)
{
    employee_id=x.employee_id;
    position=x.position;
    month_worked=x.month_worked;
    days_month=x.days_month;
    total_earning=x.total_earning;
    start_time=x.start_time;
    base_salary=x.base_salary;
    time_worked=x.time_worked;
}
void employee::checking_start(int time_start){
    start_time=time_start;
}
void employee::checking_end(int time_end){
    time_worked= time_end - start_time;
}
void employee::cal_final_salary(){
    total_earning = base_salary * time_worked; 
}