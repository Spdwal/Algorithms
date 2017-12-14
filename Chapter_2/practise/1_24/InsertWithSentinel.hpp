#pragma once
#include<vector>
#include<algorithm>
using namespace std;
void InsertSort(vector<int> &ivec)
{
    auto Min = min_element(ivec.begin(), ivec.end());
    std::swap(ivec[0], *Min);
    int n = ivec.size();
    for(int i = 1; i < n; ++i){
        for(int j = i; ivec[j] < ivec[j-1]; --j){
            std::swap(ivec[j], ivec[j-1]);
        }
    }
}
