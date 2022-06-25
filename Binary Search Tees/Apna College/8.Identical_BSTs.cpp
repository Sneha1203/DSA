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

bool areIdentical (Node *root1, Node *root2) {
    if (!root1 && !root2) {
        return true;
    }

    else if (!root1 || !root2) {
        return false;
    }

    else {
        bool dataCheck = (root1 -> data == root2 -> data);
        bool leftCheck = areIdentical (root1 -> left, root2 -> left);
        bool rightCheck = areIdentical (root1 -> right, root2 -> right);

        if (dataCheck && leftCheck && rightCheck) {
            return true;
        }

        return false;
    }

}

int main() {
    Node *root1 = new Node(2);
    root1 -> left = new Node (1);
    root1 -> right = new Node (3);
    Node *root2 = new Node(2);
    root2 -> left = new Node (1);
    root2 -> right = new Node (3);

    cout << endl << areIdentical (root1, root2) << endl;
    return 0;
}