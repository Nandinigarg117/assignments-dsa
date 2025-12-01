
#include <iostream> 
#include <vector> 
#include <queue> 
using namespace std; 
 
vector<int> dijkstra(int n, vector<vector<pair<int,int>>> &graph, int src){ 
    vector<int> dist(n, 1e9); 
    dist[src]=0; 
 
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; 
 
    pq. push({0,src}); 
 
    while(!pq.empty()){ 
        int currDist = pq.top().first; 
        int u = pq.top().second; 
        pq.pop(); 
 
        // Explore all neighbors 
        for (auto edge : graph[u]) { 
            int v = edge.first;   // neighbor 
            int w = edge.second;  // weight 
 
            // Relaxation step 
            if (currDist + w < dist[v]) { 
                dist[v] = currDist + w; 

                pq.push({dist[v], v}); 
            } 
        } 
    } 
 
    return dist; 
}  
 
int main(){ 
    int n,m,directed; 
 
    cout<<"enter the number of nodes: "; 
    cin>>n; 
    cout<<"enter number of edges: "; 
    cin>>m; 
    cout<<"for directed = 1 and undirected = 0 --> "; 
    cin>>directed; 
 
    vector<vector<pair<int,int>>> graph(n); 
 
    cout<<"\nenter edges (u) (v) (w): "; 
    for(int i=0; i<m; i++){ 
        int u,v,w; 
        cin>>u>>v>>w; 
 
        graph[u].push_back({v,w}); 
        if(!directed){ 
            graph[v].push_back({u,w}); 
        } 
    } 
     int src; 

cin >> src; // source node 
vector<int> dist = dijkstra(n, graph, src); 
// Printing the result 
for (int i = 0; i < n; i++) { 
cout << "Distance from " << src << " to " << i << " = " << dist[i] << "\n"; 
} 
}