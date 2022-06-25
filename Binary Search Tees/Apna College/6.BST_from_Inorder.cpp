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

Node *buildFromInorder (int arr[], int start, int end) {
    if (start > end) {
        return NULL;
    }
    int mid = (start + end) / 2;
    Node *root = new Node (arr[mid]);

    root -> left = buildFromInorder (arr, start, mid - 1);

    root -> right = buildFromInorder (arr, mid + 1, end);

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
    int arr[] = {10, 20, 30, 40, 50};
    Node *root = buildFromInorder (arr, 0, 4);
    printPreorder (root);
    return 0;
}
