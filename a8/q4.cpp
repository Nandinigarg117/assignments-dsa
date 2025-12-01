#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*left;
    node* right;
    node(int data){
        this->data=data;
        left =right=NULL;
    }
};
node* buildtree(node* root){

    int data;
    cin>>data;

    

    if(data==-1){
        return NULL;
    }

    root= new node(data);

    cout<<"enter left element of "<<data;
    root->left=buildtree(root->left);

     cout<<"enter right element of "<<data;
    root->right=buildtree(root->right);

 return root;
}
int min_value(node* root){
while(root->left!=NULL){
    root=root->left;
}
return root->data;
}
int max_value(node* root){
while(root->right!=NULL){
    root=root->right;
}
return root->data;
}
bool bst_or_not(node* root,int min,int max){
    if(root==NULL){
        return true ;
    }
   if(root->data<min||root->data>max){
    return false;
   }
   return bst_or_not(root->left,min,root->data)&&
   bst_or_not(root->right,root->data,max);
}


int main(){

    cout<<"enter root data";
    node* root=NULL;
    root= buildtree(root);

    int minimum=min_value(root);
     int maximum=max_value(root);
    
    cout<<bst_or_not(root,minimum,maximum);


}