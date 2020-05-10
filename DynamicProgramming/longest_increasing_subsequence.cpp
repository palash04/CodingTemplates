#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int> nums){
    int n = (int)nums.size();
    vector<int> dp(n,1);
    int i=0,maxLength=INT_MIN;
    for (int j=1;j<n;j++){
        i = 0;
        while (i != j){
            if (nums[j] > nums[i]){
                dp[j] = max(dp[j], dp[i]+1);
                if (dp[j] > maxLength) maxLength = dp[j];
            }
            i++;
        }
    }
    return maxLength;
}


int main(){
    vector<int> nums = {10, 22, 9, 33, 21, 50, 41, 60};
    cout << lengthOfLIS(nums) << "\n";
}
