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

void Inorder (Node* root) {
    if (root == NULL) {
        return;
    }

    Inorder (root -> left);
    cout << root -> data << " ";
    Inorder (root -> right);
}

int searchPos (int in[], int start, int end, int curr) {
    for (int i = start; i <= end; i++) {
        if (in[i] == curr)
            return i;
    }
    return -1;
}

Node *buildTree (int post[], int in[], int start, int end) {
    static int index = end;

    if (start > end)
        return NULL;

    int curr = post[index];
    index--;

    int pos = searchPos (in, start, end, curr);

    Node *first = new Node (curr);

    if (start == end)
        return first;
    
    first -> right = buildTree(post, in, pos + 1, end);
    first -> left = buildTree(post, in, start, pos - 1);
    return first;
}


int main () {
    int postorder[] = {4, 2, 5, 3, 1};
    int inorder[] = {4, 2, 1, 5, 3};

    Node *root = buildTree (postorder, inorder, 0, 4);
    Inorder (root);
    return 0;

}