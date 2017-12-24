#include<functional>
#include<queue>
#include<vector>
using namespace std;


template<typename T>
class Stack{
private:
    struct Node{
        int num;
        T data;
    };
public:
    Stack():que([](Node a, Node b){return a.num < b.num;}), N{0} {}
    Stack(const Stack &rhs){
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
    //auto cmp = [](Node a, Node b){return a.num > b.num;};
    int N;
    priority_queue<Node, vector<Node>, function<bool(Node,Node)>>  que;
};
