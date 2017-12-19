#pragma once
#include<vector>
#include<algorithm>
using namespace std;

void exchange_three(vector<int> &ivec, int low, int high)
{
    int mid = (low + high) / 2;
    if((ivec[low] >= ivec[mid] && ivec[mid] >= ivec[high]) ||
       (ivec[high] >= ivec[mid] && ivec[mid] >= ivec[low])){
        std::swap(ivec[low], ivec[mid]);
    }else if((ivec[low] >= ivec[high] && ivec[high] >= ivec[mid]) ||
             (ivec[mid] >= ivec[high] && ivec[high] >= ivec[low])){
        std::swap(ivec[low], ivec[mid]);
    }
}
int partional(vector<int> &ivec, int low, int high)
{
    
    int i = low;
    int j = high + 1;
    exchange_three(ivec, low, high);
    int v = ivec[low];
    while(true){
        while(ivec[++i] < v) if(i == high) break;
        while(ivec[--j] > v) if(j == low) break;
        if(i >= j) break;
        std::swap(ivec[i], ivec[j]);
    }
    std::swap(ivec[j], ivec[low]);
    return j;
}
void QuickSort(vector<int> &ivec, int low, int high)
{
    if(low >= high) return;
    int j = partional(ivec, low, high);
    QuickSort(ivec, low, j - 1);
    QuickSort(ivec, j + 1, high);
}

void QuickSort(vector<int> &ivec)
{
    random_shuffle(ivec.begin(), ivec.end());
    QuickSort(ivec, 0, ivec.size() - 1);
}
