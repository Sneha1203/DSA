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

void printSubtreeNodes (Node *root, int k) {
    if (root == NULL || k < 0) {
        return;
    }

    if (k == 0) {
        cout << root -> data << " ";
        return;
    }

    printSubtreeNodes (root -> left, k - 1);
    printSubtreeNodes (root -> right , k - 1);   
}

int printNodesAtK (Node *root, Node *target, int k) {
    if (root == NULL) {
        return -1;
    }

    if (root == target) {
        printSubtreeNodes (root, k);
        return 0;
    }


}