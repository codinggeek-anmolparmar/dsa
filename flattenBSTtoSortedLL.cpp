void inordering(TreeNode<int>* root,vector<int> ini)
{
    if(root==NULL)
    {
        return;
    }
    inordering(root->left,ini);
    ini.push_back(root->data);
    inordering(root->right,ini);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code here
vector<int> inorder;
inordering(root,inorder);
int n=inorder.size();
 TreeNode<int>* anmol= new TreeNode<int>(inorder[0]);
 TreeNode<int>* curr= anmol;

for(int i=1;i<n;i++)
{
    TreeNode<int> *temp=new TreeNode<int>(inorder[i]);
    curr->left=NULL;
    curr->right=temp;
    curr=temp;

}
curr->left=NULL;
curr->right=NULL;
return anmol;

}
