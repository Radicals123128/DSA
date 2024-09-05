#include <iostream>

#define MAX 100  

class Stack {
private:
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() const {
        return top == -1;
    }

    bool isFull() const {
        return top == MAX - 1;
    }

    void push(int value) {
        if (isFull()) {
            std::cerr << "Stack overflow" << std::endl;
            return;
        }
        arr[++top] = value;
    }

    int pop() {
        if (isEmpty()) {
            std::cerr << "Stack underflow" << std::endl;
            return -1; 
        }
        return arr[top--];
    }

    int peek() const {
        if (isEmpty()) {
            std::cerr << "Stack is empty" << std::endl;
            return -1;  
        }
        return arr[top];
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    std::cout << "Top element is: " << s.peek() << std::endl;
    std::cout << "Popped element is: " << s.pop() << std::endl;
    std::cout << "Top element is now: " << s.peek() << std::endl;
    return 0;
}
