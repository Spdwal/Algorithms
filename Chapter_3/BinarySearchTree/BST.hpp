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
    int size(Node *x){
        if(x == nullptr){
            return 0;
        }else{
            return x->N;
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

    Node* min(Node *x){
        if(x->Left == nullptr){
            return x;
        }else{
            return min(x->Left);
        }
    }


    Node* select(Node*x, int k){
        if(x == nullptr){
            cout << "Can't find the " << k <<"th" << endl;
            return nullptr;
        }
        int t = size(x->Left);
        if(t > k){
            return select(x->Left, k);
        }else if(t < k){
            return select(x->Right, k - t - 1);
        }else{
            return x;
        }
    }

    int rank(Key k, Node *x){
        if(x == nullptr){
            return 0;
        }
        if(k < x->key){
            return rank(k, x->Left);
        }else if(k > x->key){
            return 1 + size(x->Left) + rank(k, x->Right);
        }else{
            return size(x->Left);
        }
    }
public:
    BST():root(nullptr){}

    int size(){
        return size(root);
    }

    Key min(){
        return min(root)->key;
    }

    Key floor(Key k){
        Node *x = floor(root, k);
        if(x == nullptr){
            cout << "Can't find the Key " << k << endl;
            exit(1);
        }
    }

    Key select(int k){
        return select(root, k)->key;
    }
    void put(Key k, Value v){
        root = put(root, k, v);
    }
    Value get(Key k){
        return get(root, k);
    }

    int rank(Key k){
        return rank(k, root);
    }
private:
    Node *root;
};
