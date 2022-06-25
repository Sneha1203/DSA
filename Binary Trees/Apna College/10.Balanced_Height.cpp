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

int height (Node *root) {
        if (root == NULL) {
            return 0;
        }
        int leftHeight = height (root -> left);
        int rightHeight = height (root -> right);
        
        return max (leftHeight, rightHeight) + 1;
        
    }
    
bool isBalanced(Node *root)
{
    if (root == NULL) {
        return 1;
    }
        
    bool check = (abs (height (root -> left) - height (root -> right)) <= 1);
    bool checkLeft = isBalanced (root -> left);
    bool checkRight = isBalanced (root -> right);
    
    if (check && checkLeft && checkRight)
        return 1;
    else
        return 0;    
}

int main () {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(6);
    root->right->left = new Node(5);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);

    if (isBalanced (root)) {
        cout << "\nBALANCED.\n";
    } else {
        cout << "\nUNBALANCED.\n";
    }
}