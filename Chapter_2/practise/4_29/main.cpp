#include"MinMaxPQ.hpp"
#include<iostream>
using namespace std;



int main()
{
    MaxMinPQ PQ;
    for(int i = 0; i < 10; ++i){
        PQ.push(i);
    }
    cout << PQ.size() << endl;
    cout << PQ.max() << endl;
    cout << PQ.min() << endl;

    while(!PQ.empty()){
        cout << PQ.max() << endl;
        cout << PQ.min() << endl;
        PQ.pop_max();
        PQ.pop_min();
    }
    return 0;
}
