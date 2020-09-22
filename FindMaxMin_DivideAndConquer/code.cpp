#include <bits/stdc++.h>
using namespace std;

pair<int,int> D_C(int i,int j,vector<int> &nums) {
    
    if (i == j) {
        return {nums[i],nums[i]};
    }
    if (abs(i-j) == 1) {
        if (nums[i] > nums[j]) {
            return {nums[i], nums[j]};
        }
        return {nums[j], nums[i]};
    }
    int mid = i + (j-i)/2;
    
    pair<int,int> pleft = D_C(i,mid,nums);
    pair<int,int> pright = D_C(mid+1,j,nums);
    
    int mx = ( pleft.first > pright.first ) ? pleft.first : pright.first;
    int mn = ( pleft.second < pright.second ) ? pleft.second : pright.second;
    
    return {mx,mn};
}

int main() {
    vector<int> nums = {12,8,-5,30,42,-2,0,50,13};
    int n = (int)nums.size();
    
    pair<int,int> res = D_C(0,n-1,nums);
    
    cout << "Max : " << res.first << "\n";
    cout << "Min : " << res.second << "\n";
}
