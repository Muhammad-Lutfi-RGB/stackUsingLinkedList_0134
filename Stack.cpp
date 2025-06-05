#include <iostream>
using namespace std;

// Node class representing a single node in the linked list
class Node {
    public:
    int data;
    Node *next;

    Node() {
        next = NULL;
    }
};

class Stack {
    private:
    Node *top; // Pointer to the top nod of the stack

    public:
    Stack () {
        top = NULL; // Initialize the stack with a null top pointer
    }

    // Push operation: insert an element onto the top of the stack
    int push (int value) {
        Node *newNode = new Node(); // 1. allocate memory for the new node
        newNode->data = value; // 2. assign value
        newNode->next = top; // 3. set the next pointer of the new node to the current top
        top = newNode; // 4. update the top pointer to the new node
        cout << "Push value: " << value << endl;
        return value;
    } 
// Is empty operation: check if the stack is empty
bool isEmpty () {
    return top == NULL; // Return true if the top pointer is NULL, indicating an empty stack
}

// Pop operation: Remove the topmost element from the stack
void pop () {
    if (isEmpty()) {
        cout << "stack is empty." << endl;
        return; //if the stack is empty, print a message and return
    }
    cout << "popped value: " << top->data << endl;
    top = top->next; // Update the top pointer to the next node
}

//peek/Top operation: Retrieve the value of the topmost element without removing it
void peek() {
    if (isEmpty()) {
        cout << "list is empty." << endl;
        return; // if the stack is empty, print a message and return
    }
    else {
        Node *current = top;
        while (current != NULL) {
            cout << current->data << " " << endl;
            current = current->next;
        }
        cout << endl;
    } // return the value to the top node
}    
};

int main() {
    Stack Stack;

    int choice = 0;
    int value;

    while (choice != 4) {
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Exit\n";
        cout << "enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
            cout << "Enter the value to push: ";
            cin >> value;
            Stack.push(value); //Push the entered value onto the stack
            break;

            case 2:
            Stack.pop(); // Pop the topmost element from the stack
            break;

            case 3:
            Stack.peek();
            break;

            case 4:
            cout << "exiting program." << endl;
            break;

            default:
            cout << "invalid choice. Try again." << endl;
            break;
        }

        cout << endl;

    }

    return 0;
}