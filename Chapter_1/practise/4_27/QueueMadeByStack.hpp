#pragma once
#include<stack>

using namespace std;

template<typename T>
class Queue{
public:
    Queue(): stk1{}, stk2{}{}
    Queue(const Queue &rhs): stk1{rhs.stk1}, stk2{rhs.stk2}{}
    void push(T val){
        if(stk1.empty()){
            while(!stk2.empty()){
                stk1.push(stk2.top());
                stk2.pop();
            }
        }
        stk1.push(val);
    }

    T top(){
        while(!stk1.empty()){
            stk2.push(stk1.top());
            stk1.pop();
        }
        return stk2.top();
    }

    void pop_front(){
        while(!stk1.empty()){
            stk2.push(stk1.top());
            stk1.pop();
        }
        stk2.pop();
        while(!stk2.empty()){
            stk1.push(stk2.top());
            stk2.pop();
        }
    }

    bool empty() const{
        return stk1.empty() && stk2.empty();
    }
private:
    stack<T> stk1;
    stack<T> stk2;
};
