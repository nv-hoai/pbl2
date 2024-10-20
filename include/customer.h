#ifndef customer_h
#define customer_h

#include "human.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class customer : public human {
public:
    typedef unsigned int id_type;
    customer(string first_name = "", string last_name = "", int age = 0, bool gender = 0);
    customer(const customer& other);
    ~customer() {
        --customer_count;
    }
    
    customer::id_type get_id() const {
        return id;
    }

    friend stringstream& operator>>(stringstream&, customer&);
    friend istream& operator>>(istream&, customer&);
    friend ostream& operator<<(ostream&, const customer&);
private:
    static id_type customer_count;
    id_type id;
};

#endif