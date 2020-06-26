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

*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    TreeNode *res;
public:
    
    // O(n), O(n)
    bool solve(TreeNode *root, TreeNode *p, TreeNode *q){
        
        if (!root){
            return false;
        }
        bool left,right,mid;
        
        left = solve(root->left,p,q) ? 1 : 0;
        right = solve(root->right,p,q) ? 1 : 0;
        
        mid = (root == p || root == q) ? 1 : 0;
        
        if (left + right + mid > 1){
            res = root;
            return true;
        }
        return (left+right+mid > 0);
        
    }
    
    TreeNode *lca(TreeNode *root, TreeNode *p, TreeNode *q){
        solve(root,p,q);
        return res;
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
    TreeNode *p = root->left;
    TreeNode *q = root->left->right->left;
    TreeNode *res = s.lca(root, p, q);
    cout << res->val;
    cout << "\n";
}
