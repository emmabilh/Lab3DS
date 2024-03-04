// Emma Bilhimer
// Data Structures - Busch SP24
// Due March 4, 2024
// Lab Name: Stack
/*
Description: A stack is an abstract data type in which elements are added and removed
from only one end; a “last in, first out” structure. This stack must be implemented as a
linked structure (ie using pointers).
 o Class Name:
 ▪ Attributes:
 • a pointer pointing to the node on top of the stack
 ▪ Methods:
 • IsEmpty – check to see if the stack is empty
 • IsFull – check to see if the stack is full
 • Push – Add a new item on the stack
 • Pop – Removes the top item from the stack
 • Top – Returns a copy of the top item from the stack.
 */

#include <iostream>

class Node {
public:
    int data;
    Node* next;                                     // pointer to the next node in the stack

    // constructor
    Node(int value) {
        data = value;
        next = nullptr;                             // initialize next pointer to null
    }
};

// stack class;  uses pointers to nodes
class Stack {
private:
    Node* topNode;                                  // pointer to the top node of the stack

public:
// another constructor
    Stack() {
        topNode = nullptr;                          // initialize topNode pointer to null
    }

    // this will check if the stack is empty
    bool IsEmpty() {
        return (topNode == nullptr);                // if top Node is null, stack is empty
    }

    // this will check if the stack is full
    bool IsFull() {
// return false here, for simplicity, but i can always add new nodes for memory sake
        return false;
    }

    void Push(int value) {                      // add a new item onto the stack
        Node* newNode = new Node(value);
        newNode->next = topNode;                // updates top Node to point to the new node
        topNode = newNode;
    }

    // this will remove the top item from the stack and return its value
    int Pop() {
        if (IsEmpty()) {                                // check if the stack is empty
            std::cerr << "Stack is empty.\n";           // error message
            return -1;                                  // -1 as error code
        }
        
        int poppedValue = topNode->data;
        Node* temp = topNode;
        topNode = topNode->next;                        // update top Node
        delete temp;                        // delete the original top node for memory sake
        return poppedValue;
    }

    // Return the value of the top item from the stack without removing it
    int Top() {
        if (IsEmpty()) {
            std::cerr << "Stack is empty.\n";  // Print error message
            return -1;  // Assuming -1 as error code
        }
        
        return topNode->data;
    }
};

int main() {
    Stack myStack;
    myStack.Push(10);                                   //push elements onto the stack
    myStack.Push(20);
    myStack.Push(30);

 //pop & print
    std::cout << "Top element: " << myStack.Top() << std::endl;


    std::cout << "Popping elements:\n";
    while (!myStack.IsEmpty()) {
        std::cout << myStack.Pop() << std::endl;
    }

    std::cout << "Popping from empty stack:\n";
    std::cout << myStack.Pop() << std::endl;

    return 0;
}



