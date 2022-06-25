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

Node *buildBST (Node *root, int val) {
    if (root == NULL) {
        return new Node (val);
    }

    if (val < root -> data) {
        root -> left = buildBST (root -> left, val);
    } else {
        root -> right = buildBST (root -> right, val);
    }

    return root;
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
    Node *root = NULL;
    root = buildBST (root, 5);
    buildBST (root, 7);
    buildBST (root, 6);
    buildBST (root, 4);
    buildBST (root, 3);
    buildBST (root, 2);
    buildBST (root, 1);

    printInorder (root);
    
    return 0;
}