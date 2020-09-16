/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> v;
        int level = 1;
        while (!q.empty()) {
            TreeNode *curr = q.front();
            q.pop();
            if (curr != NULL) {
                v.push_back(curr->val);
                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
            }else {
                if (!(level & 1)) {
                    reverse(v.begin(), v.end());
                }
                res.push_back(v);
                v.clear();
                level++;
                if (!q.empty()) {
                    q.push(NULL);
                }
            }
        }
        return res;
    }
};
