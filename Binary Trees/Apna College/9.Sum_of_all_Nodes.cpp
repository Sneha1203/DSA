int sumOfNodes (Node *root) {
	if (root == NULL) {
		return 0;
	}

	return sumOfNodes (root -> left) + sumOfNodes (root -> right) + root -> data;
}
