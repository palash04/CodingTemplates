#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct suffix{
        int index;
        int rank[2];
    };
public:
    
    static int cmp(suffix a, suffix b){
        return (a.rank[0] == b.rank[0]) ? (a.rank[1] < b.rank[1] ? 1 : 0) : (a.rank[0] < b.rank[0] ? 1 : 0);
    }
    
    vector<int> buildSuffixArray(string s,int n){
        suffix suffixes[n];
        for (int i=0;i<n;i++){
            suffixes[i].index = i;
            suffixes[i].rank[0] = s[i] - '0';
            suffixes[i].rank[1] = (i+1 < n) ? (s[i+1] - '0') : -1;
        }
        
        sort (suffixes, suffixes+n, cmp);
        int ind[n];
        for (int k=4;k<2*n;k*=2){
            int rank=0;
            int prev_rank = suffixes[0].rank[0];
            suffixes[0].rank[0] = rank;
            ind[suffixes[0].index] = 0;
            
            for (int i=1;i<n;i++){
                if (suffixes[i].rank[0] == prev_rank && suffixes[i].rank[1] == suffixes[i-1].rank[1]){
                    prev_rank = suffixes[i].rank[0];
                    suffixes[i].rank[0] = rank;
                }else{
                    prev_rank = suffixes[i].rank[0];
                    suffixes[i].rank[0] = ++rank;
                }
                ind[suffixes[i].index] = i;
            }
            
            for (int i=0;i<n;i++){
                int nextIndex = suffixes[i].index + k/2;
                suffixes[i].rank[1] = (nextIndex < n) ? (suffixes[ind[nextIndex]].rank[0]) : -1;
            }
            sort(suffixes, suffixes+n, cmp);
        }
        
        vector<int> res;
        for (int i=0;i<n;i++){
            res.push_back(suffixes[i].index);
        }
        return res;
    }
    
    
    void lastSubstring(string s) {
        int n = (int)s.size();
        vector<int> res = buildSuffixArray(s, n);
        for (int i=0;i<n;i++){
            cout << res[i] << "\n";
        }
    }
};


int main(){
    Solution s;
    string str;
    cin>>str;
    s.lastSubstring(str);
    return 0;
}
