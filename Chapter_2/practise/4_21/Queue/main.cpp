#include"Queue.hpp"
#include<random>
#include<iostream>

using namespace std;


int main()
{
    Queue<int> stk;
    for(int i = 0; i < 15; ++i){
        stk.push(i);
    }

    while(!stk.empty()){
        cout << stk.top() << endl;
        stk.pop();
    }

    return 0;
}
