class Solution {
public:
    
    void createLPS(vector<int> &lps,string pat,int n){
        lps[0] = -1;
        for (int i=1;i<n;i++){
            if (pat[lps[i-1]+1] == pat[i]){
                lps[i] = lps[i-1]+1;
            }else{
                if (pat[i-1] == pat[i]){
                    lps[i] = lps[i-1];
                }else{
                    lps[i] = -1;
                }
            }
        }
    }
    
    int kmp(const vector<int> &lps,string txt,string pat,int m,int n){
        int i=0;
        int j = -1;
        while (i < m){
            if (txt[i] == pat[j+1]){
                i++;
                j++;
            }else{
                if (j != -1){
                    j = lps[j];
                }else{
                    i++;
                }
            }
            if (j == n-1){
                return i-n;
            }
        }
        return -1;
    }
    
    int strStr(string haystack, string needle) {
        string txt = haystack;
        string pat = needle;
        
        int m = (int)txt.size();
        int n = (int)pat.size();
        
        if (n == 0) return 0;
        
        vector<int> lps(n);
        createLPS(lps,pat,n);
        return kmp(lps,txt,pat,m,n);
    }
};
