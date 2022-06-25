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

vector <int> rightView (Node *root) {
    vector <int> v;
    if (root == NULL)
        return v;

    queue <Node *> q;
    q.push (root);
    int count = 0;

    while (!q.empty()) {
        int n = q.size();
        
        for (int i = 0; i < n; i++) {
            Node *temp = q.front();
            q.pop();
            if (i == n - 1)
                v.push_back(temp -> data);
            if (temp -> left) 
                q.push (temp -> left);
            if (temp -> right)
                q.push (temp -> right);
            count++;
        }
        count++;
    }
    return v;
}

// void rightView (Node *root) {
// 	if (root == NULL) {
// 		return;
// 	}
// 	queue <Node *> q;
// 	q.push (root);
// 	while (!q.empty()) {
// 		int n = q.size();
// 		for (int i = 0; i < n; i++) {
// 			Node *temp = q.front();
// 			q.pop();
// 			if (i == n-1) {
// 				cout << temp -> data << " ";
// 			}
// 			if (temp -> left)
// 				q.push (temp -> left);
// 			if (temp -> right)
// 				q.push (temp -> right);
// 		}
// 	}
// }

int main () {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    // rightView(root);
    vector <int> v;
    v = rightView (root);
    int n = v.size();
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    return 0;
}