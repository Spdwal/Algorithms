#include"InsertSort.hpp"
#include<random>
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> ivec;
    random_device rd;
    uniform_int_distribution<int> dist(1, 20);
    for(int i = 0; i < 10; ++i){
        ivec.push_back(dist(rd));
    }

    InsertSort(ivec);
    for(auto c: ivec){
        cout << c << endl;
    }

    return 0;
}
