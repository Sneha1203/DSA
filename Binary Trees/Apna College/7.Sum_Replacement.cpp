#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <utility>
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

void sumReplacement (Node *root) {
	if (root == NULL) {
		return;
	}

	sumReplacement (root -> left);
	sumReplacement (root -> right);
	
	if (root -> left != NULL) 
		root -> data += root -> left -> data;
	if (root -> right != NULL) 
		root -> data += root -> right -> data;
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
    sumReplacement(root);
    Inorder (root);
    return 0;
}
