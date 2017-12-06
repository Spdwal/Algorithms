#include"Stack.hpp"
#include<iostream>
using namespace std;

int main()
{
    Stack<int> stk;
    for(int i = 0; i < 10; ++i){
        stk.push(i);
    }
    while(!stk.empty()){
        cout << stk.top() << endl;
        stk.pop();
    }
}
