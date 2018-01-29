#pragma once
#include<iostream>
#include<memory>
using namespace std;

template<typename Key, typename Value>
class RBTree{
private:
    //确定颜色
    static bool RED;
    static bool BLACK;
    struct Node{
        Node(Key k, Value v, int n, bool clr):key(k), val(v), N(n), color(clr), Left(nullptr), Right(nullptr) {}
        Key key;
        Value val;
        shared_ptr<Node> Left;
        shared_ptr<Node> Right;
        int N;
        bool color;
    };

    int size(shared_ptr<Node> x){
        if(x == nullptr){
            return 0;
        }
        return x->N;
    }

    //判断节点的颜色
    bool isRed(shared_ptr<Node> x){
        if(x == nullptr){
            return false;
        }
        return x->color == RBTree::RED;
    }

    //左旋转，使红色右连接变成红色左连接
    shared_ptr<Node> rotateLeft(shared_ptr<Node> h){
        //主要便是此连接h与其右连接x之间的变换，此处获得x节点。
        shared_ptr<Node> x = h->Right;
        //将x的左节点给h的空出来的右节点，x的左节点要让给h
        h->Right = x->Left;
        x->Left = h;
        //x继承h的节点的颜色，整个这个整体的颜色没有改变
        x->color = h->color;
        //h变成红色节点
        h->color = RBTree::RED;
        x->N = h->N;
        h->N = 1 + size(h->Left) + size(h->Right);
        //返回x给上层节点
        return x;
    }

    shared_ptr<Node> rotateRight(shared_ptr<Node> h){
        //获得h得左节点x
        shared_ptr<Node> x = h->Left;
        //将x得right节点给h的空出来的Left节点
        h->Left = x->Right;
        //将h节点放在x的右节点的位置上
        x->Right = h;
        //同上
        x->color = h->color;
        h->color = RBTree::RED;
        x->N = h->N;
        h->N = 1 + size(h->Left) + size(h->Right);
        return x;
    }

    //如果两个子节点都是红色节点，全部变色
    void flipColors(shared_ptr<Node> h){
        h->color = RBTree::RED;
        h->Left->color = RBTree::BLACK;
        h->Right->color = RBTree::BLACK;
    }

    //插入节点的实现
    shared_ptr<Node> put(shared_ptr<Node> h, Key k, Value v){
        if(h == nullptr){
            return shared_ptr<Node>(new Node(k, v, 1, RBTree::RED));
        }

        if(k < h->key){
            h->Left = put(h->Left, k, v);
        }else if(k > h->key){
            h->Right = put(h->Right, k, v);
        }else{
            h->val = v;
        }

        if(isRed(h->Right) && !isRed(h->Left)){
            h = rotateLeft(h);
        }
        if(isRed(h->Left) && isRed(h->Left->Left)){
            h = rotateRight(h);
        }
        if(isRed(h->Left) && isRed(h->Right)){
            flipColors(h);
        }

        h->N = 1 + size(h->Right) + size(h->Left);
        return h;
    }

    Value get(shared_ptr<Node> x, Key k){
        if(x == nullptr){
            cout << "Can't find Key " << k << endl;
            exit(1);
        }
        if(k < x->key){
            return get(x->Left, k);
        }else if(k > x->key){
            return get(x->Right, k);
        }else{
            return x->key;
        }
    }
public:

    RBTree(): root(nullptr) {}

    int size(){
        return size(root);
    }

    //插入节点
    void put(Key k, Value v){
        root = put(root, k, v);
        root->color = RBTree::BLACK;
    }

    Value get(Key k){
        return get(root, k);
    }

private:
    shared_ptr<Node> root;
};

template<typename Key, typename Value>
bool RBTree<Key, Value>::RED = true;

template<typename Key, typename Value>
bool RBTree<Key, Value>::BLACK = false;
