#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    vector<vector<int>> adj;
    vector<int> indegree;
public:
    Graph(int V){
        this->V = V;
        adj.resize(V);
        indegree.resize(V,0);
    }
    
    void addEdge(int u,int v){
        indegree[v]++;
        adj[u].push_back(v);
    }
    
    bool isCycleUtil(int u, vector<bool> &visited, vector<bool> &recVisited){
        
        stack<int> st;
        st.push(u);
        
        while (!st.empty()){
            u = st.top();
            
            if (!visited[u]){
                visited[u] = true;
                recVisited[u] = true;
            }
            
            bool isAnyChildrenNotVisited = false;
            for (auto v = adj[u].begin(); v!=adj[u].end(); v++){
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
                st.pop();
                recVisited[u] = false;
            }
        }
        return false;
    }
    
    bool isCycle(){
        vector<bool> visited(V,false);
        vector<bool> recVisited(V,false);
        
        for (int i=0;i<V;i++){
            if (!visited[i]){
                if (isCycleUtil(i,visited,recVisited)){
                    return true;
                }
            }
        }
        return false;
    }
    
    void topoOrdering(vector<int> &res){
        
        vector<int> v;
        for (int i=0;i<V;i++){
            if (indegree[i] == 0) v.push_back(i);
        }
        
        queue<int> q;
        for (int i=0;i<v.size();i++){
            q.push(v[i]);
        }
        
        while (!q.empty()){
            int u = q.front();
            q.pop();
            res.push_back(u);
            
            for (auto v=adj[u].begin(); v!= adj[u].end(); v++){
                indegree[*v]--;
                if (indegree[*v] == 0){
                    q.push(*v);
                }
            }
        }
    }
    
};

int main(){
    
    Graph g(10);
    
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(0, 4);
    g.addEdge(7, 3);
    g.addEdge(7, 5);
    g.addEdge(1, 2);
    g.addEdge(3, 2);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(4, 6);
    
    if (g.isCycle()){
        cout << "Cycle exists. Topological ordering not possible\n";
    }else{
        // find topological ordering
        vector<int> res;
        g.topoOrdering(res);
        
        for (int i=0;i<res.size();i++){
            cout << res[i] << " ";
        }
        cout << "\n";
    }
    
}
