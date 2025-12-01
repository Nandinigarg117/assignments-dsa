#include<iostream>
#include<queue>
using namespace std;
const int MAX=1000;

class node{
    public:
    int data;
    node*next;
    node(int d){
        data=d;
        next=NULL;
    }
};
node* adjlist[MAX]={0};
void add_edge(int u,int v){
    if(adjlist[u]==NULL){
        adjlist[u]=new node(v);
    }
    else{
    node* temp=adjlist[u];
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new node(v);
    }
     if(adjlist[v]==NULL){
        adjlist[v]=new node(u);
    }
    else{
    node* temp=adjlist[v];
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new node(u);
    }
     
}
void bfs_traversal(node* adjlist[],int vertices){
    queue <int> q;
    int visited[vertices]={0};
    q.push(0);
    visited[0]=1;

    for(int i=0;i<vertices;i++){
        int num=q.front();
        node*temp=adjlist[num];
        cout<<num;
        q.pop();
        while(temp!=NULL){
            if(!visited[temp->data]){
                q.push(temp->data);
            }
            temp=temp->next;
        }
    }
}
int main(){
int vertices,edges;
cout<<"enter number of vertices and edges ";
cin>>vertices>>edges;
int u,v;
for(int i=0;i<edges;i++){
    cout<<"enter edge u v";
    cin>> u>>v;
    add_edge(u,v);
}

for(int i=0;i<vertices;i++){
    cout<<i<<"->";
    node*temp=adjlist[i];
    while(temp){
        
        cout<<temp->data<<" ";
        temp=temp->next;

    }
    cout<<endl;
}


bfs_traversal(adjlist,vertices);
}