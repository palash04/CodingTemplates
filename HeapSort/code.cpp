#include <bits/stdc++.h>
using namespace std;


void printNums(vector<int> &nums){
    for (auto num : nums){
        cout << num << " ";
    }
    cout << "\n";
}

void maxHeapify(vector<int> &nums,int i,int n){
    int l = 2*i + 1;
    int r = 2*i + 2;
    int largest = i;
    
    if (l < n && nums[l] > nums[largest]){
        largest = l;
    }
    if (r < n && nums[r] > nums[largest]){
        largest = r;
    }
    if (largest != i){
        swap(nums[i], nums[largest]);
        maxHeapify(nums, largest, n);
    }
}

void buildMaxHeap(vector<int> &nums,int n){
    for (int i=n/2-1;i>=0;i--){
        maxHeapify(nums, i, n);
    }
}

void heapSortAscending(vector<int> &nums,int n){
    buildMaxHeap(nums,n);
    for (int i=n-1;i>=0;i--){
        swap(nums[0], nums[i]);
        maxHeapify(nums, 0, i);
    }
}

void minHeapify(vector<int> &nums,int i,int n){
    int l = 2*i + 1;
    int r = 2*i + 2;
    int smallest = i;
    
    if (l < n && nums[l] < nums[smallest]){
        smallest = l;
    }
    if (r < n && nums[r] < nums[smallest]){
        smallest = r;
    }
    if (smallest != i){
        swap(nums[i],nums[smallest]);
        minHeapify(nums, smallest, n);
    }
}

void buildMinHeap(vector<int> &nums,int n){
    for (int i=n/2-1;i>=0;i--){
        minHeapify(nums, i, n);
    }
}

void heapSortDescending(vector<int> &nums,int n){
    buildMinHeap(nums, n);
    for (int i=n-1;i>=0;i--){
        swap(nums[0], nums[i]);
        minHeapify(nums, 0, i);
    }
}

int main(){
    vector<int> nums = {4,2,1,7,9,8,3,6,0,5};
    int n = (int)nums.size();
    heapSortAscending(nums, n);
    printNums(nums);
    heapSortDescending(nums, n);
    printNums(nums);
}
