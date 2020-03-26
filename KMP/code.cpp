#include <bits/stdc++.h>
using namespace std;

void createLPS(vector<int> &lps,string pat,int n){
    if (n>=1) lps[0] = -1;
    for (int i=1;i<n;i++){
        if (pat[lps[i-1]+1] == pat[i]){
            lps[i] = lps[i-1]+1;
        }else{
            lps[i] = -1;
        }
    }
}

int searchPattern(const vector<int> &lps,string txt,string pat,int m,int n){
    int i = 0;
    int j = -1;
    
    while (j!=n-1 && i<m){
        
        if (pat[j+1] == txt[i]){
            i++;
            j++;
        }else{
            j = lps[j];
            if (j == -1 && pat[j+1] != txt[i]){
                i++;
            }
        }
    }
    if (j == n-1){
        return i-n;   // returns first occurrence of the pattern in the given txt
    }
    return -1;
}

int main(){
    
    string txt = "ABABDABACDABABCABAB";
    string pat = "ABABC";
    int npat = (int)pat.size();
    int ntxt = (int)txt.size();
    vector<int> lps(npat);
    createLPS(lps,pat,npat);
    
    int patIndex = searchPattern(lps,txt,pat,ntxt,npat);
    if (patIndex == -1){
        cout << "Pattern not found\n";
    }else{
        cout << "Pattern found at index: " << patIndex << "\n";
    }
}
