#include<iostream>
#include<string>
#include "service.h"

using namespace std;

int service::service_cout = 0;

service::service(){
    service_cout++;
    service_id= service_cout;
    customer_id=0;
    service_type="Unknow";
    service_cost=0;
    service_name="Unknow";
    total_cost=0;
}
service::service( int b, string x, int y, string c){
    service_cout++;
    service_id=service_cout;
    customer_id=b;
    service_type=x;
    service_cost=y;
    service_name=c;
    total_cost=0;
}
service::service(const service&f){
    service_id=f.service_id;
    customer_id=f.customer_id;
    service_type=f.service_type;
    service_cost=f.service_cost;
    service_name=f.service_name;
    total_cost=f.total_cost

}
void service::change_cost(int new_cost){
    service_cost= new_cost;
}
void service::change_name(string new_name){
    service_name= new_name;
}
void service::cal_total_cost(){};

void service::start_use(){};

void service::end_use(){};