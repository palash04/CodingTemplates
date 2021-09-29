/*

Memory optimized trie

Insert, Search => O(M) # max length of string
Space => O(M * N) # N: number of keys
 
*/

#include <bits/stdc++.h>
using namespace std;

struct Trie{
    map<char, Trie*> mp;
    bool isEnd;
};

void insert(Trie *root, string word) {
    Trie *temp = root;

    for (auto c : word) {
        if (temp->mp.find(c) == temp->mp.end()) {
            temp->mp[c] = new Trie();
        }
        temp = temp->mp[c];
    }
    temp->isEnd = true;
}

bool search(Trie *root, string word) {
    Trie *temp = root;
    for (auto c : word) {
        if (temp->mp.find(c) == temp->mp.end()) {
            return false;
        }
        temp = temp->mp[c];
    }
    return temp and temp->isEnd;
}

void display(Trie *root, string s) {

    if (root->isEnd) {
        cout << s << "\n";
    }

    for (auto m : root->mp) {
        s += m.first;
        display(m.second, s);
        s.pop_back();
    }

}

int main() {

    string keys[] = {"hello", "hell", "win", "winner", "winn", "art", "artist"};

    Trie *root = new Trie();

    for (auto key : keys ) {
        insert(root, key);
    }

//    cout << search(root, "art") << "\n";
//    cout << search(root, "arti") << "\n";
    display(root, "");
}
