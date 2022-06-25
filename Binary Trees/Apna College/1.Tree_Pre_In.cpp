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

int searchPos (int in[], int start, int end, int curr) {
    for (int i = start; i <= end; i++) {
        if (in[i] == curr)
            return i;
    }
    return -1;
}

Node *buildTree (int pre[], int in[], int start, int end) {
    static int index = 0;

    if (start > end)
        return NULL;

    int curr = pre[index];
    index++;

    Node *first = new Node (curr);

    if (start ==  end)
        return first;
        
    int pos = searchPos (in, start, end, curr);
   

    first -> left = buildTree (pre, in, start, pos - 1);
    first -> right  = buildTree (pre, in, pos + 1, end);
    
    return first;
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

    int inorder[] = {1, 6, 8, 7};
    int preorder[] = {1, 6, 7, 8};

    Node *root = buildTree (preorder, inorder, 0, 3);
    Inorder (root);
    return 0;

}