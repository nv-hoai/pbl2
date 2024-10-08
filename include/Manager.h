#ifndef MANAGER_H
#define MANAGER_H

#include "double_linked_list.h"

class Manager {
    // + list_of_customer
    // + list_of_computer
    // + list_of_employee
    // + list_of_service
    // + list_of_receipt
    // + list_of_food
public:
    Manager();
    Manager(const Manager&);
    ~Manager();

    // + add_computer()
    // + delete_computer()
    // + add_customer()
    // + delete_customer()
    // + add_employee()
    // + delete_employee()
    // + add_service()
    // + delete_service()
    // + add_food()
    // + delete_food()
    // + show_all_computers()
    // + show_available_computer()
    // + show_customers()
    // + show_employees()
    // + show_registerd_service()
    // + show_available_service()
    // + show_receipt()
    // + show_food()
    // + register_service_for_customer()
    // + use_service()
    // + stop_use_service()
    // + create_receipt()
    // + print_receipt()
    // + change_service_fee()
    // + change_employee_salary()
    // + change_employee_position()
    // + get_customer()
    // + get_computer()
    // + get_service()
    // + get_receipt()
};

#endif