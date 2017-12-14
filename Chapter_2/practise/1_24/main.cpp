#include"InsertWithSentinel.hpp"
#include<random>
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> ivec;
    random_device rd;
    uniform_int_distribution<int> dist;
    for(int i = 0; i < 1000; ++i){
        ivec.push_back(dist(rd));
    }

    InsertSort(ivec);
    for(auto c: ivec){
        cout << c << endl;
    }

    return 0;
}
