/*
https://www.geeksforgeeks.org/0-1-bfs-shortest-path-binary-graph/
*/

#include <bits/stdc++.h>
using namespace std;

#define inf 1e9

const int V = 9;
vector<pair<int,int>> adj[V];

void addEdge(int u,int v,int wt) {
    adj[u].push_back({v,wt});
    adj[v].push_back({u,wt});
}

void shortest(int src) {
    vector<int> dist(V,inf);
    dist[src] = 0;
    deque<int> q;
    q.push_back(src);
    
    while (!q.empty()) {
        int x = q.front();
        q.pop_front();
        
        for (auto v=adj[x].begin(); v!=adj[x].end(); v++) {
            int y = (*v).first;
            int wt_x_y = (*v).second;
            if (dist[y] > dist[x] + wt_x_y) {
                dist[y] = dist[x] + wt_x_y;
                if (wt_x_y == 0) {
                    q.push_front(y);
                }else {
                    q.push_back(y);
                }
            }
        }
        
    }
    
    for (int i=0;i<V;i++) {
        cout << src << " " << i << " : " << dist[i] << "\n";
    }
}

int main() {
    addEdge(0, 1, 0);
    addEdge(0, 7, 1);
    addEdge(1, 7, 1);
    addEdge(1, 2, 1);
    addEdge(2, 3, 0);
    addEdge(2, 5, 0);
    addEdge(2, 8, 1);
    addEdge(3, 4, 1);
    addEdge(3, 5, 1);
    addEdge(4, 5, 1);
    addEdge(5, 6, 1);
    addEdge(6, 7, 1);
    addEdge(7, 8, 1);
    
    shortest(0);
    
}
