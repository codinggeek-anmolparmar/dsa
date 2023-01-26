void inordering(TreeNode<int> *root,vector<int> &anmol)
{
if(root==NULL)
{
     return;
}
inordering(root->left,anmol);
anmol.push_back(root->data);
inordering(root->right,anmol);
}
vector<int> merge(vector<int> &one,vector<int> &two)
{
    vector<int> ans(one.size()+two.size());
    int i=0;
    int j=0;
    int k=0;
    while(i<one.size() && j<two.size())
    {
        if(one[i]<two[j])
        {
          ans[k++]=one[i];
          i++;

        }
        else{

        ans[k++]=two[j];
        j++;

        }

    }
    while(i<one.size())
    {
        ans[k++]=one[i];
        i++;
    }
    while(j<<two.size())
    {
        ans[k++]=two[j];
        j++;
    }
    return ans;

}
TreeNode<int>* inordertobst(int s,int e,vector<int> &in)
{
    if(s>e){
        return NULL;
    
    }
    int mid=(s+e)/2;
TreeNode<int>* root=new TreeNode<int>(in[mid]);
root->left=inordertobst(s,mid-1,in);
root->right=inordertobst(mid+1,e,in);
return root;
}
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    // Write your code here.
    vector<int> bst1;
    vector<int> bst2;

    inordering(root1,bst1);
    inordering(root2,bst2);
    vector<int> mergearray=merge(bst1,bst2);
}
