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

void inorder(node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);

}

void postorder(node*root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    
    postorder(root->right);
    cout<<root->data;
}

void preorder(node*root){
     if(root==NULL){
        return;
    }
     cout<<root->data;
    preorder(root->left);
    preorder(root->right);
}

int main(){

    cout<<"enter root data";
    node* root=NULL;
    root= buildtree(root);
    cout<<"inorder";
    inorder(root);
    cout<<endl;
    cout<<"preorder";
    preorder(root);
    cout<<endl;
cout<<"postorder";
    postorder(root);
    cout<<endl;



}