/*
Weighted Quick Union + Path Compression
*/

#include <bits/stdc++.h>
using namespace std;

class WQUPC{
    vector<int> id,sz;
public:
    WQUPC(int n){
        id.resize(n);
        sz.resize(n,1);
        for (int i=0;i<n;i++){
            id[i] = i;
        }
    }
    
    int root(int i){
        while (id[i] != i){
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
    }
    
    bool connected(int i,int j){
        return root(i) == root(j);
    }
    
    bool unite(int i,int j){
        int pi = root(i);
        int pj = root(j);
        if (pi == pj) return false;
        if (sz[pi] > sz[pj]){
            id[pj] = id[pi];
            sz[pi] += sz[pj];
        }else{
            id[pi] = id[pj];
            sz[pj] += sz[pi];
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> res;
        int n = (int)edges.size();
        if (n == 0) return res;
        WQUPC q(n);
        for (auto edge : edges){
            if (!q.unite(edge[0], edge[1])){
                res.clear();
                res.push_back(edge[0]);
                res.push_back(edge[1]);
            }
        }
        return res;
    }
};

int main(){
    WQUPC w(5); // 5 vertices - 0,1,2,3,4
    cout << w.connected(3, 4) << "\n";
    w.unite(3, 4);
    cout << w.connected(3, 4) << "\n";
    w.unite(0, 1);
    w.unite(1, 2);
    w.unite(0, 2);
    cout << w.connected(2, 3) << "\n";
    w.unite(3, 2);
    cout << w.connected(2, 3) << "\n";
}
