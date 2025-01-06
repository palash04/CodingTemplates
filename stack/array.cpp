#include <iostream>
using namespace std;

class Stack{
private:
    int *arr;
    int top;
    int capacity;
    
public:
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }
    
    ~Stack() {
        delete[] arr;
    }
    
    void push(int val) {
        if (top == capacity - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = val;
    }
    
    int pop() {
        if (top == -1) {
            cout << "Stack underflow\n";
            return -1;
        }
        return arr[top--];
    }
    
    int peek() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

};


int main() {
    Stack stack(5);
    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    cout << "Top element: " << stack.peek() << "\n";
    stack.pop();
    cout << "Top element after pop: " << stack.peek() << "\n";
    
    
}



