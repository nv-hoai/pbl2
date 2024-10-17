#include"human.h"
#include<iostream>
#include<string>
using namespace std;

human::human(){
    first_name = "Unknow";
    last_name = "UNknow";
    age = 0;
    gender = "Unknow";
}
human::human(string first_name, string last_name, int age, bool gender): 
            first_name(first_name), last_name(last_name), age(age), gender(gender){
}
human::human(const human& h){
    first_name = h.first_name;
    last_name = h.last_name;
    age = h.age;
    gender = h.gender;
}
void human::change_first_name(const string& newname){
    first_name= newname;
}
void human::change_last_name(const string& newname){
    last_name= newname;
}
void human::change_age(int newage){
    age= newage;
}
void human::change_gender(const bool& newgender){
    gender= newgender;
}
void human::displayHuman() const{
    cout <<"Name: "<<first_name<<" "<<last_name<<endl;
    cout<<"Age: "<<age<<endl;
    cout<<"Gender: "<<gender<<endl;
}