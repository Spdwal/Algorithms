#include"QuickSort.hpp"
#include<vector>
#include<iostream>
#include<random>
using namespace std;


int main()
{
    vector<int> ivec;
    random_device rd;
    uniform_int_distribution<int> dist(1,100);
    for(int i = 0; i < 30; ++i){
        ivec.push_back(dist(rd));
    }

    QuickSort(ivec);

    for(auto c : ivec){
        cout << c << endl;
    }

    return 0;

}
