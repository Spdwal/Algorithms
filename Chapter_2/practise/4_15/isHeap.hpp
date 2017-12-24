#pragma once
#include<vector>
using namespace std;

bool isHeap(const vector<int> &ivec)
{
    int n = ivec.size();
    for(int i = 0; i < n / 2; ++i){
        if(ivec[i] < ivec[2 * i + 1] || ivec[i] < ivec[2 * i + 2]){
            return false;
        }
    }
    return true;
}
