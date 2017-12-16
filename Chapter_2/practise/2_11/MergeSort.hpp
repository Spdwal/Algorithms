#pragma once
#include<vector>
#include"InsertSort.hpp"
using namespace std;

void merge(vector<int> &ivec, int low, int mid, int high, vector<int> & tmp);
void MergeSort(vector<int> &ivec, int low, int high, vector<int> &tmp);
bool is_Sorted(const vector<int> &ivec, int low, int high);
int Max(int a, int b)
{
    return a > b ? a : b;
}

void MergeSort(vector<int> &ivec)
{
    vector<int> tmp(ivec);
    MergeSort(ivec, 0, ivec.size() - 1, tmp);
}

void MergeSort(vector<int> &ivec, int low, int high, vector<int> &tmp)
{
    if(is_Sorted(ivec, low, high)){
       return;
    }
    if(high - low < 15){
        InsertSort(ivec, low, high);
        return ;
    }
    //if(high <= low) return ;
    int mid = (low + high) / 2;
    MergeSort(ivec, low, mid, tmp);
    MergeSort(ivec, mid + 1, high, tmp);
    merge(ivec, low, mid, high, tmp);
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

bool is_Sorted(const vector<int> &ivec, int low, int high)
{
    for(int i = low; i < high; ++i){
        if(ivec[i] > ivec[i + 1]){
            return false;
        }
    }
    return true;
}
