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
    
    void dfsRecursiveUtil(int u,vector<bool> &visited){
        visited[u] = true;
        cout << u << " ";
        for (auto v = adj[u].begin(); v!= adj[u].end(); v++){
            if (!visited[*v]){
                dfsRecursiveUtil(*v, visited);
            }
        }
    }
    
    void dfsRecursive(){
        vector<bool> visited(V,false);
        for (int i=0;i<V;i++){
            if (!visited[i]){
                dfsRecursiveUtil(i,visited);
            }
        }
    }
    
    void dfsIterativeUtil(int u,vector<bool> &visited){
        stack<int> st;
        st.push(u);
        
        while (!st.empty()) {
            u = st.top();
            st.pop();
            
            if (!visited[u]){
                visited[u] = true;
                cout << u << " ";
            }
            
            for (auto v=adj[u].begin(); v!=adj[u].end(); v++){
                if (!visited[*v]){
                    st.push(*v);
                }
            }
        }
    }
    
    void dfsIterative(){
        vector<bool> visited(V,false);
        for (int i=0;i<V;i++){
            if (!visited[i]){
                dfsIterativeUtil(i,visited);
            }
        }
    }
    
};

int main(){
    
    Graph g(12);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(4, 7);
    g.addEdge(4, 8);
    g.addEdge(3, 6);
    g.addEdge(3, 5);
    g.addEdge(7, 9);
    g.addEdge(4, 10);
    g.addEdge(10, 2);
    g.addEdge(10, 11);
    
    cout << "Recursive dfs output: ";
    g.dfsRecursive();
    cout << "\nIterative dfs output: ";
    g.dfsIterative();
    cout << "\n";
}
