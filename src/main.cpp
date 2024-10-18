#include <iostream>
#include "double_linked_list.h"
#include "SystemManager.h"

using namespace std;

// Example usage
int main() {
    SystemManager MyManager;

    MyManager.add_computer();
    MyManager.add_computer();
    MyManager.show_all_computers();

    MyManager.update_computer_device_state(0, 0, 0);
    MyManager.show_all_computers();

    return 0;
}