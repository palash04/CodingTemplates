#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> &values,vector<int> &weights, int capacity){
    
    int m = (int)weights.size();
    int n = capacity;
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++){
            if (weights[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weights[i-1]] + values[i-1]);
            }
        }
    }
    return dp[m][n];
}

int main(){
    vector<int> values = {30,50,60,70};
    vector<int> weights = {2,3,5,4};
    int weight = 5;
    int ans = knapsack(values, weights, weight);
    cout << ans << "\n";
}
