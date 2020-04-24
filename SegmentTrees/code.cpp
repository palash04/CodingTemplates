#include <bits/stdc++.h>
using namespace std;

vector<int> tree;
vector<int> arr;

int buildSegTree(int start,int end,int index){
    
    if (start == end){
        tree[index] = arr[start];
        return tree[index];
    }
    
    int mid = start + (end-start)/2;
    tree[index] = buildSegTree(start, mid, 2*index) + buildSegTree(mid+1, end, 2*index+1);
    return tree[index];
}

int rangeQ(int start,int end,int i,int j,int index){
    if (start>=i && end<=j){    // in the range
        return tree[index];
    }
    if (start>j || end<i){      // out of range
        return 0;
    }
    // else overlaping
    int mid = start + (end-start)/2;
    return rangeQ(start, mid, i, j, 2*index) + rangeQ(mid+1, end, i, j, 2*index+1);
}

void updateRQ(int expectedIndex, int diff, int start, int end, int index){
    
    if (expectedIndex>=start && expectedIndex<=end){
        tree[index] += diff;
    }
    if (start == end){
        return;
    }
    
    int mid = start + (end-start)/2;
    if (expectedIndex > mid){
        updateRQ(expectedIndex, diff, mid+1, end, 2*index+1);
    }else{
        updateRQ(expectedIndex, diff, start, mid, 2*index);
    }
    
}

void updateQ(int i,int val, int start, int end){
    int diff = val - arr[i];
    arr[i] = val;
    updateRQ(i,diff,start,end,1);
}

int main(){
    int n =10;
    arr.resize(n);
    tree.resize(4*n);
    
    arr = {1,2,3,4,5,6,7,8,9,10};
    buildSegTree(0,n-1,1);
    
    int i = 3;
    int j = 7;
    cout << rangeQ(0, 9, i, j, 1) << "\n";
    
    updateQ(4, 10, 0, n-1);
    
    i = 3;
    j = 7;
    cout << rangeQ(0, 9, i, j, 1) << "\n";
    
}
