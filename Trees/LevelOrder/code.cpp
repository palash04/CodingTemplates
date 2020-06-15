#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int x): val(x),left(NULL),right(NULL) {}
};

// O(n) and O(n)
void levelOrder(TreeNode *root){
    queue<TreeNode*> bfsq;
    bfsq.push(root);
    while (!bfsq.empty()){
        root = bfsq.front();
        bfsq.pop();
        cout << root->val << " ";
        if (root->left){
            bfsq.push(root->left);
        }
        if (root->right){
            bfsq.push(root->right);
        }
    }
}

int main(){
    
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(12);
    root->left->right = new TreeNode(8);
    root->right->right = new TreeNode(11);

    levelOrder(root);
    cout << "\n";
}
