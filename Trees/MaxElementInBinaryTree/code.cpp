#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    
    int solve(TreeNode *root){
        
        if (!root){
            return INT_MIN;
        }
        
        if (!root->left && !root->right){
            return root->val;
        }
        int max = INT_MIN;
        int left = solve(root->left);
        int right = solve(root->right);
        
        if (root->val > max){
            max = root->val;
        }
        if (left > max){
            max = left;
        }else if(right > max){
            max = right;
        }
        return max;
    }
    
    // O(n),O(n)
    int maxElement(TreeNode *root){
        return solve(root);
    }
    
    // O(n),O(n)
    int maxElementIterative(TreeNode *root){
        queue<TreeNode*> bfsq;
        bfsq.push(root);
        int max = INT_MIN;
        while (!bfsq.empty()){
            TreeNode *curr = bfsq.front();bfsq.pop();
            if (curr->val > max) max = curr->val;
            if (curr->left){
                bfsq.push(curr->left);
            }
            if (curr->right){
                bfsq.push(curr->right);
            }
        }
        return max;
    }
    
};

int main(){
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(9);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(1);
    
    Solution s;
    cout << s.maxElement(root) << "\n";
    cout << s.maxElementIterative(root) << "\n";
}
