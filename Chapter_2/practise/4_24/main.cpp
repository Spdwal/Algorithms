#include"PriorityQueue.hpp"
#include<iostream>

using namespace std;


int main()
{
    PQ myQ;
    for(int i = 0; i < 10; ++i){
        myQ.insert(i);
    }

    while(!myQ.isEmpty()){
        cout << myQ.Max() << endl;
        myQ.delMax();
    }

    return 0;
}
