#include<functional>
#include<queue>
#include<vector>
using namespace std;


template<typename T>
class Queue{
private:
    struct Node{
        int num;
        T data;
    };
public:
    Queue():que([](Node a, Node b){return a.num > b.num;}), N{0} {}
    Queue(const Queue &rhs){
        que = rhs.que;
        N = rhs.N;
    }

    int size(){return que.size();}
    void push(T num){
        Node n = {N++, num};
        que.push(n);
    }


    T top(){
        return que.top().data;
    }

    void pop(){
        que.pop();
    }

    bool empty() { return que.size() == 0;}
private:
    
    int N;
    priority_queue<Node, vector<Node>, function<bool(Node,Node)>>  que;
};
