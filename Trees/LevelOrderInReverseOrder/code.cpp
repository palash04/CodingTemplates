/*

      1
     / \
    2   3
   / \ / \
  4  5 6  7
  
  output : 4 5 6 7 2 3 1

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
    //O(n),O(n)
    void levelOrderInReverseOrder(TreeNode *root){
        stack<TreeNode*> st;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            TreeNode *curr = q.front();
            q.pop();
            if (curr->right){
                q.push(curr->right);
            }
            if (curr->left){
                q.push(curr->left);
            }
            st.push(curr);
        }
        while(!st.empty()){
            cout << st.top()->val << " ";
            st.pop();
        }
    }
};

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    
    Solution s;
    s.levelOrderInReverseOrder(root);
    cout << "\n";
}
