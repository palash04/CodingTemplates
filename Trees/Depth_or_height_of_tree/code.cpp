/*
    
         1
       /   \
      2     3
     / \   / \
    4   5     6
               \
                7
               /
              8

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
Here, maxDepth = 5
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
    // O(n),O(n)
    int heightOfTree(TreeNode *root){
        int left,right;
        if (root){
            left = heightOfTree(root->left);
            right = heightOfTree(root->right);
            if (left > right){
                return left + 1;
            }else{
                return right + 1;
            }
        }
        return 0;
    }
    
    // O(n),O(n)
    int heightOfTreeIterative(TreeNode *root){
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty()){
            TreeNode *curr = q.front();q.pop();
            if (curr == NULL){
                level++;
                if (!q.empty()){
                    q.push(NULL);
                }
            }else{
                if (curr->left){
                    q.push(curr->left);
                }
                if (curr->right){
                    q.push(curr->right);
                }
            }
        }
        return level;
    }
    
};

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->right->right = new TreeNode(7);
    root->right->right->right->left = new TreeNode(8);
    
    Solution s;
    cout << s.heightOfTree(root) << "\n";
    cout << s.heightOfTreeIterative(root);
    cout << "\n";
}
