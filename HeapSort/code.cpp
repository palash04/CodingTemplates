#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &nums,int i,int n){
    int l = 2*i + 1;
    int r = 2*i + 2;
    int largest = i;
    if (l < n && nums[l] > nums[largest]){
        largest = l;
    }
    if(r < n && nums[r] > nums[largest]){
        largest = r;
    }
    
    if (largest != i){
        swap(nums[i],nums[largest]);
        heapify(nums, largest, n);
    }
}

void heapSort(vector<int> &nums,int n){
    // build maxHeap
    for (int i=n/2-1; i>=0; i--){
        heapify(nums, i, n);
    }
    
    for (int i=n-1;i>=0;i--){
        swap(nums[0], nums[i]);
        heapify(nums, 0, i);
    }
    
}


int main(){
    vector<int> nums = {15,14,13,12,11,10,9,8,7,6,5,4,3};
    int n = (int)nums.size();
    heapSort(nums,n);
    
    for (int i=0;i<n;i++){
        cout << nums[i] << " ";
    }
    
    cout << "\n";
    
}
