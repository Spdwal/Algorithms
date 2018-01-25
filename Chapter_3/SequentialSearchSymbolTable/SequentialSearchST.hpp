#pragma once
#include<numeric>
#include<iostream>
#include<vector>
#include<utility>
using namespace std;


template<typename Key, typename Value>
class SequentialSearchST{
private:
    struct Node{
        Node(const Key k, const Value v, Node *n):key(k), value(v), next(n) {}
        Key key;
        Value value;
        Node *next;
    };

    void deconstructor(Node* x){
        if(x == nullptr){
            return;
        }
        deconstructor(x->next);
        delete x;
    }
public:
    SequentialSearchST():first(nullptr), N{0} {};
    Node* find(Key k){
        for(Node *x = first; x != nullptr; x = x->next){
            if(k == x->key){
                return x;
            }
        }
        return nullptr;
    }

    Node* find_before(Key k){
        if(k == first->key){
            return first;
        }
        for(Node *x = first; x->next != nullptr; x = x->next){
            if(k == x->next->key){
                return x;
            }
        }
        return nullptr;
    }
    Value get(Key k){
        Node * ptr = find(k);
        if(ptr != nullptr){
            return ptr->value;
        }else{
            cout << "Key: " << k << " not found." << endl;
            exit(1);
        }
    }

    int Size(){
        return N;
    }
    vector<pair<Key, Value>> keys(Key low, Key high){
        vector<pair<Key, Value>> ivec;
        for(Node *x = first; x != nullptr; x = x->next){
            if(x->key <= high && x->key >= low){
                ivec.push_back(make_pair(x->key, x->value));
            }
        }

        return ivec;
    }

    void Delete(Key k){
        Node *ptr = find_before(k);
        if(ptr == nullptr){
            cout << "Not find " << k << endl;
        }else if(ptr == first && k == ptr->key){
            N--;
            Node * p = first;
            first = first->next;
            delete p;
        }else{
            N--;
            Node *p = ptr->next;
            ptr->next = ptr->next->next;
            delete p;
        }
    }
    void put(Key k, Value v){
        Node *ptr = find(k);
        if(ptr != nullptr){
            ptr->value = v;
            return;
        }
        N++;
        first = new Node(k, v, first);
        return;
    }

    ~SequentialSearchST(){
        deconstructor(first);
    }
private:
    int N;
    Node *first;
};

