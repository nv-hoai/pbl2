#ifndef RECEIPT_H
#define RECEIPT_H

#include "double_linked_list.h"
#include "service.h"
#include "Date.h"

typedef unsigned int uint32;

class Receipt {
    uint32 receipt_id;
    uint32 custumer_id;
    // DoublyLinkedList<service> used_services;
    Date date_time;
    float payment;
public:
    Receipt();
    Receipt& create_receipt();
    void print_receipt();
};

#endif