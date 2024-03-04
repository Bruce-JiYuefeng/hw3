#include <iostream>
#include "Stack.h" 

int main() {
    Stack<int> myStack;

    std::cout << "Pushing elements onto stack\n";
    for (int i = 0; i < 5; ++i) {
        myStack.push(i);
        std::cout << "Pushed: " << i << std::endl;
    }

    std::cout << "\nCurrent stack size: " << myStack.size() << std::endl;

    std::cout << "\nTop element: " << myStack.top() << std::endl;

    std::cout << "\nPopping elements from stack\n";
    while (!myStack.empty()) {
        std::cout << "Popped: " << myStack.top() << std::endl;
        myStack.pop();
    }

    try {
        std::cout << "\nAttempting to pop from empty stack\n";
        myStack.pop();
    } catch (const std::underflow_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
