#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int x): val(x),left(NULL),right(NULL) {}
};

// O(n), O(n)
void inorder(TreeNode *root){
    if (root){
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}

// O(n), O(n)
void inoderIterative(TreeNode *root){
    stack<TreeNode*> st;
    while (true){
        while (root){
            st.push(root);
            root = root->left;
        }
        if (st.empty()){
            break;
        }
        root = st.top();
        st.pop();
        cout << root->val << " ";
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

    inorder(root);
    cout << "\n";
    inoderIterative(root);
    cout << "\n";
}
