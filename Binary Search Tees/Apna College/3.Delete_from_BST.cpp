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

Node *inorderSuccessor (Node *root) {
    Node *current = root;
    while (current != NULL && current -> left != NULL) {
        current = current -> left;
    }
    return current;
}

Node *deleteFromBST (Node *root, int key) {
    if (root == NULL) {
        return NULL;
    }
    
    if (key > root -> data) {
        root -> right = deleteFromBST (root -> right, key);
    } 

    else if (key < root -> data) {
        root -> left = deleteFromBST (root -> left, key);
    }

    else if (key == root -> data) {
        if (root -> left == NULL) {
            Node *temp = root -> right;
            free (root);
            return temp;
        }

        else if (root -> right == NULL) {
            Node *temp = root -> left;
            free (root);
            return temp;
        }
        
        Node *temp = inorderSuccessor (root -> right);
        root -> data = temp -> data;
        root -> right = deleteFromBST (root -> right, temp -> data);
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
    root = buildBST (root, 4);
    buildBST(root, 2);
    buildBST(root, 5);
    buildBST(root, 1);
    buildBST(root, 3);
    buildBST(root, 6);

    printInorder (root);
    deleteFromBST (root, 5);
    printInorder (root);
    return 0;
}