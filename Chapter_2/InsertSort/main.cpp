#include"InsertSort.hpp"
#include<iostream>
#include<random>
using namespace std;

int main()
{
    vector<int> ivec;
    random_device rd;
    std::uniform_int_distribution<int> dist;

    for(int i = 0; i < 1000; ++i)
    {
        ivec.push_back(dist(rd));
    }

    InsertSort(ivec, [](int a, int b){return a < b;});

    for(const auto & c: ivec){
        cout << c << endl;
    }

    return 0;
}
