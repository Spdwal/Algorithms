#pragma once
#include<vector>
#include<limits>
using namespace std;

void merge(vector<int> &ivec, int low, int mid, int high);
void MergeSort(vector<int> & ivec, int low, int high);
void MergeSort(vector<int> &ivec)
{
    MergeSort(ivec, 0, ivec.size() - 1);
}

void MergeSort(vector<int> & ivec, int low, int high)
{
    if(high <= low){
        return;
    }
    int mid = (low + high) / 2;
    MergeSort(ivec, low, mid);
    MergeSort(ivec, mid+1, high);
    merge(ivec, low, mid, high);
}

void merge(vector<int> &ivec, int low, int mid, int high)
{
    int i = mid - low + 1;
    int j = high - mid;
    int tmp = low;
    vector<int> L;
    vector<int> R;
    for(int k = 0; k < i; ++k){
        L.push_back(ivec[k+low]);
    }
    L.push_back(numeric_limits<int>::max());
    for(int k = 0; k < j; ++k){
        R.push_back(ivec[k+mid+1]);
    }
    R.push_back(numeric_limits<int>::max());

    int n1 = 0;
    int n2 = 0;
    for(; tmp <= high; ++tmp){
        if(L[n1] <= R[n2]){
            ivec[tmp] = L[n1++];
        }else{
            ivec[tmp] = R[n2++];
        }
    }
}
