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

Node *searchInBST (Node *root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (root -> data == key) {
        return root;
    }

    if (key > root -> data) {
        return searchInBST (root -> right, key);
    } else {
        return searchInBST (root -> left, key);
    }
}


int main() {
    Node *root = NULL;
    root = buildBST (root, 4);
    buildBST(root, 2);
    buildBST(root, 5);
    buildBST(root, 1);
    buildBST(root, 3);
    buildBST(root, 6);

    Node *result = searchInBST (root, 9);
    if (result == NULL) {
        cout << "Key not found.\n";
    } else {
        cout << "Key found.\n";
    }
    return 0;
}
