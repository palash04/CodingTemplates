/*
https://practice.geeksforgeeks.org/problems/lcm-and-gcd/0
*/

#include <bits/stdc++.h>
using namespace std;

/* macros */
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define vi vector<int>
#define vt vector
#define pb push_back
#define fi first
#define se second
#define pi pair<int,int>
#define tc int t;cin>>t;while (t--){solve();}
#define notc solve();
#define newline cout << "\n";
#define mod 1000000007
#define ret return 0;
#define sz(x) (int)x.size();
#define rep(i,a,b) for(int i=a;i<b;i++)
#define srt(x) sort(x.begin(), x.end())

int gcd(int a,int b){
    if (b == 0){
        return a;
    }
    return gcd(b, a%b);
}

void solve(){
    int a,b;
    cin>>a>>b;
    int gc_d = gcd(a,b);
    int lcm = (b*a) / gc_d;
    cout << lcm << " " << gc_d << "\n";
}

int32_t main(){
    fastio
    tc
    ret
}
