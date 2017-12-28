#include"MedianFind.hpp"
#include<iostream>
using namespace std;



int main()
{
    MedianFindPQ PQ;
    for(int i = 0; i < 10; ++i){
        PQ.push(i);
    }

    while(!PQ.empty()){
        cout << PQ.mid() << endl;
        PQ.pop_mid();
    }

    return 0;
}
