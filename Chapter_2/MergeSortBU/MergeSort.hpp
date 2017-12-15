#pragma once
#include<vector>
#include<iostream>
#include<limits>
#include<algorithm>
using namespace std;

int Min(int a, int b)
{
    return a < b ? a : b;
}
void merge(vector<int> &ivec, int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    vector<int> L;
    vector<int> R;
    for(int num = i; num < j; ++num){
        L.push_back(ivec[num]);
    }
    L.push_back(numeric_limits<int>::max());
    for(int num = j; num <= high; num++){
        R.push_back(ivec[num]);
    }
    R.push_back(numeric_limits<int>::max());

    int n1 = 0;
    int n2 = 0;
    for(; low <= high; low++){
        if(L[n1] < R[n2]){
            ivec[low] = L[n1++];
        }else{
            ivec[low] = R[n2++];
        }
    }
}


void MergeSort(vector<int> &ivec)
{
    int n = ivec.size();
    for(int sz = 1; sz < n; sz *= 2){
        for(int low = 0; low < n - sz; low += 2*sz){
            int myMin = Min(low + 2*sz -1, n -1);
            merge(ivec, low, low + sz - 1, myMin);
        }
    }
}

