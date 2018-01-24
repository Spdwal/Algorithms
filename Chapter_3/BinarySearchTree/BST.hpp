#pragma once
#include<iostream>
using std::endl;
using std::cout;

template<typename Key, typename Value>
class BST{
private:
    struct Node{
        Node() = default;
        Node(Key k, Value v, int n): key{k}, val{v}, N{n}, Left{nullptr}, Right{nullptr} {}
        Key key;
        Value val;
        Node *Left;
        Node *Right;
        int N;
    };
public:
    BST():root(nullptr){}

    int size(Node *x){
        if(x == nullptr){
            return 0;
        }else{
            return x->N;
        }
    }
    int size(){
        return size(root);
    }

    Value get(Node *x, Key k){
        if(x == nullptr){
            cout << "Can't find Key " << k << endl;
        }
        if(k > x->key){
            return get(x->Right, k);
        }else if(k < x->key){
            return get(x->Left, k);
        }else{
            return x->val;
        }
    }
    
    Node* put(Node *x, Key k, Value v){
        if(x == nullptr){
            Node *ptr = new Node(k, v, 1);
            return ptr;
        }
        if(k > x->key){
            x->Right = put(x->Right, k, v);
        }else if(k < x->key){
            x->Left = put(x->Left, k, v);
        }else{
            x->val = v;
        }
        x->N = size(x->Left) + size(x->Right) + 1;
        return x;
    }

    void put(Key k, Value v){
        root = put(root, k, v);
    }
    Value get(Key k){
        return get(root, k);
    }
private:
    Node *root;
};
