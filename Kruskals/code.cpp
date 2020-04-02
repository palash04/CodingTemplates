#include <bits/stdc++.h>
using namespace std;

#define edge pair<int,int>

class Graph{
    int V;
    vector<pair<int, edge>> G;  // graph
    vector<pair<int, edge>> T;  // mst
    vector<int> parent;
public:
    
    Graph(int V){
        this->V = V;
        parent.resize(V,-1);
    }
    
    void addEdge(int u,int v,int wt){
        G.push_back(make_pair(wt, make_pair(u, v)));
        G.push_back(make_pair(wt, make_pair(v, u)));
    }
    
    int root(int i){
        while (parent[i] > -1) i = parent[-1];
        return i;
    }
    
    int isConnected(int u,int v){
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
    
    void kruskal(){
        sort(G.begin(),G.end());
        int edges = V-1;
        for (int i=0;i<G.size();i++){
            int u = G[i].second.first;
            int v = G[i].second.second;
            
            if (!isConnected(u, v)){
                unite(u, v);
                edges--;
                T.push_back(G[i]);
            }
            if (edges == 0){
                break;
            }
        }
    }
    
    void printMST(){
        int cost = 0;
        cout << "Edges included : \n";
        for (int i=0;i<T.size();i++){
            cout << T[i].second.first << " - " << T[i].second.second << " : " << T[i].first << "\n";
            cost += T[i].first;
        }
        cout << "Minimum Cost : " << cost << "\n";
    }
    
};

int main(){
    
    Graph g(6);
    g.addEdge(0, 2, 4);
    g.addEdge(0, 1, 4);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 3);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(4, 3, 3);
    g.addEdge(4, 5, 3);
        
    g.kruskal();
    g.printMST();
}
