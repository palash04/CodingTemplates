#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &nums, int start,int end){
    int pivot = nums[end];
    int i = start-1;
    for (int j=start;j<end;j++){
        if (nums[j] <= pivot){
            i++;
            swap(nums[i],nums[j]);
        }
    }
    swap(nums[i+1], nums[end]);
    return i+1;
}

void quickSort(vector<int> &nums, int start,int end){
    if (start < end){
        int pIndex = partition(nums,start,end);
        quickSort(nums, start, pIndex-1);
        quickSort(nums, pIndex, end);
    }
}

int main(){
    vector<int> nums = {-1,-2,-3,-4,-5,0,5,4,3,2,1};
    int n = (int)nums.size();
    
    quickSort(nums,0,n-1);
    
    for (int i=0;i<nums.size();i++){
        cout << nums[i] << " ";
    }
    cout << "\n";
}
