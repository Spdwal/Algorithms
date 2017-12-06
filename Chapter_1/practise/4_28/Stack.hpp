#pragma once
#include<queue>
using namespace std;

template<typename T>
class Stack{
public:
    Stack() = default;
    Stack(const Stack &rhs): myQ{rhs.myQ} {}
    T top() const{
        return myQ.back();
    }
    void push(T val)
    {
        myQ.push(val);
    }
    size_t size() const{
        return myQ.size();
    }
    void pop(){
        int Size = myQ.size();
        for(int i = 0; i < Size - 1; ++i){
            int val = myQ.front();
            myQ.push(val);
            myQ.pop();
        }
        myQ.pop();
    }
    bool empty(){
        return myQ.size() == 0;
    }
private:
    queue<T> myQ;
};
