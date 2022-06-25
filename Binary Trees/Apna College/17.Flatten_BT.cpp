#include <iostream>
#include <queue>
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

void flattenBT (Node *root) {
    if (root == NULL) {
        return;
    }

    flattenBT (root -> left);

    if (root -> left != NULL) {
        Node *child = root -> right;
        root -> right - root -> left;
        Node *temp = root -> right;

        while (temp -> right != NULL) {
            temp = temp -> right;
        }
        temp -> right = child;
        root -> left = NULL;
    }

    flattenBT (root -> right);
}

void preorder (Node *root) {
    if (root == NULL) {
        return;
    }
    cout << root -> data << " ";
    preorder (root -> left);
    preorder (root -> right);
}

int main() {
    Node *root = new Node (1);
    root -> left = new Node (2);
    root -> left -> left = new Node (3);
    root -> left -> right = new Node (4);
    root -> right = new Node (5);
    root -> right -> right = new Node (6);
    preorder (root);
    cout << endl;
    flattenBT (root);
    preorder (root);
    return 0;
}