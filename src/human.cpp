#include"human.h"
#include<iostream>
#include<string>
using namespace std;

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

istream& operator>>(istream& is, human& h) {
    //use to get input from keyboard only
    cout << "First name: "; is >> h.first_name;
    cout << "Last name: "; is >> h.last_name;
    cout << "Age: "; is >> h.age;
    cout << "Gender (0-male/1-female): "; is >> h.gender; 
    return is;
}

ostream& operator<<(ostream& os, const human& h){
    os << "Name: "<< h.first_name <<" "<< h.last_name << endl;
    os << "Age: "<< h.age << endl;
    os << "Gender: "<< ((h.gender)?"Female":"Male") << endl;
    return os;
}