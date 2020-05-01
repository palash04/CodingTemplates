#include <bits/stdc++.h>
using namespace std;

#define iPair pair<string,string>

class Solution {
public:
   
    string singleMultiply(string num1, string num2){
        
        // base cases // if any one is zero, return zero
        if (num1.size() == 1 && num1[0] == '0'){
            return "0";
        }else if (num2.size() == 1 && num2[0] == '0'){
            return "0";
        }
        
        if (num1 == "1"){   // if any one is '1', return the other number
            return num2;
        }else if (num2 == "1"){
            return num1;
        }
        
        string ans = "";
        string a,b;
        if (num1.size() == 1){
            a = num2;
            b = num1;
        }else{
            a = num1;
            b = num2;
        }
        
        int c = 0, f= b[0]-'0';
        for (int i=(int)a.size()-1;i>=0;i--){
            int s = a[i]-'0';
            int r = (s*f+c)%10;
            char ch = (r+'0');
            ans = ch + ans;
            c = (s*f+c)/10;
        }
        if (c>0) {
            char ch = c + '0';
            ans = ch + ans;
        }
        return ans;
    }
    
    pair<string,string> split(string s){
        int m = (int)s.size() >> 1;
        m = (s.size() & 1) == 1 ? m+1 : m;
        pair<string,string> p = {s.substr(0,m), s.substr(m,s.size()-m)};
        return p;
    }
    
    string add(string num1,string num2){
        string a;
        string b;
        int diff = 0;
        if (num1.size() >= num2.size()){
            a = num1;
            b = num2;
            diff = (int)num1.size()-(int)num2.size();
        }else{
            a = num2;
            b = num1;
            diff = (int)num2.size()-(int)num1.size();
        }
        
        int c = 0;
        string ans="";
        for (int i=(int)b.size()-1;i>=0;i--){
            int x = a[i+diff]-'0';
            int y = b[i]-'0';
            int z = (x + y + c)%10;
            ans = (char)(z+'0')+ans;
            c = (x+y+c)/10;
        }
        for (int i=diff-1;i>=0;i--){
            int x = a[i]-'0';
            int z = (x+c)%10;
            ans = (char)(z+'0')+ans;
            c = (x+c)/10;
        }
        if (c>0){
            ans = (char)(c+'0')+ans;
        }
        ans = trim(ans);
        return ans;
    }
    
    string subtract(string num1, string num2){
        string a = "";
        string b = "";
        
        if (num1.size() > num2.size()){
            a = num1;
            b = num2;
        }else if (num1.size() < num2.size()){
            a = num2;
            b = num1;
        }else {
            for (int i=0;i < num1.size();i++){
                if (num1[i]-'0' > num2[i]-'0'){
                    a = num1;
                    b = num2;
                    break;
                }else if( num2[i]-'0' > num1[i]-'0'){
                    a = num2;
                    b = num1;
                    break;
                }
            }
            if (a == "") return "0";  // num1 and num2 are same
        }
        int c = 0;
        string ans = "";
        int diff = (int)a.size() - (int)b.size();
        for (int i=(int)a.size()-1;i>=0;i--){
            int f = a[i] - '0';
            int s = (i-diff)<0? 0 : b[i-diff]-'0';
            int p = f-s-c;
            if (p < 0){
                p += 10;
                c = 1;
            }else {
                c = 0;
            }
            ans = (char)(p+'0') + ans;
        }
        ans = trim(ans);
        return ans;
    }
    
    string trim(string s){
        while (s.size() > 1 && s[0] == '0'){
            s.erase(s.begin());
        }
        return s;
    }
    
    string pad(string s, int zeros){
        for (int i=0;i<zeros;i++){
            s.push_back('0');
        }
        return s;
    }
    
    string multiply(string num1, string num2) {
        
        if (num1 == "" || num2 == ""){
            return "";
        }
        
        if (num1.size() == 1 || num2.size() == 1){
            return singleMultiply(num1, num2);
        }

        int len = max((int)num1.size(), (int)num2.size());
        string pa = "",pb = "";
        for (int i=(int)num1.size();i<len;i++){
            pa += '0';
        }
        for (int i=(int)num2.size();i<len;i++){
            pb += '0';
        }
        num1 = pa + num1;
        num2 = pb + num2;
        
        iPair p1 = split(num1);
        iPair p2 = split(num2);
        string a = p1.first;
        string b = p1.second;
        string c = p2.first;
        string d = p2.second;
        
        // do 3 multiplications
        string a_c = multiply(a, c);
        string b_d = multiply(b, d);
        string ab_cd = multiply(add(a,b),add(c, d));
        string e = subtract(subtract(ab_cd, a_c), b_d);
        return add(add(pad(e, len>>1), b_d), pad(a_c, (len>>1)<<1));
    }
};

int32_t main(){
    
    Solution s;
    string num1 = "1211111132131";
    string num2 = "2121111999312";
    
    cout << s.multiply(num1, num2) << "\n";
    
}
