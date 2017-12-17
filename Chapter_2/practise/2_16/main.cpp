#include"NaturalMergeSort.hpp"
#include<iostream>
#include<vector>
#include<random>
using namespace std;

int main()
{
    random_device rd;
    uniform_int_distribution<int> dist(1, 100);

    vector<int> ivec;
    
    for(int i = 0; i < 30; ++i){
        ivec.push_back(dist(rd));
    }
    
    MergeSort(ivec);
    for(auto c : ivec){
        cout << c << endl;
    }
    return 0;
}
