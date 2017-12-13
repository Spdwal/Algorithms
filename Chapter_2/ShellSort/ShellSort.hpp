#pragma once
#include<vector>
#include<utility>
using namespace std;
template<typename T, typename COMP>
void ShellSort(vector<T> &ivec, COMP comp)
{
    int n = ivec.size();
    int h = 1;
    while(h < n/3){
        h = 3 * h + 1;
    }

    while(h >= 1){
        for(int i = h; i < n; ++i){
            for(int j = i; j >= h && comp(ivec[j], ivec[j-h]); j -= h){
                swap(ivec[j], ivec[j-h]);
            }
        }
        h /= 3;
    }
}
