#include <iostream>
using namespace std;

class Node {
    public:
        Node * left;
        Node * right;
        int val;

        Node (int data) {
            left = NULL;
            right = NULL;
            val = data;
        }
};

int heightBT (Node *root, int &res) {
    if (root == NULL) {
        return 0;
    }
    int left = heightBT (root -> left, res);
    int right = heightBT (root -> right, res);

    // int temp = 1 + max (left, right);
    // res = max (1+left+right, res);
    // return temp;
    int temp = 1 + max (left, right);
    int ans = max (temp, 1 + left + right);
    res = max (res, ans);
    return temp;
}

int diameterBT (Node *root) {
    if (root == NULL) {
        return 0;
    }
    int res = INT_MIN;
    res = heightBT (root, res);
    return res;
}

int main() {
    Node *root = new Node (1);
    root -> left = new Node (2);
    root -> right = new Node (3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    // root -> left -> left = new Node (4);
    // root -> left -> right = new Node (5);
    // root -> left -> right -> left = new Node (6);
    // root -> left -> right -> right = new Node (7);
    // root -> right -> right = new Node (8);
    // root -> right -> right -> right = new Node (9);
    // root -> right -> right -> right -> left = new Node (10);
    // root -> right -> right -> right -> left -> left = new Node (12);
    // root -> right -> right -> right -> left -> right = new Node (13);
    // root -> right -> right -> right -> right = new Node (11);
    
    
    cout << endl << "DIAMETER : " << diameterBT (root) << endl;
    return 0;
}