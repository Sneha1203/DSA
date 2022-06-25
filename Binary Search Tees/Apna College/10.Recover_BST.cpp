#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;

        Node (int val) {
            data = val;
            left = NULL;
            right = NULL;
    }
};

void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void calculatePointers (Node *root, Node **first, Node **mid, Node **last, Node **prev) {
    if (root == NULL) {
        return;
    }
    calculatePointers (root -> left, first, mid, last, prev);

    if (*prev && root -> data < (*prev) -> data) {
        if (!*first) {
            *first = *prev;
            *mid = root;
        }
        else {
            *last = root;
        }
    }
    *prev = root;
    calculatePointers (root -> right, first, mid, last, prev);
}

void restoreBST (Node *root) {
    Node *first, *mid, *last, *prev;
    first = mid = last = prev = NULL;

    calculatePointers (root, &first, &mid, &last, &prev);

    if (first && last) {
        swap (&(first -> data), &(last -> data));
    }
    else if (first && mid) {
        swap (&(first -> data), &(mid -> data));
    }
}

void printInorder (Node *root) {
    if (root == NULL) {
        return;
    }
    printInorder (root -> left);
    cout << root -> data << " ";
    printInorder (root -> right);
}

int main() {
    Node *root = new Node(6);
    root -> left = new Node(9);
    root -> right = new Node(3);
    root -> left -> left = new Node(1);
    root -> left -> right = new Node(4);
    root -> right -> right = new Node(13);

    printInorder (root);
    cout << "\n";
    restoreBST (root);
    printInorder (root);
    return 0;
}