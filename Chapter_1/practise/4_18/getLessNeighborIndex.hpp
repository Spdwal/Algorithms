#pragma once
#include<vector>
#include<stdexcept>
using namespace std;

int getLessNeighborIndex(const vector<int>& ivec)
{
    if(ivec.empty())
    {
        throw range_error("Invaalid parameters");
    }

    if(ivec.size() == 1)
    {
        return ivec[0];
    }
    if(ivec[ivec.size() - 1] < ivec[ivec.size() - 2])
    {
        return ivec.size() - 1;
    }

    int left = 1;
    int right = ivec.size() - 2;
    while(left < right)
    {
        int mid = (left + right) / 2;
        if(mid + 1 <= right && ivec[mid] > ivec[mid+1])
        {
            left = mid+1;
        }else if(mid - 1 >= left && ivec[mid] > ivec[mid - 1])
        {
            right = mid - 1;
        }else
            return mid;
    }
    return left;
}

