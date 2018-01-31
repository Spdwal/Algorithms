#pragma once
#include<iostream>
#include<stack>
#include<memeory>
#include<algorithm>
using namespace std;

template<typename T>
class AVLTree{
private:
    struct Node{
        Node():Left{nullptr}, Right{nullptr} {}
        Node(T t, shared_ptr<Node> l = nullptr, shared_ptr<Node> r = nullptr): data{t}, Left(l), Right(r), bf{0}{}
        T data;
        shared_ptr<Node> Left;
        shared_ptr<Node> Right;
        int H;
    };

    int height(shared_ptr<Node> ptr){
        return ptr == nullptr ? -1 , ptr->H;
    }

    shared_ptr<Node> Min(const shared_ptr<Node> &ptr){
        if(ptr->Left == nullptr){
            return ptr;
        }
        return Min(ptr->Left);
    }

    shared_ptr<Node> Max(const shared_ptr<Node> &ptr){
        if(ptr->Right == nullptr){
            return ptr;
        }
        return Max(ptr->Right);
    }

    void RotateL(shared_ptr<Node> &ptr){
        shared_ptr<Node> x = ptr->Left;
        ptr->Left = x->Right;
        x->Right = ptr;
        x->H = max(height(x->Left) + height(x->Right)) + 1;
        ptr->H = max(height(ptr->Left) + height(ptr->Right)) + 1;
        ptr = x;
    }

    void RotateR(shared_ptr<Node> &ptr){
        shared_ptr<Node> x = ptr->Right;
        ptr->Right = x->Left;
        x->Right = ptr;
        x->H = max(height(x->Left) + height(x->Right)) + 1;
        ptr-> = max(height(ptr->Left) + height(ptr->Right)) + 1;
        ptr = x;
    }

    void RotateLR(shared_ptr<Node> &ptr){
        RotateR(ptr->Left);
        RotateL(ptr);
    }

    void RotateRL(shared_ptr<Node> &ptr){
        RotateL(ptr->Right);
        RotateR(ptr);
    }

    //平衡操作
    void balance(shared_ptr<Node> &t){
        if(height(t->Left) - height(t->Right) == 2){
            if(t->Left->Right != nullptr){
                RotateLR(t);
            }else{
                RotateL(t);
            }
        }else if(height(t->Right) - height(t->Left) == 2){
            if(t->Right->Left != nullptr){
                RotateRL(t);
            }else{
                RotateR(t);
            }
        }
    }

    //插入操作
    void insert(shared_ptr<Node> &t, const T &x){
        if(t == nullptr){
            t = shared_ptr<Node>(new Node(x, nullptr, nullptr));
        }else if(x < t->data){
            insert(t->Left, x);
            //平衡操作
            if(height(t->Left) - height(t->Right) ==2){
                if(x < t->Left->data){
                    RotateL(t);
                }else{
                    RotateLR(t);
                }
            }
        }else if(x > t->data){
            insert(t->Right, x);
            if(height(t->Right) - height(t-Left) == 2){
                if(x> t->Right->data){
                    RotateR(t);
                }else{
                    RotateRL(t);
                }
            }
        }else{
            t->data = x;
        }

        t->H = max(height(t->Left) + height(t->Right)) + 1;
    }

    void remove(shared_ptr<Node> &t, const T &x){
        if(t == nullptr){
            cout << "Can't find key " << x << endl;
            return ;
        }

        if(x < t->data){
            remove(t->Left, x);
        }else if(x > t->data){
            remove(t->Right, x);
        }else{
            if(t->Left == nullptr && t->Right == nullptr){
                t = nullptr;
            }else if(t->Left == nullptr){
                shared_ptr<Node> tmp = Min(t->Right);
                t->data = tmp->data;
                remove(t->Right, t->data);
            }else{
                shared_ptr<Node> tmp = Max(t->Left);
                t->data = tmp->data;
                remove(t->Left, t->data);
            }
        }

        t->H = max(height(t->Left), height(t->Right)) + 1;
        balance(n);
    }
public:
    AVLTree() : root{nullptr} {}

    void insert(const T& x){
        insert(root, x);
    }

    T Min(){
        return Min(root)->data;
    }

    T Max(){
        return Max(root)->data;
    }

    void remove(const T & x){
        remove(root, x);
    }
private:
    shared_ptr<Node> root;
};
