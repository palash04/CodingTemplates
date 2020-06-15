#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int x): val(x),left(NULL),right(NULL) {}
};

// O(n) and O(n)
void postOrder(TreeNode *root){
    if (root){
        postOrder(root->left);
        postOrder(root->right);
        cout << root->val << " ";
    }
}

// O(n) and O(n)
void postOrderIterative(TreeNode *root){
    stack<TreeNode*> st;
    vector<int> res;
    st.push(root);
    while (!st.empty()){
        root = st.top();st.pop();
        res.insert(res.begin(), root->val);
        if (root->left){
            st.push(root->left);
        }
        if (root->right){
            st.push(root->right);
        }
    }
    for (auto v : res){
        cout << v << " ";
    }
}

int main(){
    
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(12);
    root->left->right = new TreeNode(8);
    root->right->right = new TreeNode(11);

    postOrder(root);
    cout << "\n";
    postOrderIterative(root);
    cout << "\n";
}
