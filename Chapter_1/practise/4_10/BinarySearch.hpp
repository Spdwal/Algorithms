#pragma once
#include<vector>

using namespace std;

int BinarySearch(const vector<int> &ivec, int low, int high, int search);
int BinarySearchMin(const vector<int> &ivec,int search)
{
    int low = 0;
    int high = ivec.size();
    return BinarySearch(ivec, low, high, search);
}

int BinarySearch(const vector<int>& ivec, int low, int high, int search)
{
    int mid = (low + high)/2;
    if(low > high)
    {
        return -1;
    }


    if(search > ivec[mid])
    {
        return BinarySearch(ivec, mid + 1, high, search);
    }else if(search < ivec[mid])
    {
        return BinarySearch(ivec, low, mid - 1, search);
    }else{
        int i = BinarySearch(ivec, low, mid-1, search);
        if(i == -1){
            return mid;
        }else{
            return i;
        }
    }
}
