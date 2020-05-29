#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> &nums){
    for (auto num : nums){
        cout << num << " ";
    }
    cout << "\n";
}

void insertionSort(vector<int> &nums,int n){
    for (int i=1;i<n;i++){
        int key = nums[i];
        int j = i-1;
        while (j >= 0 && nums[j] > key){
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = key;
    }
}


int main(){
    vector<int> nums = {10,9,8,7,6,5,4,3,2,1};
    int n = (int)nums.size();
    //printArray(nums);
    insertionSort(nums,n);
    printArray(nums);
}
