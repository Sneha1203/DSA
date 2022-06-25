bool check (Node *root, Node *min, Node *max) {
    if (root == NULL)
        return true;
            
    if (min != NULL && min -> data >= root -> data)
        return false;
        
    if (max != NULL && max -> data <= root -> data)
        return false;
            
    bool leftCheck = check (root -> left, min, root);
    bool rightCheck = check (root -> right, root, max);
    return leftCheck && rightCheck;
}
    