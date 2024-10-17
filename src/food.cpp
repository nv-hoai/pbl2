#include"food.h"
#include<string>
#include<iostream>
using namespace std;

int food::count=0;
food::food()
{
    this->count++;
    remain=0;
    cost=0;
    name =nullptr;
    food_id=count;
    current_state=false;
}
food::food(int remain, int cost, string name){
    this->count++;
    this->cost=cost;
    this->remain= remain;
    this->name= name;
    this->food_id=count;
    if (remain ==0){
        current_state = false;
    }
    else{
        current_state = true;
    }
}
void food::update_state(){
    if (remain ==0){
        current_state = false;
    }
    else{
        current_state = true;
    }
}
bool food::get_state(){
    return current_state;
}
ostream& operator <<(ostream& out, const food& f){
    cout<<"Food id: "<<f.food_id;
    cout<<"food's name: "<<f.name;
    cout<<"food's cost: "<<f.cost;
    cout<<"food's remain: "<<f.remain;
    if (f.current_state)
    {
        cout<<" available.";
    }
    else{
        cout<<"unavailable .";
    }

    return out;
}
istream& operator >>(istream& in, food& f ){
    cout<<"food's name: ";
    getline(in,f.name);
    cout<<"food's cost: ";
    in>> f.cost;
    cout<<"food's remain: ";
    in>>f.remain;
    if (f.remain !=0)
    {
        f.current_state= true;
    }
    else{
         f.current_state= false;
    }

    return in;
}