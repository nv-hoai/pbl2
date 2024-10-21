#include "employee.h"

employee::id_type employee::employee_cout =0;

employee::employee(string first_name, string last_name, int age, bool gender, 
                    string position, int month, int days, int salary):
                    human(first_name, last_name, age, gender), position(position), month_worked(month),
                    days_month(days), base_salary(salary){
    start_time=0;
    total_earning=0;
    id=employee_cout++;
    time_worked=0;
}

employee::employee(const employee& e): human((human&)e)
{
    id= employee_cout++;
    position=e.position;
    month_worked=e.month_worked;
    days_month=e.days_month;
    total_earning=e.total_earning;
    start_time=e.start_time;
    base_salary=e.base_salary;
    time_worked=e.time_worked;
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
    os << "Employee ID: " << e.id << "\n";
    os << (human&)e;
    os << setw(14) << "Position: " << e.position;
    os << setw(16) << "Base salary: " << e.base_salary;
    os << setw(18) << "Month worked: " << e.month_worked;
    os << setw(25) << "Days worked in month: " << e.days_month << "\n";
    return os;
}

void employee::change_base_salary(int newsalary) {
    base_salary = newsalary;
}

void employee::change_position(string newpos) {
    position = newpos;
}