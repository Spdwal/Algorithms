#include"QueueMadeByStack.hpp"
#include<iostream>
using namespace std;

int main()
{
    Queue<int> myQ;
    for(int i = 0; i < 10; ++i){
        myQ.push(i);
    }

    while(!myQ.empty()){
        cout << myQ.top() << endl;
        myQ.pop_front();
    }

    return 0;
}
