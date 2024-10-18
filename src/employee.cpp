#include "employee.h"

employee::id_type employee::employee_cout =0;

employee::employee(string first_name, string last_name, int age, bool gender, 
                    string position, int month, int days, int salary):
                    human(first_name, last_name, age, gender), position(position), month_worked(month),
                    days_month(days), base_salary(salary){
    start_time=0;
    total_earning=0;
    employee_id=employee_cout++;
    time_worked=0;
}

employee::employee(const employee& x): human(x)
{
    employee_id= employee_cout++;
    position=x.position;
    month_worked=x.month_worked;
    days_month=x.days_month;
    total_earning=x.total_earning;
    start_time=x.start_time;
    base_salary=x.base_salary;
    time_worked=x.time_worked;
}

employee::~employee() {
    employee_cout--;
}

void employee::checking_start(int time_start){
    start_time=time_start;
}

void employee::checking_end(int time_end){
    time_worked= time_end - start_time;
}

void employee::cal_final_salary(){
    //more work to do
    total_earning = base_salary * time_worked; 
}

istream& operator>>(istream& is, employee& e) {
    is >> (human&)e;
    cout << "Position: "; is >> e.position;
    cout << "Base salary: "; is >> e.base_salary;
    return is;
}

stringstream& operator>>(stringstream& ss, employee& e) {
    char t;
    ss >> (human&)e >> t >> e.position >> t >> e.month_worked >> t >> e.days_month >> t >> e.base_salary;
    return ss;
}

ostream& operator<<(ostream& os, const employee& e) {
    os << "Employee ID: " << e.employee_id << "\n";
    os << (human&)e;
    os << setw(14) << "Position: " << e.position;
    os << setw(16) << "Base salary: " << e.base_salary;
    os << setw(18) << "Month worked: " << e.month_worked;
    os << setw(25) << "Days worked in month: " << e.days_month << "\n";
    return os;
}