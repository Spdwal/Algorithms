#pragma once
#include<vector>
#include<iostream>
using namespace std;

void merge(vector<int> &ivec, int low, int mid, int high, vector<int> &tmp, long &Count)
{
    int i = low;
    int j = mid + 1;
    for(int k = low; k <= high; k++){
        tmp[k] = ivec[k];
    }

    for(int k = low; k <= high; ++k){
        if(i > mid){
            ivec[k] = tmp[j++];
        }else if(j > high){
            ivec[k] = tmp[i++];
        }else if(tmp[j] < tmp[i]){
            ivec[k] = tmp[j++];
            Count += mid - i + 1;
        }else{
            ivec[k] = tmp[i++];
        }
    }
}
void mergeSort(vector<int> &ivec, int low, int high, vector<int> &tmp, long &Count)
{
    if(high <= low){
        return ;
    }
    int mid = low + (high - low) / 2;
    mergeSort(ivec, low, mid, tmp, Count);
    mergeSort(ivec, mid+1, high, tmp, Count);
    merge(ivec, low, mid, high, tmp, Count);
}
long mergeCount(vector<int> &ivec)
{
    vector<int> tmp(ivec);
    long Count = 0;
    mergeSort(ivec, 0, ivec.size() - 1, tmp, Count);
    return Count;
}

long distance(vector<int> &ivec1, vector<int> &ivec2)
{
    if(ivec1.size() != ivec2.size())
    {
        cout << "Array dimensions disagree" << endl;
        return -1;
    }

    int n = ivec1.size();

    vector<int> tmp1(n);

    for(int i = 0; i < n; i++){
        tmp1[ivec1[i]] = i;
    }

    vector<int> tmp2(n);

    for(int i = 0; i < n; i++)
    {
        tmp2[i]= tmp1[ivec2[i]];
    }

    return mergeCount(tmp2);
}
