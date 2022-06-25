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

int lengthOfLL (Node *&head) {
    int l = 0;
    Node *temp = head;
    while (temp != NULL) {
        l++;
        temp = temp -> next;
    }
    return l;
}

Node *appendLastK (Node *&head, int k) {
    int l = lengthOfLL (head);
    int count = 1;
    Node *newTail, *newHead, *temp = head;
    while (temp -> next != NULL) {
        if (count == (l - k)) {
            newTail = temp;
        }
        if (count == (l - k + 1)) {
            newHead = temp;
        }
        count++;
        temp = temp -> next;
    }

    temp -> next = head;
    newTail -> next = NULL;

    return newHead;
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
    Node *head = NULL;
    insertAtTail (head, 1);
    insertAtTail (head, 2);
    insertAtTail (head, 3);
    insertAtTail (head, 4);
    insertAtTail (head, 5);
    insertAtTail (head, 6);
    cout << "LINKED LIST: ";
    printLL (head);
    head = appendLastK (head, 3);
    cout << "APPENDED LL: ";
    printLL (head);
    return 0;
}
