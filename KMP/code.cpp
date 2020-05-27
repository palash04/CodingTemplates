#include <bits/stdc++.h>
using namespace std;

void createLPS(vector<int> &lps,string pat,int n){
    if (n>=1) lps[0] = -1;
    for (int i=1;i<n;i++){
        if (pat[lps[i-1]+1] == pat[i]){
            lps[i] = lps[i-1]+1;
        }else{
            if (pat[i-1] == pat[i]){
                lps[i-1] = lps[i];
            }
            else lps[i] = -1;
        }
    }
}

int searchPattern(const vector<int> &lps,string txt,string pat, int m,int n){
    int i = 0;
    int j = -1;
    
    while (i < m){
        if (pat[j+1] == txt[i]){
            i++;
            j++;
        }else{
            if (j != -1){
                j = lps[j];
            }
            else {
                i++;
            }
        }
        
        // finding all the occurrences of the given pattern.
        if (j == n-1){
            cout << i-n << "\n";
            j = lps[j];
        }
    }
    return -1;
    
}

void printLPS(vector<int> &lps){
    for (auto l : lps){
        cout << l << " ";
    }
    cout << "\n";
}

int main(){
    
    string txt = "AABAABAA";
    string pat = "ABAA";
    
    int m = (int)txt.size();
    int n = (int)pat.size();
    
    vector<int> lps(n);
    createLPS(lps,pat,n);
    printLPS(lps);
    searchPattern(lps, txt, pat, m, n);
    
}
