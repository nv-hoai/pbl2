#include "double_linked_list.h"

int main() {
    DoublyLinkedList<int> myList;
    myList.push_front(10);
    myList.push_back(20);
    myList.push_back(30);

    std::cout << "List size: " << myList.size() << std::endl;
    std::cout << "First element: " << myList.head()->data << std::endl;
    std::cout << "Last element: " << myList.tail()->data << std::endl;

    DoublyLinkedList<int>::Node *n1= myList.search(20);
    myList.remove(n1);
    myList.display();

    myList.pop_front();
    myList.pop_back();
    std::cout << "List size after pop_front and pop_back: " << myList.size() << std::endl;

    return 0;
}