#pragma once
#include<numeric>
#include<iostream>
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
public:
    SequentialSearchST():first(nullptr){};
    Value get(Key k){
        for(Node* x = first; x != nullptr; x = x->next){
            if(k == x->key){
                return x->value;
            }
        }
        cout << "Key: " << k << " not found." << endl;
        exit(1);
    }

    void put(Key k, Value v){
        for(Node *x = first; x != nullptr; x = x->next)
        {
            if(k == x->key){
                x->value = v;
                return ;
            }
        }
        first = new Node(k, v, first);
        return;
    }
private:
    Node *first;

};

