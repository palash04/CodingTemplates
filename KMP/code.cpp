#include <bits/stdc++.h>
using namespace std;

void createLPS(vector<int> &lps, string pat, int n) {
    lps[0] = 0;
    int len = 0;
    int i = 1;
    while (i < n) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }else {
            if (len) {
                len = lps[len-1];
            }else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int searchPattern(vector<int> &lps, string t, string p, int m, int n) {
    int i = 0;
    int j = 0;

    while (i < m) {
        if (t[i] == p[j]) {
            i++;
            j++;
        }else {
            if (j) {
                j = lps[j-1];
            }else {
                i++;
            }
        }

        if (j == n) {
            cout << i-j << "\n";
            j = lps[j-1];
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

    searchPattern(lps, txt, pat, m, n);

}
