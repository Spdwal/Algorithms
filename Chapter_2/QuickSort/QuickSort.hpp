#pragma once
#include<vector>
using namespace std;

int partition(vector<int> &ivec, int low, int high)
{
    int i = low;
    int j = high + 1;
    int v = ivec[low];
    while(true){
        while(ivec[++i] < v){
            if(i == high)
                break;
        }
        while(v < ivec[--j]){
            if(j == low)
                break;
        }
        if(i >= j)
            break;
        std::swap(ivec[i], ivec[j]);
    }
    std::swap(ivec[low], ivec[j]);
    return j;
}

void QuickSort(vector<int> &ivec, int low, int high)
{
    if(high <= low){
        return;
    }
    int j = partition(ivec, low, high);
    QuickSort(ivec, low, j - 1);
    QuickSort(ivec, j+1, high);
}


void QuickSort(vector<int> &ivec)
{
    QuickSort(ivec, 0, ivec.size() - 1);
}

