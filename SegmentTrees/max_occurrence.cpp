#include <bits/stdc++.h>
#define MAXN 100
using namespace std;

pair<int,int> t[4*MAXN];

pair<int,int> combine(pair<int,int> a, pair<int,int> b) {
    if (a.first > b.first)
        return a;
    if (b.first > a.first) {
        return b;
    }

    return {a.first, a.second + b.second};
}

void buildTree(vector<int> &nums, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = {nums[tl], 1};
        return;
    }

    int tm = tl + ((tr - tl) >> 1);

    buildTree(nums, v * 2, tl, tm);
    buildTree(nums, v * 2 + 1, tm + 1, tr);

    t[v] = combine(t[v*2], t[v*2+1]);
}

pair<int,int> get_max(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return {-INFINITY, 0};
    }

    if (tl == l and tr == r) {
        return t[v];
    }

    int tm = tl + ((tr - tl) >> 1);

    return combine (
            get_max (v*2, tl, tm, l, min(r,tm)),
            get_max (v*2+1, tm+1, tr, max(l,tm+1), r)
    );

}

void update(int v, int tl, int tr, int pos, int new_value) {
    if (tl == tr) {
        t[v] = {new_value, 1};
        return;
    }

    int tm = tl + ( (tr - tl) >> 1);

    if (pos <= tm) {
        update(v*2, tl, tm, pos, new_value);
    } else {
        update(v*2+1, tm+1, tr, pos, new_value);
    }

    t[v] = combine(t[v*2], t[v*2+1]);

}


int32_t main(){
    int n = 6;

    vector<int> nums = {2,2,3,4,5,5};

    buildTree(nums, 1, 0, n-1);

    pair<int,int> p = get_max(1, 0, n-1, 0, n-1);
    cout << p.first << " " << p.second << "\n";
    p = get_max(1, 0, n-1, 0, 3);
    cout << p.first << " " << p.second << "\n";
    p = get_max(1, 0, n-1, 1, 4);
    cout << p.first << " " << p.second << "\n";
    p = get_max(1, 0, n-1, 1, 3);
    cout << p.first << " " << p.second << "\n";

    update(1, 0, n-1, 0, 20);

    p = get_max(1, 0, n-1, 0, n-1);
    cout << p.first << " " << p.second << "\n";
    p = get_max(1, 0, n-1, 0, 3);
    cout << p.first << " " << p.second << "\n";
    p = get_max(1, 0, n-1, 1, 4);
    cout << p.first << " " << p.second << "\n";
    p = get_max(1, 0, n-1, 1, 3);
    cout << p.first << " " << p.second << "\n";

}
