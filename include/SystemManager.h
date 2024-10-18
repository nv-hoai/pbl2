#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "Computer.h"
#include "customer.h"
#include "employee.h"
#include "service.h"
#include "food.h"
#include "Receipt.h"

#include "double_linked_list.h"

class SystemManager {
    DoublyLinkedList<customer> customers;
    DoublyLinkedList<Computer> computers;
    // DoublyLinkedList<employee> employees;
    // DoublyLinkedList<service> services;
    // DoublyLinkedList<Receipt> receipts;
    // DoublyLinkedList<food> foods;

public:
    SystemManager() = default;
    SystemManager(const SystemManager&);
    ~SystemManager();

    void load_data(const char* path[]);

    Computer& add_computer(bool add_type = 0);
    void delete_computer();
    customer& add_customer(bool add_type = 0);
    void delete_customer();
    void add_employee();
    void delete_employee();
    void add_service();
    void delete_service();
    void add_food();
    void delete_food();
    void show_all_computers();
    void show_available_computer();
    void show_customers();
    void show_employees();
    void show_registerd_service();
    void show_available_service();
    void show_receipt();
    void show_food();
    void register_service_for_customer();
    void use_service();
    void stop_use_service();
    void create_receipt();
    void print_receipt();
    void change_service_fee();
    void change_employee_salary();
    void change_employee_position();
    void update_computer_device_state(Computer::id_type, Device::id_type, bool state);
};

#endif