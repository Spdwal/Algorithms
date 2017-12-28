#pragma once
#include<queue>
#include<functional>
using namespace std;

class MedianFindPQ{
private:
    void reset(){
        while(que1.size() < que2.size()){
            que1.push(que2.top());
            que2.pop();
        }
        while(que1.size() > que2.size() + 1){
            que2.push(que1.top());
            que1.pop();
        }
    }
public:
    MedianFindPQ():que1(greater<int>()), que2(less<int>()) {}
    bool empty() {return (que1.size() + que2.size()) == 0;}
    void  push(int num){
        if(que1.empty()){
            que1.push(num);
            return;
        }
        if(num > que1.empty()){
            que1.push(num);
        }else{
            que2.push(num);
        }
        reset();
    }

    void pop_mid(){
        que1.pop();
        reset();
    }
    int mid() {
        return que1.top();
    }
private:
    priority_queue<int, vector<int>, function<bool(int, int)>> que1;
    priority_queue<int, vector<int>, function<bool(int, int)>> que2;
};
