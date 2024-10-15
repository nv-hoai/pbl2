#ifndef MANAGER_H
#define MANAGER_H

#include "Computer.h"
#include "customer.h"
#include "employee.h"
#include "service.h"
#include "food.h"
#include "Receipt.h"

#include "double_linked_list.h"

class Manager {
    DoublyLinkedList<customer> customers;
    DoublyLinkedList<Computer> computers;
    DoublyLinkedList<employee> employees;
    DoublyLinkedList<service> services;
    DoublyLinkedList<Receipt> receipts;
    DoublyLinkedList<food> foods;
public:
    Manager();
    Manager(const Manager&);
    ~Manager();

    void load_data();
    void add_computer();
    void delete_computer();
    void add_customer();
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
    void get_customer();
    void get_computer();
    void get_service();
    void get_receipt();
};

#endif