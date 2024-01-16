#include "LinkedList.h"

int main() {
    LinkedList<int> myList;

    myList.AddToHead(1);
    myList.AddToTail(2);
    myList.AddToTail(3);
    myList.AddToTail(4);

    std::cout << "Original List: ";
    myList.Show();

    myList.InsertAtPosition(10, 2);
    std::cout << "List after inserting 10 at position 2: ";
    myList.Show();

    myList.DeleteAtPosition(1);
    std::cout << "List after deleting element at position 1: ";
    myList.Show();

    int searchValue = 3;
    int searchResult = myList.SearchElement(searchValue);
    if (searchResult != -1) {
        std::cout << "Element " << searchValue << " found at position " << searchResult << std::endl;
    }
    else {
        std::cout << "Element " << searchValue << " not found in the list\n";
    }

    int oldValue = 2;
    int newValue = 20;
    int replaceCount = myList.ReplaceElement(oldValue, newValue);
    std::cout << "List after replacing " << oldValue << " with " << newValue << ": ";
    myList.Show();
    std::cout << "Number of replacements: " << replaceCount << std::endl;

    std::cout << "List after reversing: ";
    myList.Reverse();
    myList.Show();

    myList.DeleteAll();
    std::cout << "List after deleting all elements: ";
    myList.Show();

    return 0;
}
