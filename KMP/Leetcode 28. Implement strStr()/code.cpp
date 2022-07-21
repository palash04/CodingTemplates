class Solution {
public:
    
    void computeLPS(string p, int n, vector<int> &lps) {
        
        lps[0] = 0;
        
        for (int i=1;i<n;i++) {
            if (lps[i-1] == 0) {
                if (p[i] == p[0]) {
                    lps[i] = 1;
                } else {
                    lps[i] = 0;
                }
            } else {
                if (p[lps[i-1]] == p[i]) {
                    lps[i] = lps[i-1] + 1;
                } else {
                    
                    if (p[i] == p[i-1] and p[i] == p[0]) lps[i] = lps[i-1];
                    else lps[i] = 0;
                }
            }
        }
    }
    
    int search(string txt, string p, int m, int n, vector<int> &lps) {
        
        int i = 0;
        int j = 0;
        
        while (i < m) {
            if (txt[i] == p[j]) {
                i += 1;
                j += 1;
                
                if (j == n) {
                    return i - j;
                    // count all occurrences
                    j = lps[j-1];
                }
            } else {
                if (j > 0) {
                    j = lps[j-1];
                } else {
                    i = i + 1;
                }
            }
        }
        return -1;
    }
    
    int strStr(string txt, string p) {
        int m = (int)txt.size();
        int n = (int)p.size();
        
        if (n == 0) return 0;
        if (n > m) return -1;
        
        vector<int> lps(n);
        
        computeLPS(p, n, lps);
        
        for (auto v : lps) {
            cout << v << " ";
        }
        
        return search(txt, p, m, n, lps);
    }
};
