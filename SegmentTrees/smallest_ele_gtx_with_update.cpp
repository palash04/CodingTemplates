#include <bits/stdc++.h>
#define MAXN 100
#define INF 999
using namespace std;

multiset<int> t[4*MAXN];

void build (int v, int tl, int tr, vector<int> &nums) {
    if (tl == tr) {
        t[v].insert(nums[tl]);
        return;
    }

    int tm = tl + ( (tr - tl) >> 1);

    build(v*2, tl, tm, nums);
    build(v*2+1, tm+1, tr, nums);

    merge(t[v*2].begin(), t[v*2].end(), t[v*2+1].begin(), t[v*2+1].end(), inserter(t[v], t[v].begin()));
}

int query(int v, int tl, int tr, int l, int r, int x) {
    if (l > r) {
        return INF;
    }

    if (tl == l and tr == r) {
        auto pos = t[v].lower_bound(x);
        if (pos != t[v].end()) {
            return *pos;
        }
        return INF;
    }

    int tm = tl + ( (tr-tl) >> 1);

    return min(query(v*2, tl, tm, l, min(r, tm), x),
               query(v*2+1, tm+1, tr, max(l, tm+1), r, x));

}

void update(int v, int tl, int tr, int pos, int new_val, vector<int> &nums) {
    if (t[v].find(nums[pos]) != t[v].end()) {
        t[v].erase(t[v].find(nums[pos]));
        t[v].insert(new_val);
    }

    if (tl == tr) {
        nums[pos] = new_val;
        return;
    }

    int tm = tl + ( (tr - tl) >> 1);
    if (pos <= tm) {
        update(v*2, tl, tm, pos, new_val, nums);
    } else {
        update(v*2+1, tm+1, tr, pos, new_val, nums);
    }

}


int32_t main(){

    vector<int> nums = {1,4,5,7,8,9,10};
    int n = (int)nums.size();
    build(1, 0, n-1, nums);

    int l = 2;
    int r = n-1;
    int x = 3;
    cout << query(1, 0, n-1, l, r, x) << "\n";
    update(1, 0, n-1, 2, 12, nums);
    cout << query(1, 0, n-1, l,r, x) << "\n";

}
