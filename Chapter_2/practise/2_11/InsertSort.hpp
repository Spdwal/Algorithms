#pragma once
#include<vector>
using namespace std;

void InsertSort(vector<int> &ivec, int low, int high)
{
    int Size = high - low + 1;
    int h = 1;
    while(h < Size / 3) h = 3 * h + 1;
    while(h >= 1){
        for(int i = low + h; i <= high; ++i){
            for(int j = i; j >= low + h && ivec[j] < ivec[j - h]; j -= h){
                std::swap(ivec[j], ivec[j - h]);
            }
        }
        h /= 3;
    }
}
