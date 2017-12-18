#include"ThreeWayQuickSort.hpp"
#include<vector>
#include<random>
#include<iostream>
using namespace std;


int main()
{
    vector<int> ivec;
    for(int i = 0; i < 100; i +=5){
        ivec.push_back(i);
    }

    QuickSort(ivec);

    for(auto c : ivec){
        cout << c << endl;
    }
}
