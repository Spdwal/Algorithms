#pragma once
#include<vector>
using namespace std;

template<typename T, typename COMP>
void InsertSort(vector<T> &ivec, COMP comp){
    int n = ivec.size();
    for(int i = 1; i < n; ++i){
        for(int j = i; j > 0 && comp(ivec[j], ivec[j-1]); j--){
            std::swap(ivec[j], ivec[j - 1]);
        }
    }
}
