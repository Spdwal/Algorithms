#pragma once
#include<vector>
using namespace std;

void InsertSort(vector<int> & ivec){
    int n = ivec.size();
    for(int i = 1; i < n; ++i){
        int tmp = ivec[i];
        int j = i;
        for(; j > 0 && tmp > ivec[j-1] ; j--){
            ivec[j] = ivec[j - 1];
        }
        ivec[j] = tmp;
    }
}
