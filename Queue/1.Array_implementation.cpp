#include <iostream>
using namespace std;

class Queue {
    int size;
    int *arr;
    int front;
    int rear;

    public:

    Queue (int n) {
        size = n;
        arr = new int [size];
        front = -1;
        rear = -1;
    }

    bool isEmpty();
    bool isFull();
    void push (int val);
    void pop();
    int peekFront();
    void printQueue();
};

bool Queue :: isEmpty() {
    if (front == -1)
        return true;
    return false;
}

bool Queue :: isFull() {
    if (rear == size - 1) 
        return true;
    return false;
}

void Queue :: push (int val) {
    if (isFull()) {
        cout << "Queue Overflow.\n";
    }
    rear++;
    arr[rear] = val;

    if (front == -1)
        front++;    
}

void Queue :: pop() {
    if (isEmpty()) {
        cout << "Queue Underflow.\n";
    }
    front++;
}

int Queue :: peekFront() {
    if (isEmpty()) {
        cout << "Queue Underflow.\n";
        return -1;
    }
    return arr[front];
}

void Queue :: printQueue() {
    if (isEmpty()) {
        cout << "Queue Underflow, no elements to print.\n";
    }
    int temp = front;
    while (temp <= rear) {
        cout << arr[temp] << " ";
        temp++;
    }
    cout << endl;
}

int main() {
    Queue q (5);
    q.push (1);
    q.push (2);
    q.push (3);
    q.push (4);
    q.push (5);

    q.pop();
    cout << q.peekFront() << " is the front element.\n";
    q.printQueue();
    q.pop();
    q.pop();
    q.printQueue();
    return 0;
}