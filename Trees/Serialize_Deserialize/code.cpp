#include <bits/stdc++.h>
using namespace std;

class Codec {
    struct Tree{
        int val;
        Tree *left,*right;
        int uId;
        Tree(int x,int id) : val(x), uId(id), left(NULL), right(NULL) {}
    };
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root){
            return "X,";
        }
        string leftSerialized = serialize(root->left);
        string rightSerialized = serialize(root->right);
        return to_string(root->val) + "," + leftSerialized + rightSerialized;
    }

    
    vector<string> splitString(string s,char splitCharacter){
        stringstream ss(s);
        vector<string> v;
        while (ss.good()){
            string str;
            getline(ss,str,splitCharacter);
            v.push_back(str);
        }
        return v;
    }
    
    TreeNode *deserializeHelper(queue<string> &nodesLeft){
        string valueForNode = nodesLeft.front();nodesLeft.pop();
        if (valueForNode == "X"){
            return NULL;
        }
        TreeNode *newNode = new TreeNode(stoi(valueForNode));
        newNode->left = deserializeHelper(nodesLeft);
        newNode->right = deserializeHelper(nodesLeft);
        return newNode;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> v = splitString(data, ',');
        queue<string> nodesLeft;
        for (auto &s : v){
            nodesLeft.push(s);
        }
        return deserializeHelper(nodesLeft);
    }
    
};
