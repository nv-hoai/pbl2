#include<iostream>
#include<string>
#include"food.h"
using namespace std;

int main(){
    int remain,cost;
    string name;
    cout<<"Nhap ten food: ";
    getline(cin,name);
    cout<<name;
    cout<<"nhap gia: ";
    cin>>cost;
    cout<<cost;
    cout<<"Nhap so luong: ";
    cin>>remain;
    cout<<remain;
    food f(remain,cost,name);
    cout<<f;

}