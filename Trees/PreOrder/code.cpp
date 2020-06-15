#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int x): val(x),left(NULL),right(NULL) {}
};

// O(n) and O(n)
void preorder(TreeNode *root){
    if (root){
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// O(n) and O(n)
void preorderIterative(TreeNode *root){
    stack<TreeNode*> st;
    while (true){
        while (root) {
            cout << root->val << " ";
            st.push(root);
            root = root->left;
        }
        if (st.empty()){
            break;
        }
        root = st.top();
        st.pop();
        root = root->right;
    }
}

int main(){
    
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(12);
    root->left->right = new TreeNode(8);
    root->right->right = new TreeNode(11);

    preorder(root);
    cout << "\n";
    preorderIterative(root);
    cout << "\n";
}
