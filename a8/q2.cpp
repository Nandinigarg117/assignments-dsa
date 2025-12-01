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
      else{
        root->right=insert_bst(root->right,data);
    }

    return root;
}

//(A)

bool search_recursive(node*root,int key){
     if(root==NULL){
        return false;
     }

     if(key<root->data){
       return search_recursive(root->left,key);
     }
     else if(key>root->data){
        return search_recursive(root->right,key);
     }
     else if(key==root->data){
        return true;
     }

}
bool search_iterative(node* root,int key ){
    if(root==NULL){
        return false;
    }
node*temp=root;
while(temp!=NULL){
    if(key==temp->data){
        return true;
    }
    else if(key<temp->data){
       
       temp=temp->left;
     }
     else {
       
        temp=temp->right;
     }
}

return false;
}
void inorder (node * root){
    if(root==NULL)
    return;
    inorder(root->left);
     
    cout<<root->data;
   
    inorder(root->right);
}
//(B)
int maximum_bst(node*root){
while(root->right!=NULL){
    root=root->right;
}    
return root->data;
}
//(C)
int minimum_bst(node*root){
while(root->left!=NULL){
    root=root->left;
}    
return root->data;
}
//(D)
int inorder_successor(node* root,int key){
node* curr=root;
node* succ=NULL;

while(curr!=NULL){
    if(key<curr->data){
        succ=curr;
        curr=curr->left;

    }
    else if(key>curr->data){
        
        curr=curr->right;
        
    }
     else{
       // leftmostinrightsubtree
       if(curr->right!=NULL){
        curr=curr->right;
        while(curr->left!=NULL){
            curr=curr->left;
        }
        succ=curr;
    }
break;
}
}
if(succ==NULL){
    return -1;
}

return succ->data;
}
//(E)
int inorder_predecessor(node* root,int key){
node* curr=root;
node* pred=NULL;

while(curr!=NULL){
    if(key<curr->data){
      
        curr=curr->left;

    }
    else if(key>curr->data){
        pred=curr;
        curr=curr->right;
        
    }
     else{
      
       if(curr->left!=NULL){
        curr=curr->left;
        while(curr->right!=NULL){
            curr=curr->right;
        }
    pred= curr;
}
break;
    }

}
if(pred==NULL){
    return -1;
}
return pred->data;
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

   inorder (root);
int key;
cout<<"\nenter key ";
cin>>key;
  cout<< search_recursive(root,key);
   cout<<endl<<search_iterative(root,key)<<endl;
   cout<<"maximum "<<maximum_bst(root)<<" "<<"minimum "<<minimum_bst(root)<<endl;
   cout<<inorder_predecessor(root,key);
   cout<<inorder_successor(root,key);
}