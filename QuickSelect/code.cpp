#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &nums,int start,int end){
    int i = start-1;
    int pivot = nums[end];
    for (int j=start; j<end;j++){
        if (nums[j] <= pivot){
            i++;
            swap(nums[i],nums[j]);
        }
    }
    swap(nums[i+1], nums[end]);
    return i+1;
}

void quickSelect(vector<int> &nums,int start,int end,int &ans,int requiredIndex){
    if (start <= end){
        int pIndex = partition(nums, start, end);
        if (pIndex == requiredIndex){
            ans = nums[pIndex];
            return;
        }else if (pIndex < requiredIndex){
            quickSelect(nums, pIndex+1, end, ans, requiredIndex);
        }else{
            quickSelect(nums, start, pIndex-1, ans, requiredIndex);
        }
    }
}

int main(){
    vector<int> nums = {1,9,2,8,3,7,4,6,5};
    int n = (int)nums.size();
    int ans = -1;
    int k = 5;  // kth largest element
    int requiredIndex = n-k;
    quickSelect(nums,0,n-1,ans,requiredIndex);
    if (ans == -1){
        cout << "k out of bounds\n";
    }else{
        cout << k << "th largest element: " << ans << "\n";
    }
    
}
