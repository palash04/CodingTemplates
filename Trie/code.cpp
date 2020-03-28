#include <bits/stdc++.h>
using namespace std;

#define alpha 26

struct TrieNode{
    TrieNode *children[alpha];
    bool isEndWord;
};

TrieNode* getNode(){
    TrieNode *tNode = new TrieNode;
    for (int i=0;i<alpha;i++){
        tNode->children[i] = NULL;
    }
    tNode->isEndWord = false;
    return tNode;
}

void insert(TrieNode *root, string key){
    TrieNode *tNode = root;
    for (int i=0;i<key.size();i++){
        int index = key[i] - 'a';
        if (!tNode->children[index]){
            tNode->children[index] = getNode();
        }
        tNode = tNode->children[index];
    }
    tNode->isEndWord = true;
}

bool search(TrieNode *root, string key){
    TrieNode *tNode = root;
    for (int i=0;i<key.size();i++){
        int index = key[i] - 'a';
        if (!tNode->children[index]){
            return false;
        }
        tNode = tNode->children[index];
    }
    return (tNode != NULL && tNode->isEndWord);
}

void display(TrieNode *root,string res){
    
    if (root->isEndWord){
        cout << res << "\n";
    }
    
    for (int i=0;i<alpha;i++){
        if (root->children[i]){
            res += i+'a';
            display(root->children[i],res);
            res.pop_back();
        }
    }
}

int main(){
    string keys[] = {"won","win","there","the","those","art","artist","air","poll"};
    TrieNode *root = getNode();
    for (auto key : keys){
        insert(root, key);
    }
    string target = "thoses";
    if (search(root,target)){
        cout << "Target found\n";
    }else{
        cout << "Target not found\n";
    }
    display(root, "");
}
