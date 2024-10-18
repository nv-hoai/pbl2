#ifndef human_h
#define human_h

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class human
{
private:
    string first_name;
    string last_name;
    int age;
    bool gender;
public:
    human(string first_name = "Unknown", string last_name ="", int age = 0, bool gender = 0);
    human(const human& person);
    void change_first_name(const string & newname);
    void change_last_name(const string& newname);
    void change_age(int newage);
    void change_gender(const bool& newgender);
    
    friend istream& operator>>(istream&, human&);
    friend ostream& operator<<(ostream&, const human&); 
};

#endif

