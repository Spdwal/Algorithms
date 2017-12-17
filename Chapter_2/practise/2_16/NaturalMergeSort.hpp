#pragma once
#include<vector>
#include<algorithm>
using namespace std;

int SortedPos(vector<int> ivec, int low, int high)
{
    int i;
    for(i = low; i < high; ++i){
        if(ivec[i] > ivec[i+1]){
            break;
        }
    }
    return i;
}

void merge(vector<int> &ivec, int low, int mid, int high, vector<int> &tmp)
{
    int i = low;
    int j = mid + 1;

    for(int k = low; k <= high; ++k){
        tmp[k] = ivec[k];
    }

    for(int k = low; k <= high; ++k){
        if(i > mid){
            ivec[k] = tmp[j++];
        }else if(j > high){
            ivec[k] = tmp[i++];
        }else if(tmp[i] > tmp[j]){
            ivec[k] = tmp[j++];
        }else{
            ivec[k] = tmp[i++];
        }
    }
}


void MergeSort(vector<int> &ivec)
{
    int n = ivec.size();
    vector<int> tmp(ivec);

    for(int sz = 1; sz < n; sz *= 2){
        for(int low = 0; low < n - sz; low += 2 * sz){
            int high = min(low + sz + sz - 1, n -1);
            int pos = SortedPos(ivec, low, high);
            merge(ivec, low, pos, high, tmp);
        }
    }
}
