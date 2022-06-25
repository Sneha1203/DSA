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

int MPS (Node *root, int &res) {
    if (root == NULL) {
        return 0;
    }
    int l = MPS (root -> left, res);
    int r  = MPS (root -> right, res);


    int temp = max(max(l, r) + root -> val, root -> val);
    int ans = max (temp, l + r + root -> val);
    res = max (ans, res);
    return temp;
}

int calcMPS (Node *root) {
    if (root == NULL) {
        return 0;
    }
    int res = INT_MIN;
    res = MPS (root, res);
    return res;
}

int main() {
    Node *root = new Node (10);
    root -> left = new Node (2);
    root -> right = new Node (10);
    root -> left -> left = new Node (20);
    root -> left -> right = new Node (1);
    root -> right -> right = new Node (-25);
    root -> right -> right -> left = new Node (3);
    root -> right -> right -> right = new Node (4);
    cout << endl << calcMPS (root) << endl;
    return 0;
}