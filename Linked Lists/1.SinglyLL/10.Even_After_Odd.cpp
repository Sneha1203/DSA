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

void evenNodesAfterOdd (Node *&head) {
    Node *odd = head;
    Node *even = head -> next;
    Node *evenStart = even;

    while (odd -> next != NULL && even -> next != NULL) {
        odd -> next = even -> next;
        odd = odd -> next;
        even -> next = odd -> next;
        even = even -> next;
    }
    odd -> next = evenStart;
    if (odd -> next != NULL) {
        even -> next = NULL;
    }
}

void insertAtHead (Node *&head, int val) {
    Node *temp = new Node (val);    
    temp -> next = head;
    head = temp;
}

void insertAtPos (Node *&head, int val, int pos) {
    Node *temp = new Node (val);
    if (head == NULL) {
        head = temp;
        return;
    }
    Node *first = head;
    int count = 1;
    while (first -> next != NULL) {
        if (count == pos - 1) {
            temp -> next = first -> next;
            first -> next = temp;
        }
        first = first -> next;
        count++;
    }  
}

void insertAtTail (Node *&head, int val) {
    if (head == NULL) {
        insertAtHead (head, val);
        return;
    }
    Node *newNode = new Node (val);
    Node *temp = head;
    while (temp -> next != NULL) {
        temp = temp -> next;
    }
    temp -> next = newNode;
}

void printLL (Node *head) {
    if (head == NULL) {
        cout << "No nodes to print.\n";
        return;
    }
    Node *temp = head;
    while (temp != NULL) {
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node *head1 = NULL;
    insertAtTail (head1, 1);
    insertAtTail (head1, 2);
    insertAtTail (head1, 3);
    insertAtTail (head1, 4);
    insertAtTail (head1, 5);
    insertAtTail (head1, 6);
    cout << "LINKED LIST: ";
    printLL (head1);
    evenNodesAfterOdd (head1);
    cout << "LINKED LIST: ";
    printLL (head1);
    return 0;
}
