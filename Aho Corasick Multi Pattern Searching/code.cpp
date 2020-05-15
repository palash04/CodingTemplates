#include <bits/stdc++.h>
using namespace std;


class Ahocorasick{
    struct Trie{
        Trie *child[26];
        Trie *suffixLink;
        Trie *outputLink;
        bool isEnd;
        int level;
        Trie(){
            for (int i=0;i<26;i++){
                child[i] = NULL;
            }
            suffixLink = outputLink = NULL;
            level = 0;
            isEnd = false;
        }
    };
    Trie *root;
    Trie *state;
    
    void buildTrie(vector<string> &words){
        for (auto &word : words){
            Trie *node = root;
            for (auto w : word){
                if (!node->child[w-'a']){
                    node->child[w-'a'] = new Trie();
                }
                node->child[w-'a']->level = node->level + 1;
                node = node->child[w-'a'];
            }
            node->isEnd = true;
        }
    }
    
    void buildSuffixLink(){
        queue<Trie*> bfsQ;
        root->suffixLink = root;
        bfsQ.push(root);
        while (!bfsQ.empty()){
            Trie *curr = bfsQ.front();
            bfsQ.pop();
            for (int i=0;i<26;i++){
                if (curr->child[i]){
                    Trie *suf = curr->suffixLink;
                    while (suf != root && !suf->child[i]){
                        suf = suf->suffixLink;
                    }
                    if (suf->child[i] && suf != curr){
                        curr->child[i]->suffixLink = suf->child[i];
                    }else{
                        curr->child[i]->suffixLink = root;
                    }
                    bfsQ.push(curr->child[i]);
                }
            }
        }
    }
    
    void buildOutputLink(){
        queue<Trie*> bfsQ;
        bfsQ.push(root);
        while (!bfsQ.empty()){
            Trie *curr = bfsQ.front();
            bfsQ.pop();
            Trie *suf = curr->suffixLink;
            while (suf != root && !suf->isEnd){
                suf = suf->suffixLink;
            }
            if (suf->isEnd && suf != curr){
                curr->outputLink = suf;
            }
            for (int i=0;i<26;i++){
                if (curr->child[i]){
                    bfsQ.push(curr->child[i]);
                }
            }
            
        }
    }
    
public:
    
    Ahocorasick(vector<string> &words){
        root = new Trie();
        buildTrie(words);
        buildSuffixLink();
        buildOutputLink();
        state = root;
    }
    
    void searchPatterns(string txt){
        int count = 0;
        for (int i=0;i<txt.size();i++){
            int index = txt[i] - 'a';
            while (state != root && !state->child[index]){
                state = state->suffixLink;
            }
            if (state->child[index]){
                state = state->child[index];
            }
            if (state->isEnd){
                int sindex = i - state->level + 1;
                cout << sindex << " " << txt.substr(sindex,state->level) << "\n";
                count++;
            }
            if (state->outputLink){
                Trie *opnode = state;
                while (opnode->outputLink){
                    opnode = opnode->outputLink;
                    int sindex = i - opnode->level + 1;
                    cout << sindex << " " << txt.substr(sindex,opnode->level) << "\n";
                    count++;
                }
            }
        }
        cout << count << "\n";
    }
    
};

int main(){
    vector<string> words = {"in","ing","tin","sting","win","inac","inactive"};
    Ahocorasick ahocorasick(words);
    
    string txt = "wingsting";
    ahocorasick.searchPatterns(txt);
}
