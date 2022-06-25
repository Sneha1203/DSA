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

int intersection (Node *&head1, Node *&head2) {
    int l1 = lengthOfLL (head1);
    int l2 = lengthOfLL (head2);
    int d;

    Node *ptr1;
    Node *ptr2;

    if (l1 > l2) {
        d = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    } else {
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }

    while (d) {
        ptr1 = ptr1 -> next;
        if (ptr1== NULL) {
            return -1;
        }
        d--;
    }

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 == ptr2) {
            return ptr1 -> data;
        }
        ptr1 = ptr1 -> next;
        ptr2 = ptr2 -> next;
    }
    return -1;
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

void intersect(Node* &head1, Node *&head2, int pos){
    Node* temp1=head1;
    pos--;
    while(pos--){
        temp1=temp1->next;
    }
    Node* temp2=head2;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp1;
}

int main() {
    Node *head1 = NULL;
    Node *head2 = NULL;
    insertAtTail (head1, 1);
    insertAtTail (head1, 2);
    insertAtTail (head1, 3);
    insertAtTail (head1, 4);
    insertAtTail (head1, 5);
    insertAtTail (head1, 6);
    insertAtTail (head2, 9);
    insertAtTail (head2, 10);
    cout << "LINKED LIST 1: ";
    printLL (head1);
    cout << "LINKED LIST 2: ";
    printLL (head2);
    intersect (head1, head2, 3);
    cout << endl << intersection (head1, head2);
    return 0;
}