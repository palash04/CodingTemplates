#include <bits/stdc++.h>
using namespace std;
#define ipair pair<int,int>
#define INF INT_MAX

int V;
vector<vector<ipair>> adj;

/*
addEdge(0,1,10);
addEdge(0,2,20);
addEdge(1,2,15);
addEdge(2,3,5);

[0] -> {1,10},{2,20}
[1] -> {2,15}
[2] -> {3,5}
*/
void addEdge(int u,int v,int wt){
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt)); // comment this line for directed graph
}


// Time Comp: Adjacency List + priority_queue => O((E+V)logV) ~ O(ElogV) since E is much much greater than V
void shortestPath(int src){
    priority_queue<ipair, vector<ipair>, greater<>> pq;
    vector<int> dist(V,INF);
    
    pq.push(make_pair(0, src));
    dist[src] = 0;
    
    while (!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        
        for (auto node : adj[u]){
            int v = node.first;
            int u_v_weight = node.second;
            
            if (dist[v] > dist[u] + u_v_weight){
                dist[v] = dist[u] + u_v_weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    cout << "Shortest path from \n";
    for (int i=0;i<V;i++){
        cout << src << " to " << i << " -> " << dist[i] << "\n";
    }
    
}

int main(){
    V = 9;
    adj.resize(V);
    addEdge(0, 1, 4);
    addEdge(0, 7, 8);
    addEdge(1, 2, 8);
    addEdge(1, 7, 11);
    addEdge(2, 3, 7);
    addEdge(2, 8, 2);
    addEdge(2, 5, 4);
    addEdge(3, 4, 9);
    addEdge(3, 5, 14);
    addEdge(4, 5, 10);
    addEdge(5, 6, 2);
    addEdge(6, 7, 1);
    addEdge(6, 8, 6);
    addEdge(7, 8, 7);
    
    int sourceVertex = 0;
    shortestPath(sourceVertex);
    
    return 0;
}
