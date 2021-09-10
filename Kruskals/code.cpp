/*

Time complexity: O(ElogE)

*/


#include <bits/stdc++.h>
using namespace std;

#define edge pair<int,int>

class Graph{
    int V;
    vector<pair<int, edge>> G;
    vector<pair<int, edge>> T;
    vector<int> id,sz;
public:
    Graph(int V) {
        this->V = V;
        G.clear();
        T.clear();
        id.resize(V);
        sz.resize(V, 1);
        for (int i=0;i<V;i++) {
            id[i] = i;
        }

    }

    void addEdge(int u, int v, int wt) {
        G.push_back({wt, {u,v}});
        G.push_back({wt, {v,u}});
    }

    int root (int i) {
        while (id[i] != i) {
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
    }

    void unite(int u, int v) {
        int p = root(u);
        int q = root(v);

        if (sz[p] >= sz[q]) {
            id[q] = p;
            sz[p] += sz[q];
        } else {
            id[p] = q;
            sz[q] += sz[p];
        }
    }

    bool connected(int u, int v) {
        return root(u) == root(v);
    }

    void kruskal() {
        sort(G.begin(), G.end());
        int count = 0;
        for (int i=0;i<G.size();i++) {
            int u = G[i].second.first;
            int v = G[i].second.second;

            if (!connected(u,v)) {
                unite(u,v);
                T.push_back(G[i]);
                count++;
            }

            if (count == V-1) {
                break;
            }
        }
    }

    void print() {
        for (int i=0;i<T.size();i++) {
            cout << T[i].second.first << ", " << T[i].second.second << " :: " << T[i].first << "\n";
        }
    }

};

int main() {
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
    g.print();
}
