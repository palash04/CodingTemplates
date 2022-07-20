#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct TrieNode{
    map<char, TrieNode*> mp;
    TrieNode *children[256];
    bool isEnd;
    
    TrieNode () {
        isEnd = false;
        for (int i=0;i<256;i++) {
            children[i] = NULL;
        }
    }
    
};

// using children[256]
void ins(TrieNode *root, string word) {
    TrieNode *tNode = root;
    for (auto c : word) {
        if (!tNode->children[c]) {
            tNode->children[c] = new TrieNode;
        }
        tNode = tNode->children[c];
    }
    tNode->isEnd = true;
}

void dis(TrieNode *root, string s) {
    if (root->isEnd) {
        cout << s << "\n";
    }
    
    for (int i=0;i<256;i++) {
        if (root->children[i]) {
            s += char(i);
            dis(root->children[i], s);
            s.pop_back();
        }
    }
    
}


// using map
void insert (TrieNode *root, string word) {
    TrieNode *tNode = root;
    
    for (auto c : word) {
        if (tNode->mp.find(c) == tNode->mp.end()) {
            tNode->mp.insert({c, new TrieNode});
        }
        tNode = tNode->mp[c];
    }
    
    tNode->isEnd = true;
    
}

void display(TrieNode *root, string s) {
    if (root->isEnd) {
        cout << s << "\n";
    }
    
    for (auto m : root->mp) {
        char c = m.first;
        s += c;
        display(m.second, s);
        s.pop_back();
    }
    
}

bool search(TrieNode *root, string word) {
    TrieNode *tNode = root;
    
    for (auto c : word) {
        if (tNode->mp.find(c) == tNode->mp.end()) {
            return false;
        }
        tNode = tNode->mp[c];
    }
    
    return tNode != NULL and tNode->isEnd;
    
}

int main() {
    TrieNode *root = new TrieNode();
    
    string keys[] = {"hello", "hell", "win", "winning", "art", "artist", "aero"};
    
    for (auto key : keys) {
        insert(root, key);
    }
    
    display(root, "");
    cout << "\n*****\n\n";
    TrieNode *rootNew = new TrieNode();
    
    for (auto key : keys) {
        ins(rootNew, key);
    }
    
    dis(rootNew, "");
    
}
