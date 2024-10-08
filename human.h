#ifndef human_h
#define human_h
#include<string>
using namespace std;

class human
{
private:
    string first_name;
    string last_name;
    int age;
    string gender;
public:
    human();
    human(string a, string b, int c, string d);
    human(const human& person);
    void change_first_name(const string & newname);
    void change_last_name(const string& newname);
    void change_age(int newage);
    void change_gender(const string& newgender);
    void displayHuman() const;

};
#endif

