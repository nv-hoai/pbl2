#ifndef ORDER_FOOD_H
#define ORDER_FOOD_H

#include "service.h"

class OrderFood: public service{
public:
    OrderFood(customer::id_type customer_id = -1 , int cost = 0, string name = "", int number_order = 0);
    OrderFood(const OrderFood&);
    ~OrderFood();
    int cal_total_cost() override;

    friend istream& operator>>(istream&, OrderFood&);
    friend ostream& operator<<(ostream&, const OrderFood&);
    friend stringstream& operator>>(stringstream&, OrderFood&);
private:
    int number_order;
};

#endif