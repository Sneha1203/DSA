#include <iostream>
#include <stack>
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

void ZigZag (Node *root) {
    if (root == NULL) {
        return;
    }

    stack <Node *> currLevel;
    stack <Node *> nextLevel;

    bool leftToRight = true;

    currLevel.push (root);

    while (!currLevel.empty()) {
        Node *temp = currLevel.top();
        currLevel.pop();

        if (temp) {
            cout << temp -> data << " ";

            if (leftToRight) {
                if (temp -> left) {
                    nextLevel.push (temp -> left);
                }
                if (temp -> right) {
                    nextLevel.push (temp -> right);
                }
            } 

            else {
                if (temp -> right) {
                    nextLevel.push (temp -> right);
                }
                if (temp -> left) {
                    nextLevel.push (temp -> left);
                }
            }
        }

        if (currLevel.empty()) {
            leftToRight = !leftToRight;
            swap (currLevel, nextLevel);
        }

    }
}

int main() {
    Node* root = new Node(12);
    root->left = new Node(9);
    root->right = new Node(15);
    root->left->left = new Node(5);
    root->left->right= new Node(10);

    ZigZag (root);
    return 0;
}



#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = right = 0;
    }
};


// vector<int> level(Node *curr)
// {
//     vector<int> ans;
//     if (curr == NULL)
//         return ans;
//     int f = 1;
//     queue<Node *> q;
//     q.push(curr);
//     while (!q.empty())
//     {
//         vector<int> temp;
        
//         int sz = q.size();
//         while (sz--)
//         {
//             Node *t = q.front();
//             temp.push_back(t -> data);
//             q.pop();
//             if (t->left != NULL)
//                 q.push(t->left);
//             if (t->right != NULL)
//                 q.push(t->right);
//         }
//         if (f % 2 == 0)
//             reverse(temp.begin(), temp.end());
//         for (int i = 0; i < temp.size(); i++)
//             ans.push_back(temp[i]);
//         f = !f;
//     }
//     return ans;
// }

// int main()
// {

//     Node *root = new Node(1);
//     root->left = new Node(2);
//     root->right = new Node(3);
//     root->left->left = new Node(4);
//     root->left->right = new Node(5);
//     root->left->right->left = new Node(8);
//     root->right->left = new Node(6);
//     root->right->right = new Node(7);
//     root->right->right->left = new Node(9);
//     root->right->right->right = new Node(10);

//     vector<int> ans;
//     ans = level(root);

//     cout << "The zigzag Traversal is : ";
//     for (int i = 0; i < ans.size(); i++)
//     {
//         cout << ans[i] << " ";
//     }
//     return 0;
// }