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

Node* lca(Node* root ,int n1 ,int n2 )
    {
        if (root == NULL) {
            return NULL;
        }
        
        if (root -> data == n1 || root -> data == n2) {
            return root;
        }
        
        Node *left = lca (root -> left, n1, n2);
        Node *right = lca (root -> right, n1, n2);
        
        if (left && right) {
            return root;
        }
        
        if (left)
            return left;
        else 
            return right;
    }

int main () {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Node *LCA = lca (root, 4, 7);
    if (LCA) {
        cout << "LCA : " << LCA -> data << endl;
    } else {
        cout << "LCA doesn't exist." << endl;
    }
    return 0;
}