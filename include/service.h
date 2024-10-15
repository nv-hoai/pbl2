#ifndef service_h
#define service_h

#include <iostream>
#include<string>
using namespace std;

class service{
    private:
        static int service_cout;
        int service_id;
        int customer_id;
        string service_type;
        int service_cost;
        string service_name;
        int total_cost;
    public:
        service();
        service( int b, string x, int y, string c);
        service(const service&f);
        void change_cost( int newcost);
        void change_name( string newname);
        void start_use();
        void end_use();
        void cal_total_cost();
        void display_service();
};
#endif
