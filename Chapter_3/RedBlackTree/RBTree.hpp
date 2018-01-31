#pragma once
#include<iostream>
#include<memory>
#include<algorithm>
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

    int height(shared_ptr<Node> h){
        if(h == nullptr){
            return -1;
        }
        return 1 + std::max(height(h->Left), height(h->Right));
    }


    shared_ptr<Node> Min(shared_ptr<Node> x){
        if(x->Left == nullptr){
            return x;
        }
        return Min(x->Left);
    }


    shared_ptr<Node> Max(shared_ptr<Node> x){
        if(x->Right == nullptr){
            return x;
        }
        return Max(x->Right);
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
        h->color = !h->color;
        h->Left->color = !h->Left->color;
        h->Right->color = !h->Right->color;
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

    shared_ptr<Node> balance(shared_ptr<Node> h){
        if(isRed(h->Right)){
            h = rotateLeft(h);
        }
        if(isRed(h->Left) && isRed(h->Left->Left)){
            h = rotateRight(h);
        }
        if(isRed(h->Left) && isRed(h->Right)){
            flipColors(h);
        }
        h->N = size(h->Left) + size(h->Right) + 1;
        return h;
    }

    //使h或者h左子节点的某个子节点为红节点
    shared_ptr<Node> moveRedLeft(shared_ptr<Node> h){
        //融和成一个4节点
        //本来这个节点左节点为黑，右节点天然为黑
        //flipColor后左右节点都为红，即为一个4节点。
        flipColors(h);
        //如果同时h的右节点的左节点也为红色，此时它便成了一个5节点，应该要避免。
        //将键借给左子节点
        //其实是使右节点的左节点变为根节点，然后元来的根节点和左子节点组成红色节点。
        if(isRed(h->Right->Left)){
            //右节点的左节点取命节点RL，此时RL节点为h的右节点。
            //且R节点为红节点。
            h->Right = rotateRight(h->Right);
            //这里将RL取代原来H的位置与上层节点相连
            //而原来的h节点与L节点组成一个3节点
            h = rotateLeft(h);
            //此时RL节点的左右子节点都为红节点，变色。
            flipColors(h);
        }
        return h;
    }

    //将右子节点或者其子节点变为红节点。
    shared_ptr<Node> moveRedRight(shared_ptr<Node> h){
        //右节点天然为黑，左节点为红
        //变色，将h节点融和和R成一个3节点
        //此时L节点为黑色，R为红色
        flipColors(h);
        //如果h的左子节点的左子节点为红色节点
        if(isRed(h->Left->Left)){
            //h直接右旋，将L节点代替元来的h节点与上层节点相连
            //h节点与R节点组成一个3节点。
            //此时h节点原来R的颜色，即红色。
            h = rotateRight(h);
            //因为此时L节点左右都为红色节点，变色。
            flipColors(h);
        }
        return h;
    }

    shared_ptr<Node> deleteMin(shared_ptr<Node> h){
        if(h->Left == nullptr){
            return nullptr;
        }

        //第一个条件为它的左节点不是红色节点，也就是h节点不是3节点
        //它的左子节点也不是3节点时，需要调整
        if(!isRed(h->Left) && isRed(h->Left->Left)){
            //将左子节点调整成适和删除的状态，避免删除一个2节点
            h = moveRedLeft(h);
        }

        //递归删除
        h->Left = deleteMin(h->Left);

        //自下而上调整成自平衡状态。
        return balance(h);
    }

    shared_ptr<Node> deleteMax(shared_ptr<Node> h){
        //如果左子节点为红色，将红色连接移动到右侧。
        if(isRed(h->Left)){
            //L节点代替h节点的位置，h节点为红色节点。
            h = rotateRight(h);
        }
        
        if(h->Right == nullptr){
            return nullptr;
        }

        if(!isRed(h->Right) && !isRed(h->Right->Left)){
            h = moveRedRight(h);
        }

        h->Right = deleteMax(h->Right);

        return balance(h);
    }

    //delete的实现
    shared_ptr<Node> deleteK(shared_ptr<Node> h, Key k){
        if(k < h->key){
            //如果L不是一个红色节点，且LL节点也不是红色节点
            //意即左节点不是一个3节点，需要从右边移动一个节点到左节点，形成一个3节点
            if(!isRed(h->Left) && !isRed(h->Left->Left)){
                h = moveRedLeft(h);
            }
            //递归删除
            h->Left = deleteK(h->Left, k);
        }else{
            //如果L节点是红色，那么将红色连接移动到右边
            //此时L节点为根节点，M节点为右节点
            //此时RL节点为M节点的右节点
            if(isRed(h->Left)){
                h = rotateRight(h);
            }
            //如果之前h->L为红色节点，此时右节点为一个3节点，如果它为最小，那么就直接删除
            //向下查找的过程中，已经保证了节点不可能是2节点，如果左子节点非空，右子节点空
            //只可能是3节点，经过上一个if，3节点的红连接右斜了。
            if(k == h->key && (h->Right == nullptr)){
                return nullptr;
            }
            //右子树保证非2节点。
            if(!isRed(h->Right) && !isRed(h->Right->Left)){
                h = moveRedRight(h);
            }
            //找到节点，将节点替换程后继节点，类似二叉树操作，
            if(k == h->key){
                shared_ptr<Node> x = Min(h->Right);
                h->key = x->key;
                h->val = x->val;

                h->Right = deleteMin(h->Right);
            }
            else{
                //没找到，继续递归查找
                h->Right = deleteK(h->Right, k);
            }
        }

        return balance(h);
    }
public:

    RBTree(): root(nullptr) {}

    bool isEmpty(){
        return root == nullptr;
    }

    int size(){
        return size(root);
    }

    Key Min(){
        return Min(root)->key;
    }
    Key Max(){
        return Max(root)->key;
    }
    //插入节点
    void put(Key k, Value v){
        root = put(root, k, v);
        root->color = RBTree::BLACK;
    }

    Value get(Key k){
        return get(root, k);
    }

    //删除最小节点
    void deleteMin(){
        if(isEmpty()){
            throw runtime_error("BST underflow");
        }
        //如果两个子节点都不是红色节点，那么将根节点设为红色节点，方便操作。
        if(!isRed(root->Left) && !isRed(root->Right))
            root->color = RBTree::RED;
        //删除操作
        root = deleteMin(root);
        //变回黑色节点
        if(!isEmpty()){
            root->color = RBTree::BLACK;
        }
    }


    void deleteMax(){
        if(isEmpty()){
            throw runtime_error("BST underflow");
        }
        //同deleteMin()
        if(!isRed(root->Left) && !isRed(root->Right)){
            root->color = RBTree::RED;
        }
        //删除操作
        root = deleteMax(root);
        //变色
        if(!isEmpty()){
            root->color = RBTree::BLACK;
        }
    }

    void deleteK(Key k){
        if(!isRed(root->Left) && !isRed(root->Right)){
            root->color = RBTree::RED;
        }

        root = deleteK(root, k);
        if(!isEmpty())
            root->color = RBTree::BLACK;
    }
private:
    shared_ptr<Node> root;
};

template<typename Key, typename Value>
bool RBTree<Key, Value>::RED = true;

template<typename Key, typename Value>
bool RBTree<Key, Value>::BLACK = false;
