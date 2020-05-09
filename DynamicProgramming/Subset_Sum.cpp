#include <bits/stdc++.h>
using namespace std;

bool isSubsetSum(vector<int> &nums,int sum){
    int m = (int)nums.size();
    int n = sum;
    vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
    
    for (int i=0;i<=m;i++){
        dp[i][0] = true;
    }
    
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++){
            if (nums[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
        }
    }
    return dp[m][n];
}

int main(){
    vector<int> nums = {2,3,4};
    int sum = 9;
    cout << isSubsetSum(nums, sum) << "\n";
}
