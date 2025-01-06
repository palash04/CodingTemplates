#include <iostream>
using namespace std;

#define MAX 100

class Queue{
private:
    int front, rear, size;
    int arr[MAX];
    
public:
    Queue() {
        front = 0;
        rear = -1;
        size = 0;
    }
    
    void enqueue(int value) {
        if (size == MAX) {
            cout << "Queue is full (Overflow)\n";
            return;
        }
        rear = (rear + 1) % MAX;
        arr[rear] = value;
        size++;
    }
    
    void dequeue() {
        if (size == 0) {
            cout << "Queue is empty (Underflow)\n";
            return;
        }
        front = (front + 1) % MAX;
        size--;
    }
    
    int get_front() {
        if (size == 0) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }
    
    bool empty() {
        return size == 0;
    }
    
    int get_size() {
        return size;
    }
    
};


int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    
    cout << "Front element: " << q.get_front() << "\n";
    q.dequeue();
    cout << "Front element: " << q.get_front() << "\n";
    cout << "Queue size: " << q.get_size() << "\n";
}


