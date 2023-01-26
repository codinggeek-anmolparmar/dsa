class info{
public:
int maxi;
int mini;
bool isbst;
int size;

};
info solve(TreeNode<int>* root,int &maxisize)
{
if(root==NULL)
{
    return {INT_MIN,INT_MAX,true,0};

    
}

info left=solve(root->left,maxisize);
info right=solve(root->right,maxisize);
info current;
current.size=left.size+right.size+1;
current.maxi=max(root->data,right.maxi);
current.mini=min(root->data,left.mini);
if(left.isbst && right.isbst && (root->data>left.maxi && root->data<right.mini))
{
    current.isbst=true;
}
else{
    current.isbst=false;

}
if(current.isbst)
{
    maxisize=max(maxisize,current.size);

}
return current;
}
int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    int maxisiz=0;
    info temp=solve(root,maxisiz);
    return maxisiz;
}
