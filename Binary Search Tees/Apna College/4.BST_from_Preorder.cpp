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

Node *buildFromPreorder (int preorder[], int *preIdx, int key, int min, int max, int size) {
    
    if (*preIdx >= size) {
        return NULL;
    }

    Node *root = NULL;

    if (key > min && key < max) {
        root = new Node (key);
        *preIdx = *preIdx + 1;

        if (*preIdx < size) {
            root -> left = buildFromPreorder (preorder, preIdx, preorder[*preIdx], min, key, size);
        }

        if (*preIdx < size) {
            root -> right = buildFromPreorder (preorder, preIdx, preorder[*preIdx], key, max, size);
        }

    }
    return root;
}

void printPreorder (Node *root) {
    if (root == NULL){
        return;
    }

    cout << root -> data << " ";
    printPreorder (root -> left);
    printPreorder (root -> right);

}

int main() {
    int preorder[] = {10, 2, 1, 13, 11};
    int size = 5;
    int preIdx = 0;
    Node *root = buildFromPreorder (preorder, &preIdx, preorder[0], INT_MIN, INT_MAX, size);
    printPreorder (root);
    return 0;
}