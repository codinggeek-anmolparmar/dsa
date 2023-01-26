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
void convertintodoublyll(TreeNode<int> *root,TreeNode<int> &head)
{
    if(root==NULL)
    {
        return NULL;
    }
    convertintodoublyll(root->right,head);
    root->right=head;
    if (head != NULL) {
      head->left = root;
      head = root;
    }

    convertintodoublyll(root-.left,head);
}
void mergelinkedlist(TreeNode<int> *head1,TreeNode<int> *head2)
{
    TreeNode<int> *head=NULL;
    TreeNode<int> *tail=NULL;
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data<head2->data)
        {
            if(head==NULL)
            {
            head=head1;
            tail=head1;
            head1=head1->right;



 
            }
            else{
            tail->right=head1;
            head1->left=tail;
            tail=head1;
            head1=head1->right;


            }
        }
        else{
            if(head==NULL){
             head=head2;
             tail=head2;
             head1=head2->right;




            }
            else{
            tail->right=head2;    
            head2->left=tail;
            tail=head2;
            head2=head2->right;
            }
        }
    }
    while(head1!=NULL)
    {
            tail->right=head1;
            head1->left=tail;
            tail=head1;
            head1=head1->right;
    }
    while(head2!=NULL)
    {
            tail->right=head2;    
            head2->left=tail;
            tail=head2;
            head2=head2->right;

    }
    return head;
}
int countnodes(TreeNode<int> *head)
{
    int counter=0;
    TreeNode<int> *temp=head;
    while(temp!=NULL)
    {
        counter++;
         temp=temp->right;
    }
    return counter;
}
TreeNode<int>* sortedlltobst(TreeNode<int>* &head,int n)
{
 //base case
 if(n<=0 || head==NULL)
 {
     return NULL;
 }
 TreeNode<int> *left=sortedlltobst(head,n/2);
 TreeNode<int> *root=head;
 root->left=left;
 head=head->next;
 root->right=sortedtollbst(head,n-n/2-1);
 return root;

}
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    // Write your code here.
    // vector<int> bst1;
    // vector<int> bst2;

    // inordering(root1,bst1);
    // inordering(root2,bst2);
    // vector<int> mergearray=merge(bst1,bst2);
    //step1
    TreeNode<int> *head1=NULL;
    convertintodoublyll(root1,head1);
    head1->left=NULL;
    TreeNode<int> *head2=NULL;
    convertintodoublyll(root2,head2);
    head2->left=NULL;
    // step2
    TreeNode<int> *head=mergelinkedlist(head1,head2);
    //step3
    return sortedlltobst(head,countnodes(head));

}
