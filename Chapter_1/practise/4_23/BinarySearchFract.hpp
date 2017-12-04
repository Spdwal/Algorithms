//
// Created by spdwal on 04/12/17.
//

#ifndef INC_4_23_BINARYSEARCHFRACT_HPP
#define INC_4_23_BINARYSEARCHFRACT_HPP
#include<vector>
#include<utility>
using namespace std;

bool Less(const pair<int, int> &lhs, const pair<int, int> &rhs)
{
    return lhs.first * rhs.second < rhs.first * lhs.second;
}
int binarySearch(const vector<pair<int, int>> &ivec, const pair<int, int> &val)
{
    int low = 0;
    int high = ivec.size() - 1;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(Less(ivec[mid], val))
        {
            low = mid + 1;
        }else if(Less(val, ivec[mid]))
        {
            high = mid - 1;
        }else{
            return mid;
        }
    }
    return -1;
}

#endif //INC_4_23_BINARYSEARCHFRACT_HPP
