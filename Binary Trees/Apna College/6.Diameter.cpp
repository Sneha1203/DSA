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

int Height (Node *root) {
    if (root == NULL) {
        return 0;
    }

    return max (Height (root -> left), Height (root -> right)) + 1;
}

int Diameter (Node *root) {

    if (root == NULL) {
        return 0;
    }
    
    int leftHeight = Height (root -> left);
    int rightHeight = Height (root -> right);

    int currentDiameter = leftHeight + rightHeight + 1;

    int leftDiameter = Diameter (root -> left);
    int rightDiameter = Diameter (root -> right);

    return max (currentDiameter, max (leftDiameter, rightDiameter));

}

int main () {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << endl << Diameter (root) << endl;
    return 0;
}