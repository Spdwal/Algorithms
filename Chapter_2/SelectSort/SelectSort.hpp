#pragma once
#include<vector>
#include<utility>
using namespace std;

template<typename T, typename COMP>
void selectSort(vector<T> &ivec, int pos, COMP comp)
{
    if(pos == ivec.size() -1)
        return ;
    T elem = ivec[pos];
    int achor = pos;
    for(int i = pos + 1; i < ivec.size(); ++i){
        if(comp(elem, ivec[i])){
            elem = ivec[i];
            achor = i;
        }
    }
    std::swap(ivec[pos], ivec[achor]);
    selectSort(ivec, pos + 1, comp);
}


template<typename T, typename COMP>
void selectSort(vector<T> &ivec, COMP comp)
{
    selectSort(ivec, 0, comp);
}
