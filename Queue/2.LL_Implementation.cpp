#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node (int val) {
            data = val;
            next = NULL;
        }
};

class Queue {
    Node *front;
    Node *rear;

    public:

        Queue () {
            front = NULL;
            rear = NULL;
        }

        bool isEmpty();
        void push (int val);
        void pop();
        int peekFront();
        void printQueue();
};

bool Queue :: isEmpty() {
    if (front == NULL)
        return true;
    return false;
}

void Queue :: push (int val) {
       Node *n = new Node (val);

       if (front == NULL) {
           front = n;
           rear = n;
           return;
       }
       
       rear -> next = n;
       rear = n;
}

void Queue :: pop() {
    if (isEmpty()) {
        cout << "Queue Underflow.\n";
        return;
    }

    Node *temp = front;
    front = front -> next;
    delete temp;
}

int Queue :: peekFront() {
    if (isEmpty()) {
        cout << "Queue Underflow.\n";
        return -1;
    }

    return front -> data;
}

void Queue :: printQueue() {
    if (isEmpty()) {
        cout << "Queue Underflow, no elements to print.\n";
        return;
    }

    Node *temp = front;
    while (temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main() {
    Queue q;
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