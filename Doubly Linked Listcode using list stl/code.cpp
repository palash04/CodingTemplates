#include <bits/stdc++.h>
using namespace std;

class MyLinkedList{
    list<int> _keys;
    int len;
public:
    MyLinkedList(){
        this->len = 0;
    }
    int get(int index){
        if (index >= len){
            return -1;
        }
        list<int>::iterator it = _keys.begin();
        advance(it,index);
        return *it;
    }
    void addAtHead(int value){
        _keys.push_front(value);
        ++len;
    }
    void addAtTail(int value){
        _keys.push_back(value);
        ++len;
    }
    void addAtIndex(int index,int value){
        if (index > len) return;
        if (index == 0){
            addAtHead(value);
            return;
        }else if(index == len){
            addAtTail(value);
            return;
        }else {
            list<int>::iterator it = _keys.begin();
            advance(it,index);
            _keys.insert(it, value);
            ++len;
        }
    }
    void deleteAtIndex(int index){
        if (index >= len) return;
        list<int>::iterator it = _keys.begin();
        advance(it, index);
        _keys.erase(it);
        --len;
    }
};

int main(){
    MyLinkedList m;
    m.addAtHead(9);
    cout << m.get(1) << "\n";
    m.addAtIndex(1, 1);
    m.addAtIndex(1, 7);
    m.deleteAtIndex(1);
    m.addAtHead(7);
    m.addAtHead(4);
    m.deleteAtIndex(1);
    m.addAtIndex(1, 4);
    m.addAtHead(2);
    m.deleteAtIndex(5);
}
