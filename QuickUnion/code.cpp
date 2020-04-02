#include <bits/stdc++.h>
using namespace std;

class QuickUnion{
    int V;
    vector<int> parent;
public:
    QuickUnion(int V){
        this->V = V;
        parent.resize(V,-1);
    }
    int root(int i){
        while (parent[i] > -1) i = parent[i];
        return i;
    }
    bool find(int u,int v){
        return (root(u) == root(v));
    }
    void unite(int u,int v){
        int p = root(u);
        int q = root(v);
        if (parent[p] <= parent[q]){
            parent[p] += parent[q];
            parent[q] = p;
        }else{
            parent[q] += parent[p];
            parent[p] = q;
        }
    }
};

int main(){
    
    QuickUnion q(10);
    
    // check if vertices 2 and 5 are connected or not
    cout << (q.find(2, 5) ? "Connected\n" : "Not connected\n" );
    
    // join (2,7), (8,9), (9,0), (5,0), (7,9)
    q.unite(2, 7);
    q.unite(8, 9);
    q.unite(9, 0);
    q.unite(5, 0);
    q.unite(7, 9);
    
    // check again for 2 and 5
    cout << (q.find(2, 5) ? "Connected\n" : "Not connected\n" );
    
    // further can be used to check if cycle exists in undirected graph or not
    // graph of 5 vertices
    QuickUnion c(5);
    vector<pair<int,int>> edges = {{0,1},{1,4},{0,3},{1,2},{2,3},{0,2}};
    bool foundCycle = false;
    for (auto edge : edges){
        int u = edge.first;
        int v = edge.second;
        if (c.find(u, v)){
            foundCycle = true;
            break;
        }else{
            c.unite(u, v);
        }
    }
    if (foundCycle){
        cout << "Cycle exists\n";
    }else{
        cout << "Cycle does not exists\n";
    }
}
