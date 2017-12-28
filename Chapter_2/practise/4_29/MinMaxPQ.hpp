#pragma once
#include<queue>
#include<functional>
using namespace std;


class MaxMinPQ{
public:
    MaxMinPQ():Size{0}, que1([](int a, int b){return a > b;}), que2([](int a, int b){return a < b;}) {}
    int max(){return que2.top();}
    int min(){return que1.top();}
    bool empty() { return Size == 0;}
    int size() {return Size;}
    void push(int i){
        Size ++;
        que1.push(i);
        que2.push(i);
    }

    void pop_max(){
        que2.pop();
        Size --;
    }

    void pop_min(){
        que1.pop();
        Size --;
    }
private:
    int Size;
    priority_queue<int, vector<int>, function<bool(int, int)>> que1;
    priority_queue<int, vector<int>, function<bool(int, int)>> que2;
};
