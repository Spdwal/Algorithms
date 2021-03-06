#pragma once
#include<vector>
#include<algorithm>
using namespace std;

int Partition(vector<int> &ivec, int low, int high)
{
    int i = low;
    int j = high + 1;
    int v = ivec[low];
    while(i < j){
        while(ivec[++i] < v) if(i == high) break;
        while(v < ivec[--j]) if(j == low) break;
        if(i >= j) break;
        std::swap(ivec[i], ivec[j]);
    }
    std::swap(ivec[j], ivec[low]);
    return j;
}

int Select(vector<int> &ivec, int low, int high, int k)
{
    if(high <= low) return ivec[k];
    int j = Partition(ivec, low, high);
    if(j == k)
        return ivec[j];
    else if(j > k)
        return Select(ivec, low, j-1, k);
    else if(j < k)
        return Select(ivec, j+1, high, k);
}
int Select(vector<int> &ivec, int k){
    random_shuffle(ivec.begin(), ivec.end());
    int low = 0;
    int high = ivec.size() - 1;
    return Select(ivec, 0, high, k-1);
}
