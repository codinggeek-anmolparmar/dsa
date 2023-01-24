void inordering(TreeNode<int>* root,vector<int> &ini)
{
    if(root=NULL)
    {
        return ;

    }
    inordering(root->left,ini);
    ini.push_back(root->data);
    inordering(root->right,ini);
}
TreeNode<int>* inordertoBST(int s,int e,vector<int> &inordering)
{
   if(s>e)
   {
       return NULL;
   }
   int mid=(s+e)/2;
   TreeNode<int>* root=new TreeNode<int>(inordering[mid]);
   root->left=inordertoBST(s,mid-1,inordering);
   root->right=inordertoBST(mid+1,e,inordering);
   return root;

}
TreeNode<int>* balancedBst(TreeNode<int>* root) {
    // Write your code here.
    vector<int> inorder;
    inordering(root,inorder);
return inordertoBST(0,inorder.size()-1,inorder);
}
