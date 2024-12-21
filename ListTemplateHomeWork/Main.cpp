#include <iostream>
#include "List.h"

int main() {
    List<int> myList;

    myList.push_back(10);
    myList.push_back(20);
    myList.push_front(5);

    std::cout << "Front: " << myList.front() << std::endl;
    std::cout << "Back: " << myList.back() << std::endl;

    myList.pop_front();
    std::cout << "Pop_front, front: " << myList.front() << std::endl;

    myList.pop_back();
    std::cout << "Pop_back, back: " << myList.back() << std::endl;

    myList.clear();
    std::cout << "Is empty: " << myList.empty() << std::endl;

    return 0;
}
