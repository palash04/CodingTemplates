/*
          37
        /    \
       5      10 
     /  \    /  \
    2    3  4    1
        /    \
       15     10
             /
            13
    
Output - 
37->5->2
37->5->3->15
37->10->4->10->13
37->10->1

*/


#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    
    void process(vector<int> &path){
        string subres = "";
        for (auto p : path){
            subres += to_string(p);
            subres += "->";
        }
        subres.pop_back();
        subres.pop_back();
        cout << subres << "\n";
    }
    
    void solve(TreeNode *root,vector<int> path){
        
        if (!root){
            return;
        }
        
        if (!root->left && !root->right){
            path.push_back(root->val);
            process(path);
            return;
        }
        
        path.push_back(root->val);
        solve(root->left,path);
        solve(root->right,path);
        path.pop_back();
    }
    
    void allPaths(TreeNode *root){
        vector<int> path;
        solve(root,path);
    }
};

int main(){
    TreeNode *root = new TreeNode(37);
    root->left = new TreeNode(5);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(1);
    root->left->right->left = new TreeNode(15);
    root->right->left->right = new TreeNode(10);
    root->right->left->right->left = new TreeNode(13);
    
    Solution s;
    s.allPaths(root);
    cout << "\n";
}
