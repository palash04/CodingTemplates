#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    vector<vector<int>> adj;
public:
    Graph(int V){
        this->V = V;
        adj.resize(V);
    }
    
    void addEdge(int u,int v){
        adj[u].push_back(v);
    }
    
    void bfs(int s){
        vector<bool> visited(V,false);
        
        queue<int> q;
        q.push(s);
        visited[s] = true;
        while (!q.empty()){
            int u = q.front();
            cout << u << " ";
            q.pop();
            
            for (auto v=adj[u].begin(); v!=adj[u].end(); v++){
                if (!visited[*v]){
                    visited[*v] = true;
                    q.push(*v);
                }
            }
        }
    }
};

int main(){
    Graph g(12);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 6);
    g.addEdge(3, 5);
    g.addEdge(2, 4);
    g.addEdge(4, 8);
    g.addEdge(4, 10);
    g.addEdge(4, 7);
    g.addEdge(7, 9);
    g.addEdge(10, 11);
    g.addEdge(10, 2);
    
    g.bfs(0);
    cout << "\n";
}
