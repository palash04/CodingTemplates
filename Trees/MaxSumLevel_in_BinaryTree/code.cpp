/*
            12
          /    \
         5      10
       /   \   /  \
      2     3 4    1
           /   \
          15    10
               /
              13
              
ouput: 3

Since, level 3 has maximum sum : 15+10 = 25
            
Level starts from 0

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
    int maxSumLevel(TreeNode *root){
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int curr_sum = 0;
        int max_sum = INT_MIN;
        int maxLevel = 0;
        while (!q.empty()){
            TreeNode *curr = q.front();q.pop();
            if (!curr){
                if (curr_sum > max_sum){
                    max_sum = curr_sum;
                    maxLevel = level;
                }
                curr_sum = 0;
                if (!q.empty()){
                    q.push(NULL);
                }
                level++;
            }else{
                curr_sum += curr->val;
                if (curr->left){
                    q.push(curr->left);
                }
                if (curr->right){
                    q.push(curr->right);
                }
            }
        }
        return maxLevel;
    }
};

int main(){
    TreeNode *root = new TreeNode(12);
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
    cout << s.maxSumLevel(root);
    cout << "\n";
}
