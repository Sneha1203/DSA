// recursive function is correct, but not working in VS Code, works fine on GFG.

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

Node *mergeIterative (Node *&head1, Node *&head2) {
    Node *p1 = head1;
    Node *p2 = head2;
    Node *newNode = new Node (-1);
    Node *p3 = newNode;

    while (p1 != NULL && p2 != NULL) {
        if (p1 -> data < p2 -> data) {
            p3 -> next = p1;
            p1 = p1 -> next;
        } else {
            p3 -> next = p2;
            p2 = p2 -> next;
        }
        p3 = p3 -> next;
    }

    while (p1 != NULL) {
        p3 -> next = p1;
        p1 = p1 -> next;
        p3 = p3 -> next;
    }

    while (p2 != NULL) {
        p3 -> next = p2;
        p2 = p2 -> next;
        p3 = p3 -> next;
    }

    return newNode -> next;
}

Node *mergeRecursive (Node *&head1, Node *&head2) {
    if (head1 == NULL) {
        return head2;
    }
    else if (head2 == NULL) {
        return head1;
    }

    Node *newNode = NULL;

    if (head1 -> data < head2 -> data) {
        newNode = head1;
        newNode -> next = mergeRecursive (head1 -> next, head2);    
    } else {
        newNode = head2;
        newNode -> next = mergeRecursive (head1, head2 -> next);
    }
    return newNode;
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
    Node *head2 = NULL;
    insertAtTail (head1, 1);
    insertAtTail (head2, 2);
    insertAtTail (head1, 3);
    insertAtTail (head2, 4);
    insertAtTail (head1, 5);
    insertAtTail (head1, 6);
    insertAtTail (head2, 7);
    insertAtTail (head1, 8);
    cout << "LINKED LIST 1: ";
    printLL (head1);
    cout << "LINKED LIST 2: ";
    printLL (head2);
    // Node *merged1 = mergeIterative (head1, head2);
    // cout << " MERGED LINKED LIST: ";
    // printLL (merged1);
    Node *merged2 = mergeRecursive (head1, head2);
    cout << " MERGED LINKED LIST: ";
    printLL (merged2);
    return 0;
}
