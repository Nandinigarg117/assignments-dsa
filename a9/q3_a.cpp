#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std; 
 
struct Edge { 
    int u, v, w; 
}; 
 
vector<int> parent, sz; 
 
// DSU Find 
int find(int x) { 
    if (x == parent[x]) return x; 
    return parent[x] = find(parent[x]); 
} 
 
// DSU Union 
void unite(int a, int b) { 
    a = find(a); 
    b = find(b); 
    if (a != b) { 
        if (sz[a] < sz[b]) swap(a, b); 
        parent[b] = a; 
        sz[a] += sz[b]; 
    } 
} 
 
// Kruskal Algorithm 
int kruskal(int n, vector<Edge>& edges) { 
 
    // 1. Sort edges by weight 
    sort(edges.begin(), edges.end(), 
         [](Edge &a, Edge &b) { return a.w < b.w; }); 
 
    // 2. Initialize DSU 
    parent.resize(n); 
    sz.assign(n, 1); 
 
    for (int i = 0; i < n; i++) 
        parent[i] = i; 
 
    int mst_weight = 0; 
    int count = 0; 
 
    // 3. Process edges 
    for (auto &e : edges) { 
        if (find(e.u) != find(e.v)) {   // no cycle 

            unite(e.u, e.v);            // join them 
            mst_weight += e.w;          // add weight 
            count++; 
 
            if (count == n - 1) break;  // MST complete 
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
 
    vector<Edge> edges(m); 
 
    cout << "Enter edges (u v w): \n"; 
    for (int i = 0; i < m; i++) { 
        cin >> edges[i].u >> edges[i].v >> edges[i].w; 
    } 
 
    int mst_weight = kruskal(n, edges); 
 
    cout << "Minimum Spanning Tree Weight = " << mst_weight << endl; 
 
    return 0; 
}