#include <bits/stdc++.h>
using namespace std;

vector<int> t;

void buildTree(vector<int> &nums, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = nums[tl];
        return;
    }

    int tm = tl + ((tr - tl) >> 1);

    buildTree(nums, v * 2, tl, tm);
    buildTree(nums, v * 2 + 1, tm + 1, tr);

    t[v] = max(t[v*2] , t[v*2 + 1]);
}

int range(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return 0;
    }

    if (tl == l and tr == r) {
        return t[v];
    }

    int tm = tl + ((tr - tl) >> 1);

    return max(range(v*2, tl, tm, l, min(r, tm)) , range(v*2 + 1, tm+1, tr, max(l, tm+1), r));

}

void update(int v, int tl, int tr, int pos, int new_value) {
    if (tl == tr) {
        t[v] = new_value;
        return;
    }

    int tm = tl + ( (tr - tl) >> 1);

    if (pos <= tm) {
        update(v*2, tl, tm, pos, new_value);
    } else {
        update(v*2+1, tm+1, tr, pos, new_value);
    }

    t[v] = max(t[v*2] , t[v*2+1]);

}


int32_t main(){
    int n = 6;
    t.resize(4*n);

    vector<int> nums = {1,2,3,4,5,6};

    buildTree(nums, 1, 0, n-1);

    cout << range(1, 0, n-1, 0, n-1) << "\n";
    cout << range(1, 0, n-1, 0, 3) << "\n";
    cout << range(1, 0, n-1, 1, 4) << "\n";
    cout << range(1, 0, n-1, 1, 3) << "\n";

    update(1, 0, n-1, 0, 20);

    cout << range(1, 0, n-1, 0, n-1) << "\n";
    cout << range(1, 0, n-1, 0, 3) << "\n";
    cout << range(1, 0, n-1, 1, 4) << "\n";
    cout << range(1, 0, n-1, 1, 3) << "\n";

}
