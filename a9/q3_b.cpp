
#include <iostream> 
#include<vector> 
#include <queue> 
 
using namespace std; 
 
// Prim's Algorithm for Minimum Spanning Tree 
int prim(int n, vector<vector<pair<int,int>>>& graph) { 
    vector<bool> vis(n, false); 
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; 
 
    pq.push({0, 0});  // {weight, node}   start from node 0 
    int mst_weight = 0; 
 
    while (!pq.empty()) { 
        auto top = pq.top(); 
        int w = top.first; 
        int u = top.second; 
 
        pq.pop(); 
 
        if (vis[u]) continue; 
        vis[u] = true; 
 
        mst_weight += w; 
 
        // Push all edges from this node 
        for (auto &p : graph[u]) { 

            int v = p.first;     // neighbor 
            int wt = p.second;   // weight 
            if (!vis[v]) { 
                pq.push({wt, v}); 
            } 
        } 
    } 
    return mst_weight; 
} 
 
int main() { 
    int n, m; 
    cout << "Enter number of nodes: "; 
    cin >> n; 
    cout << "Enter number of edges: "; 
    cin >> m; 
 
    vector<vector<pair<int,int>>> graph(n); 
 
    cout << "Enter edges (u v w): \n"; 
    for (int i = 0; i < m; i++) { 
        int u, v, w; 
        cin >> u >> v >> w; 
 
        graph[u].push_back({v, w}); 
        graph[v].push_back({u, w});  // because Prim works on undirected graph 
    } 
 
    int mst_weight = prim(n, graph); 
 
    cout << "Minimum Spanning Tree Weight = " << mst_weight << endl; 

 
    return 0; 
} 
