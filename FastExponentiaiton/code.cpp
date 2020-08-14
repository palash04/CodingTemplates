#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
#define mod 1000000007

// O(n)
int solve(int a,int n){
    int ans = 1;
    for (int i=1;i<=n;i++){
        ans = (ans%mod * a%mod)%mod;
    }
    return ans;
}

// O(logn)
int power(int a, int n){
    if (n == 0) {
        return 1;
    }
    else if (n == 1){
        return a;
    }
    
    int X = power(a, n/2);
    if (n&1){
        // n is odd
        int y = (X%mod * X%mod)%mod;
        y = ((y%mod * a%mod)%mod);
        return y;
    }else{
        // n is even
        return (X%mod * X%mod)%mod;
    }
}

signed main(){
    int a = 2002;
    int n = 100000000;  // naive approach : 3.8 secs , logn approach : 0.000004 seconds
    
    clock_t start;
    double duration;
    
    cout << "O(n) approach: ";
    start = clock();
    cout << solve(a,n);
    duration = (clock()-start)/(double)CLOCKS_PER_SEC;
    cout << "\t\t Time Taken: " << duration << " seconds" << "\n\n";
    
    cout << "O(logn) approach: ";
    start = clock();
    cout << power(a,n);
    duration = (clock()-start)/(double)CLOCKS_PER_SEC;
    cout << "\t\t Time Taken: " << duration << " seconds" <<  "\n\n";
    
}
