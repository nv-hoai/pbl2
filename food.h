#ifndef food_h
#define food_h
#include <string>
using namespace std;

class food
{
private:
    int food_id;
    string name;
    int remain,cost;
    bool current_state;
    static int count;
public:
    food();
    food(int remain, int cost, string name);
    food( const food& f);
    void update_state();
    bool get_state();
    friend ostream& operator <<(ostream& out, const food& f);
};
#endif

