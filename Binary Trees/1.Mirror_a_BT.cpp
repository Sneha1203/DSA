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

void mirrorBT (Node *root) {
    if (root == NULL) {
        return;
    }

    if (root -> left == NULL && root -> right == NULL) {
        return;
    }

    mirrorBT (root -> left);
    mirrorBT (root -> right);

    if (root -> left || root -> right) {
        Node *temp = root -> left;
        root -> left = root -> right;
        root -> right = temp;
    }
}

void Inorder (Node* root) {
    if (root == NULL) {
        return;
    }

    Inorder (root -> left);
    cout << root -> data << " ";
    Inorder (root -> right);
}

int main () {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Inorder (root);
    cout << endl;
    mirrorBT (root);
    Inorder (root);
    return 0;
}