void inordering(BinaryTreeNode<int>* root,vector<int> &inorder)
{
if(root==NULL)
{
    return ;
}

inordering(root->left,inorder);
inorder.push_back(root->data);
inordering(root->right,inorder);

}
bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	//Write your code here
    vector<int> inorder;
    inordering(root,inorder);
    int i=0;
    int j=inorder.size()-1;
    while(i<j)
    {
        int sum=inorder[i]+inorder[j];
        if(sum==target)
        {
            return true;
        }
        else if(sum>target){
            j--;
        }
        else{
            i++;
        }
    }
    return false;
}
