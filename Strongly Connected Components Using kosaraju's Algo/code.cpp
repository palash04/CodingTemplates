#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<vector<int>> radj;
int V;
stack<int> st;
vector<bool> visited;
vector<bool> rvisited;

void dfs(int u){
    visited[u] = true;

    for (auto v=adj[u].begin();v!=adj[u].end();v++){
        if (!visited[*v]){
            dfs(*v);
        }
    }
    st.push(u);
}

void dfs2(int u){
    rvisited[u] = true;
    cout << u << " ";   // printing all vertices in this particular component
    for (auto v=radj[u].begin(); v!=radj[u].end(); v++){
        if (!rvisited[*v]){
            dfs2(*v);
        }
    }
}

void kosaraju(vector<pair<int, int>> &edges){
    for (pair<int,int> edge : edges ){
        adj[edge.first].push_back(edge.second);
    }
    for (pair<int,int> edge : edges ){
        radj[edge.second].push_back(edge.first);
    }

    for (int i=0;i<V;i++){
        if (!visited[i]){
            dfs(i);
        }
    }
    int component = 0;
    while (!st.empty()){
        int u = st.top();
        st.pop();

        if (!rvisited[u]){
            component++;
            cout << "Component " << component << " :: ";
            dfs2(u);
            cout << "\n";
        }
    }
}


int main(){
    V = 13;
    adj.resize(V);
    radj.resize(V);
    visited.resize(V,false);
    rvisited.resize(V,false);

    vector<pair<int,int>> edges;
    edges.push_back({1,2});
    edges.push_back({2,3});
    edges.push_back({3,4});
    edges.push_back({4,1});
    edges.push_back({3,8});
    edges.push_back({5,4});
    edges.push_back({2,6});
    edges.push_back({6,7});
    edges.push_back({7,8});
    edges.push_back({9,7});
    edges.push_back({8,6});
    edges.push_back({9,10});
    edges.push_back({10,9});
    edges.push_back({8,11});
    edges.push_back({11,0});
    edges.push_back({0,12});
    edges.push_back({12,11});

    kosaraju(edges);

}
