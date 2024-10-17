#include <iostream>
#include "double_linked_list.h"

using namespace std;

// Example usage
int main() {
    DoublyLinkedList<int> list;

    list.append(10);
    list.append(20);
    list.append(30);
    list.prepend(5);

    cout << "List: ";
    list.display();

    // Find a value
    auto it = list.find(20);
    if (it != list.end())
        cout << "Found: " << *it << endl;
    else
        cout << "Value not found" << endl;

    // Use iterator to traverse the list
    cout << "Iterating forward: ";
    for (auto iter = list.begin(); iter != list.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    // Deleting a node
    list.deleteNode(it);
    cout << "List after deletion: ";
    list.display();

    return 0;
}