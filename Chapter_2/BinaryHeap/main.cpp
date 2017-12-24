#include"BinaryHeap.hpp"
#include<random>
#include<vector>
#include<iostream>
using namespace std;

int main()
{
    BinaryHeap BH;

    random_device rd;
    uniform_int_distribution<int> dist(1, 100);

    for(int i = 0; i < 20; ++i){
        int num = dist(rd);
        BH.insert(num);
    }
    int i  = 1;
    while(!BH.empty()){
        cout << i++ << ":  ";
        cout << BH.delMax() << endl;
    }

    return 0;
}
