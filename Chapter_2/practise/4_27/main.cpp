#include"Heap.hpp"
#include<vector>
#include<iostream>
using namespace std;

int main()
{
    MaxPQ  p;
    for(int i = 0; i < 10; ++i){
        p.insert(i);

    }
    cout << p.min() << endl;

    while(!p.isEmpty()){
        int Max = p.delMax();
        cout << Max << endl;
    }

    return 0;
}
