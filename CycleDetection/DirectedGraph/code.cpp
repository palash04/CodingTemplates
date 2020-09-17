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
    
    // Recursive
    bool dfs(int u, vector<bool> &visited, vector<bool> &recVisited) {
        
        if (!visited[u]) {
            visited[u] = true;
            recVisited[u] = true;
        }
        
        for (auto v : adj[u]) {
            if (recVisited[v]) {
                
                return true;
            }
            
            if (!visited[v]) {
                if (dfs(v, visited, recVisited)) {
                    return true;
                }
            }
        }
        
        recVisited[u] = false;
        return false;
    }
    
    // Iterative
    bool isCycleUtil(int u,vector<bool> &visited,vector<bool> &recVisited){
        stack<int> st;
        st.push(u);
        
        while (!st.empty()){
            
            u = st.top();
            
            if (!visited[u]){
                visited[u] = true;
                recVisited[u] = true;
            }
            
            bool isAnyChildrenNotVisited = false;
            for (auto v=adj[u].begin(); v!=adj[u].end(); v++){
                if (recVisited[*v]){
                    return true;
                }
                if (!visited[*v]){
                    st.push(*v);
                    isAnyChildrenNotVisited = true;
                    break;
                }
            }
            if (!isAnyChildrenNotVisited){
                recVisited[u] = false;
                st.pop();
            }
        }
        return false;
    }
    
    bool isCycle(){
        vector<bool> visited(V);
        vector<bool> recVisited(V);
        
        for (int i=0;i<V;i++){
            if (!visited[i]){
                if (isCycleUtil(i,visited,recVisited)){
                    return true;
                }
            }
        }
        return false;
    }
    
};

int main(){
    Graph g(12);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 5);
    g.addEdge(2, 4);
    g.addEdge(4, 11);
    g.addEdge(5, 8);
    g.addEdge(3, 7);
    g.addEdge(3, 6);
    g.addEdge(8, 10);
    g.addEdge(8, 9);
    g.addEdge(9, 10);
    g.addEdge(11, 2);   // cycle exists for this edge
    
    
    cout << g.isCycle() << "\n";
    
}
