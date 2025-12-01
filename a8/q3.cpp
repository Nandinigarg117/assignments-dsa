#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*left;
    node*right;
    node(int d){
        data=d;
        left=right=NULL;
    }
};
node* insert_bst(node* root,int data){
    if(root==NULL){
        return new node(data);
    }

    if(data<root->data){
       root->left= insert_bst(root->left,data);
    }
      else if(data>root->data){
        root->right=insert_bst(root->right,data);
    }
        else{
        cout<<"duplicate value so ignored";
        return root;
        }
    return root;
}

node* delete_bst(node* root,int target){
if(root==NULL){
    return NULL;

}
if(target <root->data){
    root->left=delete_bst(root->left,target);
    return root;
}
else if(target >root->data){
    root->right=delete_bst(root->right,target);
    return root;
}
else{
    if(root->left==NULL&&root->right==NULL){
        delete root;
        return NULL;
    }
    else if(!root->right){
        node* temp=root->left;
        delete root;
        return temp;
    }
      else if(!root->left){
        node* temp=root->right;
        delete root;
        return temp;
    }
    else {
        node*child=root->left;
        node* parent=root;
        while(child->right){
            parent =child;
            child=child->right;
        }
        if(parent!=root){
            parent->right=child->left;
            child->left=root->left;
            child->right=root->right;
            delete root;
            return child;

        }
        else{
            child->right=parent->right;
            delete root;
            return child;
        }
    }

}
}

int depth_max(node*root){
    if(root==NULL){
        return 0;

    }
    int leftH=depth_max(root->left);
    int rightH=depth_max(root->right);
    return 1+max(leftH,rightH);
}
int depth_min(node*root){
    if(root==NULL){
        return 0;

    }
    int leftH=depth_min(root->left);
    int rightH=depth_min(root->right);
    return 1+min(leftH,rightH);
}
void inorder(node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main(){
    int size;
    int data;
    node*root=NULL;
    cout<<"enter number of nodes";
    cin>>size;
    for(int i=0;i<size;i++)
   {
    cin>>data;
    root=insert_bst(root,data);
   }
   inorder(root);
   int target;
   cout<<"enter element to delete ";
   cin>>target;
   delete_bst(root,target);
inorder(root);

   cout << "Maximum Depth: " << depth_max(root) << endl;
    cout << "Minimum Depth: " << depth_min(root) << endl;


}