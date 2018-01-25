#pragma once
#include<iostream>
#include<queue>
#include<algorithm>
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

    Node* max(Node *x){
        if(x->Right == nullptr){
            return x;
        }else{
            return max(x->Right);
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

    Node* deleteMin(Node *x){
        if(x->Left == nullptr){
            Node *tmp = x->Right;
            delete x;
            return tmp;
        }else{
            x->Left = deleteMin(x->Left);
            x->N = size(x->Left) + size(x->Right) + 1;
            return x;
        }
    }

    Node* deleteKey(Node *x, Key k){
        if(x==nullptr){
            return nullptr;
        }
        if(k < x->key){
            x->Left = deleteKey(x->Left, k);
        }else if(k > x->key){
            x->Right = deleteKey(x->Right, k);
        }else{
            if(x->Right == nullptr){
                Node *tmp = x->Left;
                delete x;
                return tmp;
            }
            if(x->Left == nullptr){
                Node *tmp = x->Right;
                delete x;
                return tmp;
            }
            Node *tmp = x;
            x = min(tmp->Right);
            x->Right = deleteMin(tmp->Right);
            x->Left = tmp->Left;
            delete tmp;
        }
        x->N = size(x->Left) + size(x->Right) + 1;
        return x;
    }

    void print(Node *x){
        if(x == nullptr){
            return;
        }
        print(x->Left);
        cout << "Key: " << x->key << " Value: " << x->val << endl;
        print(x->Right);
    }

    void keys(Node *x, std::queue<Key> &que, Key low, Key high){
        if(x == nullptr){
            return ;
        }
        if(low < x->key){
            keys(x->Left, que, low, high);
        }
        if(low <= x->key && high >= x->key){
            que.push(x->key);
        }
        if(high > x->key){
            keys(x->Right, que, low, high);
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

    Key max(){
        return max(root)->key;

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

    void deleteMin(){
        root = deleteMin(root);
    }

    void deleteKey(Key k){
        root = deleteKey(root, k);
    }

    void print(){
        print(root);
    }

    std::queue<Key> keys(Key low, Key high){
        std::queue<Key> que;
        keys(root, que, low, high);
        return que;
    }
    std::queue<Key> keys(){
        return keys(min(), max());
    }

    int height(Node *x){
        if(x == nullptr)
            return 0;
        return std::max(height(x->Left), height(x->Right)) + 1;
    }
    int height(){
        return height(root);
    }
private:
    Node *root;
};
