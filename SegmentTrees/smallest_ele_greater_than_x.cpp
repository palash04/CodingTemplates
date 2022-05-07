#include <bits/stdc++.h>
#define MAXN 100
#define INF 999
using namespace std;

vector<int> t[4*MAXN];

void build (int v, int tl, int tr, vector<int> &nums) {
    if (tl == tr) {
        t[v] = vector<int> (1, nums[tl]);
        return;
    }

    int tm = tl + ( (tr - tl) >> 1);

    build(v*2, tl, tm, nums);
    build(v*2, tm+1, tr, nums);

    merge(t[v*2].begin(), t[v*2].end(), t[v*2+1].begin(), t[v*2+1].end(), back_inserter(t[v]));

}

int query(int v, int tl, int tr, int l, int r, int x) {
    if (l > r) {
        return INF;
    }

    if (tl == l and tr == r) {
        vector<int>::iterator pos = lower_bound(t[v].begin(), t[v].end(), x);
        if (pos != t[v].end()) {
            return *pos;
        }
        return INF;
    }

    int tm = tl + ( (tr-tl) >> 1);

    return min(query(v*2, tl, tm, l, min(r, tm), x),
               query(v*2, tm+1, r, max(l, tm+1), r, x));

}


int32_t main(){

    vector<int> nums = {1,2,4,5,6,2,3,8,10,12,7,6};
    int n = (int)nums.size();
    build(1, 0, n-1, nums);

    int l = 0;
    int r = n-1;
    int x = 4;
    cout << query(1, 0, n-1, 4,8, x) << "\n";

}
