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

int sumAtLevelK (Node *root, int K) {
	if (root == NULL) {
		return -1;
	}
	queue <Node *> q;
	q.push (root);
	int level = 0;
	int sum = 0;
	while (!q.empty()) {
		int n = q.size();
		
		for (int i = 0; i < n; i++) {
			Node *temp = q.front();
			q.pop();
			if (level == K) {
				sum += temp -> data;
			}
			if (temp -> left)
				q.push (temp -> left);
			if (temp -> right)
				q.push (temp -> right);
			 
		}
        level++;
	}
	return sum;
}

int main () {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << endl << sumAtLevelK (root, 2) << endl;
    return 0;
}