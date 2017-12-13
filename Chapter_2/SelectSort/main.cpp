#include"SelectSort.hpp"
#include<iostream>
#include<random>
using namespace std;

int main(){
    vector<int> ivec = {1,2,3,5,6,7,2,4,5,2,3,23,5,2,1,321,2,4,5,3,32,1,43};
    selectSort(ivec, [](int a, int b){return a < b;});
    for(const auto &c : ivec){
        cout << c << endl;
    }

    return 0;
}
