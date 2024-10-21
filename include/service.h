#ifndef service_h
#define service_h

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include "customer.h"

using namespace std;

class service{
public:
    typedef unsigned int id_type;
    service(customer::id_type = -1, int = 0, string = "");
    service(const service&f);
    ~service();
    void change_cost( int newcost);
    void change_name( string newname);
    
    id_type get_id() {
        return id;
    }

    int get_type() {
        return (name=="hire computer")?1:0;
    }

    customer::id_type get_customer_id() {
        return customer_id;
    }

    virtual void start_use();
    virtual void end_use();
    virtual int cal_total_cost();
    
    friend istream& operator>>(istream&, service&);
    friend ostream& operator<<(ostream&, const service&);
    friend stringstream& operator>>(stringstream&, service&);
private:
    static id_type service_count;
    id_type id;
    customer::id_type customer_id;
    string name;
protected:
    int cost;
};
#endif
