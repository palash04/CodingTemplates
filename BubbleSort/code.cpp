#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &nums,int n){
    for (int i=n-1;i>=1;i--){
        for (int j=0;j<=i-1;j++){
            if (nums[j] > nums[j+1]){
                swap(nums[j], nums[j+1]);
            }
        }
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
    bubbleSort(nums,n);
    printNums(nums);
}
