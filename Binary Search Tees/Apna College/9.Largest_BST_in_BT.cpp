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

class Info {
    public:
        int min;
        int max;
        int size;
        int ans;
        bool isBST;
};

Node *buildBST (Node *root, int val) {
    if (root == NULL) {
        return new Node (val);
    }

    if (val < root -> data) {
        root -> left = buildBST (root -> left, val);
    } else {
        root -> right = buildBST (root -> right, val);
    }

    return root;
}

Info largestBST (Node *root) {
    if (root == NULL) {
        return {INT_MAX, INT_MIN, 0, 0, true};
    }

    if (root -> left == NULL && root -> right == NULL) {
        return {root -> data, root -> data, 1, 1, true};
    }

    Info left = largestBST (root -> left);
    Info right = largestBST (root -> right);

    Info current;
    current.size = 1 + left.size + right.size;

    if (left.isBST && right.isBST && left.max < root -> data && right.min > root -> data) {
        current.min = min (left.min, min(right.min, root -> data));
        current.max = max (left.max, max(right.max, root -> data));
        
        current.ans = current.size;
        current.isBST = true;

        return current;
    }

    current.ans = max(left.ans, right.ans);
    current.isBST = false;
    return current;
}

// int main() {
//     Node *root = new Node (15);
//     root -> left = new Node (20);
//     root -> right = new Node (30);
//     root -> left -> left = new Node (5);

//     cout << endl << "Size of Largest BST: " << largestBST(root).ans << endl;
//     return 0;
// }

int main() {
    Node *root = NULL;
    root = buildBST (root, 4);
    buildBST(root, 2);
    buildBST(root, 5);
    buildBST(root, 1);
    buildBST(root, 3);
    buildBST(root, 6);

    cout << endl << "Size of Largest BST: " << largestBST(root).ans << endl;
    return 0;
}