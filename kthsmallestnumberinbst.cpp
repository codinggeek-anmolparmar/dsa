int solve(BinaryTreeNode<int>* root,int& i,int k){
    if(root==NULL)
    {
        return -1;
    }
    //;eft
    int leftans=solve(root->left,i,k);
    if(leftans!=-1)
    {
        return leftans;
    }
    //node
    i++;
    if(i==k)
    {
        return root->data;
    }
    //right
    return solve(root->right,i,k);
}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    // Write your code here.
    int i=0;
    int ans=solve(root,i,k);
    return ans;
}
