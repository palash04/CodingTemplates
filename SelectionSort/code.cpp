#include <bits/stdc++.h>
using namespace std;

// Best,Avg,Worst :  O(n^2),O(n^2),O(n^2)
void selectionSort(vector<int> &nums,int n){
    for (int i=0;i<n;i++){
        int minId = i;
        for (int j=i+1;j<n;j++){
            if (nums[j] < nums[minId]){
                minId = j;
            }
        }
        swap(nums[i],nums[minId]);
    }
}

void printNums(vector<int> &nums){
    for (auto num : nums){
        cout << num << " ";
    }
    cout << "\n";
}

int main(){
    vector<int> nums = {9,6,3,6,1,9,5,7,4,33};
    int n = (int)nums.size();
    selectionSort(nums,n);
    printNums(nums);
}
