#include"InsertSort.hpp"
#include"MergeSort.hpp"
#include<vector>
#include<iostream>
#include<random>
using namespace std;

int main()
{
    vector<int> ivec;
    random_device rd;
    uniform_int_distribution<int> dist(1,100);
    for(int i = 0; i < 50; ++i){
        ivec.push_back(dist(rd));
    }

    MergeSort(ivec);

    for(auto c : ivec){
        cout << c << endl;
    }
    return 0;
}
