#include <iostream>
#include <vector>
#include <string>

using namespace std;

class HashTable {
private:

    struct Entry {
        string key;
        int value;
        bool isDeleted;
        
        Entry(): key(""), value(0), isDeleted(false) {}
        Entry(string k, int v): key(k), value(v), isDeleted(false) {}
        
    };

    vector<Entry> table;
    int size;
    int capacity;
    
    int hash(const string &key) {
        int hashValue = 0;
        for (char c : key) {
            hashValue = (31 * hashValue + c) % capacity;
        }
        return hashValue;
    }
    
    int findIndex(const string &key) {
        int index = hash(key);
        int originalIndex = index;
        while (!table[index].key.empty() or table[index].isDeleted) {
            if (table[index].key == key and !table[index].isDeleted) {
                return index;
            }
            index = (index + 1) % capacity; // linear probing (next slot)
            if (index == originalIndex) {
                break;   // prevent infinite loop if table is full
            }
        }
        return -1;
    }

public: 
    HashTable(int cap): size(0), capacity(cap) {
        table.resize(capacity);
    }
    
    void add(const string &key, int value) {
        int index = hash(key);
        
        while (!table[index].key.empty() and table[index].key != key and !table[index].isDeleted) {
            index = (index + 1) % capacity;
        }
        
        if (table[index].key.empty() or table[index].isDeleted) {
            table[index] = Entry(key, value);
            size++;
        } else if (table[index].key == key){
            table[index].value = value; // update the value
        }
    }
    
    bool exists(const string &key) {
        int index = findIndex(key);
        return index != -1;
    }
    
    int get(const string &key) {
        int index = findIndex(key);
        if (index != -1) {
            return table[index].value;
        }
        throw runtime_error("key not found");
    }
    
    void remove(const string &key) {
        int index = findIndex(key);
        if (index != -1) {
            table[index].isDeleted = true;
            table[index].key = "";
            size--;
        }
    }

};

int main() {
    HashTable ht(10);
    ht.add("one", 1);
    ht.add("two", 2);
    ht.add("three", 3);
    
    cout << ht.exists("one") << "\n";
    cout << ht.exists("onee") << "\n";
    
    cout << ht.get("three") << "\n";   
    ht.remove("two");
    cout << ht.exists("two") << "\n";
    ht.add("three", 4);
    cout << ht.get("three") << "\n";   
}
