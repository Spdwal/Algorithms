#pragma once
#include<utility>

using namespace std;

class PQ{
private:
    struct Node{
        Node(int d, int N): data{d}, n(N), parent{nullptr}, left{nullptr}, right{nullptr}{}
        int data;
        int n;
        Node * parent;
        Node * left;
        Node * right;
    };

    int size(Node *p){
        if(p == nullptr) return 0;
        return p->n;
    }
    void swapNode(Node * x, Node * y){
        std::swap(x->data, y->data);
    }

    void swim(Node *x){
        if(x == nullptr) return;
        if(x->parent == nullptr) return;
        if(x->data > x->parent->data){
            swapNode(x, x->parent);
            swim(x->parent);
        }
    }

    void sink(Node *x){
        if(x == nullptr) return ;
        Node *swap_node;
        if(x->left == nullptr && x->right ==nullptr){
            return ;
        }else if(x->left == nullptr){
            swap_node = x->right;
            if(x->data < swap_node->data){
                swapNode(x, x->right);
            }
        }else if(x->right == nullptr){
            swap_node = x->left;
            if(x->data < swap_node->data){
                swapNode(x, x->left);
            }
        }else{
            if(x->right->data > x->left->data){
                swap_node = x->right;
            }else{
                swap_node = x->left;
            }
            if(swap_node->data > x->data){
                swapNode(swap_node, x);
                sink(swap_node);
            }
        }
    }
    //只负责将节点插入，而不负责将节点swim或者sink
    Node * insert(Node * x, int data){
        //root == nullptr 或者到了叶子节点。
        if(x == nullptr){
            lastInserted = new Node(data, 1);
            return lastInserted;
        }
        //else 跟据size是向左子树还是右子树递归向下插入，
        int leftSize = size(x->left);
        int rightSize = size(x->right);
        if(leftSize <= rightSize){
            Node *inserted = insert(x->left, data);
            x->left = inserted;
            inserted->parent = x;
        }else{
            Node *inserted = insert(x->right, data);
            x->right = inserted;
            inserted->parent = x;
        }
        x->n = size(x->left) + size(x->right) + 1;
        return x;
    }

    Node *resetLastInserted(Node *x){
        if(x == nullptr) return nullptr;
        if(x->left == nullptr && x->right == nullptr) return x;
        if(size(x->right) < size(x->left)) return resetLastInserted(x->left);
        else                               return resetLastInserted(x->right);
    }


public:
    PQ(): root{nullptr}, Size{0}, lastInserted{nullptr}{}
    void insert(int data){
        root = insert(root, data);
        swim(lastInserted);
    }

    int Max(){
        if(root == nullptr) return 0;
        return root->data;
    }

    int delMax(){
        if(size() == 1){
            int ret = root->data;
            root = nullptr;
            return ret;
        }
        swapNode(root, lastInserted);
        Node * lastInsertParent = lastInserted->parent;
        int lastInsertData = lastInserted->data;
        if(lastInserted == lastInsertParent->left){
            lastInsertParent->left = nullptr;
        }else{
            lastInsertParent->right = nullptr;
        }
        Node * traverser = lastInserted;
        while(traverser != nullptr){
            traverser->n--;
            traverser = traverser->parent;
        }

        delete lastInserted;
        lastInserted = resetLastInserted(root);
        sink(root);
        return lastInsertData;
    }

    int size(){
        return size(root);
    }

    bool isEmpty(){
        return size() == 0;
    }
private :
    Node *lastInserted;
    int Size;
    Node * root;
};

