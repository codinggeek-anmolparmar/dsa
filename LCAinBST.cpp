TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	// Write your code here
    if(root==NULL)
    {
     return NULL;
    }
    if (root->data < P->data && root->data < Q->data) {
    return LCAinaBST(root->right,P,Q);
    
    }
    if (root->data > P->data && root->data > Q->data)
    {
     return LCAinaBST(root->left,P,Q);

    } else {
      return root;
    }
}
//or
TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	// Write your code here
    if(root==NULL)
    {
     return NULL;
    }
    if (root->data < P->data && root->data < Q->data) {
    return LCAinaBST(root->right,P,Q);
    
    }
    if (root->data > P->data && root->data < Q->data)
    {
     return LCAinaBST(root->left,P,Q);

    }
    if(root->data > P->data && root->data < Q->data)
    {
        return root;
    }
    if(root->data < P->data && root->data < Q->data)
    {
        return root;
    }
}
//but in the second code we have given runtime error as we are again checkng in the first we are using just the else statement .To avoid the TLE kindly use the first one.
