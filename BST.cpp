#include<bits/stdc++.h>
using namespace std;
class Node{
public:
  int data;
  Node* left;
  Node* right;
  Node(int m)
  {
    this->data=m;
    this->left=NULL;
    this->right=NULL;
  }
};
bool search(Node* root,int value)
{
  if(root==NULL)
  {
    return false;
  }
  if(root->data==value)
  {
    return true;
  }
  if(value<root->data)
  {
    //left ma jana ha
    return search(root->left,value);
  }
  if(value>root->data)
  {
    return search(root->right,value);
  }
}
Node* insertintobst(Node* root,int d)
{
  if(root==NULL)
  {
    root= new Node(d);
    return root;
  }
  else if(d<root->data)
  {
    //left ma dalna ha
    root->left=insertintobst(root->left,d);

  }
  else if(d>root->data)
  {
    //right ma dalna ha
    root->right=insertintobst(root->right,d);
  }
  return root;
}
void takeinput(Node* &root)
{

  int data;
  cin>>data;
  while(data!=-1)
  {
    root=insertintobst(root,data);
    cin>>data;
  }

}
Node* minval(Node* root)
{
  Node* test=root;
  while(test->left!=NULL)
  {
    test=test->left;
  }
  return test;
}
Node* maxval(Node* root)
{
  Node* test=root;
  while(test->right!=NULL)
  {
    test=test->right;
  }
  return test;
}
Node* delete(Node* root,int val)
{
  if(root==NULL)
  {
    return root;
  }
  if(root->data==val)
  {
    //0 child
  if(root->left==NULL && root->right==NULL)
{
  delete root;
  return NULL;
}

//1 child
//LEFT CHILD
if(root->right==NULL && root->left!=NULL)
{
  Node* temp=root->left;
  delete root;
  return temp;
}
//RIGHT CHILD
if(root->left==NULL && root->right!=NULL)
{
  Node* temp=root->right;
  delete root;
  return temp;
}
   //2 child
if(root->left!=NULL && root->right!=NULL)
{
  int mini=minval(root->right)->data;
  root->data=mini;
  root->right=delete(root->right,mini);
  return root;
  
}



  }
  if(val<root->data)
  {
    root->left=delete(root->left,val);
   return root;
  }
  if(val>root->data)
  {
    root->right=delete(root->right,val);
    return root;

  }
  return root;
}
int main()
{
  Node* root=NULL;
  cout<<"enter the elements you want to insert for the bst"<<endl;
  takeinput(root);
  bool ans=search(root,4);
  if(ans)
  {
    cout<<"yes present";
  }
  else{
    cout<<"not present";
  }
  cout<<endl;
cout<<minval(root)->data<<endl;
cout<<maxval(root)->data<<endl;
  return 0;
}
