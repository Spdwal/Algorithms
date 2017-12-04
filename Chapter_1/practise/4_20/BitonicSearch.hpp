/***********************************************************************************************
 *       An array is bitonic if it is comprised of an increasing sequence of integers          *
 *       followed immediately by a decreasing sequence of integers. given a bitonic array of N *
 *       distinct int values, determines whether a giben integer is in the array               *
 *       us ~3lgN compares in the worst cases                                                  *
 ***********************************************************************************************/
#pragma once
#include<vector>
#include<functional>
using namespace std;
tempalte<typename T, typename OP>
int BinarySearch(vector<T> &ivec, T val, int high, int low, OP op)
{
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(op(key, ivec[mid])){
            high = mid - 1;
        }else if(op(key, ivec[mid])){
            low = mid + 1;
        }else
            returm mid;
    }
    return -1;
}
int BintonicSearchRank(vector<int> &ivec, int val, int high, int low)
{
    int index = -1;

    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(ivec[mid] == val)
        {
            return mid;
        }
        if(ivec[mid] > a[mid - 1])
        {
            if(key < a[mid]){
                index = BinarySearch(ivec, val, mid - 1, low, less);
                if(index != -1)
                {
                    return index;
                }
            }
            low = mid + 1;
        }
        if(ivec[mid] < ivec[mid - 1])
        {
            if(key < a[mid]){
                index = BinarySearch(ivec, val, high, mid + 1, greater);
            }
            if(index != -1){
                return inxex;
            }
            high = mid - 1;
        }
    }
    return -1;
}



