/*

Given Tree: 

          37
        /    \
       5      10 
     /  \    /  \
    2    3  4    1
        /    \
       15     10
             /
            13
            
            
Ouput Tree:

          37
        /    \
      10      5 
     /  \    /  \
    1    4  3    2
        /    \
       10     15
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
public:

    // O(n), O(n)
    TreeNode *mirrorTree(TreeNode *root){
        if (root){
            mirrorTree(root->left);
            mirrorTree(root->right);
            TreeNode *temp = root->left;
            root->left = root->right;
            root->right = temp;
        }
        return root;
    }
    
    void levelOrderTrav(TreeNode *root){
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty()){
            TreeNode *curr = q.front();q.pop();
            if (!curr){
                cout << "\n";
                if (!q.empty()){
                    q.push(NULL);
                }
            }else{
                cout << curr->val << " ";
                if (curr->left){
                    q.push(curr->left);
                }
                if (curr->right){
                    q.push(curr->right);
                }
            }
        }
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
    s.levelOrderTrav(root);
    cout << "\n\n";
    root = s.mirrorTree(root);
    s.levelOrderTrav(root);
    cout << "\n\n";
}
