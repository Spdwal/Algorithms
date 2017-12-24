#pragma once
#include<vector>
using namespace std;

void sink(vector<int> &ivec, int start, int end)
{
    int c = start;
    int l = 2 * c + 1;
    int tmp = ivec[c];
    for(; l <= end; c = l, l = 2 * l + 1){
        if(l < end && ivec[l] < ivec[l+1]){
            l++;
        }
        if(tmp >= ivec[l])
            break;
        else{
            ivec[c] = ivec[l];
            ivec[l] = tmp;
        }
    }
}

void HeapSort(vector<int> &ivec)
{
    int N = ivec.size();
    for(int k = N / 2 - 1; k >= 0; k--){
        sink(ivec, k, N - 1);
    }

    for(int i = N - 1; i > 0; --i){
        std::swap(ivec[0], ivec[i]);
        sink(ivec, 0, i-1);
    }
}
