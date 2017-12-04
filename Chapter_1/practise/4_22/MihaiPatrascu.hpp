//
// Created by spdwal on 04/12/17.
//

#ifndef INC_4_22_MIHAIPATRASCU_HPP
#define INC_4_22_MIHAIPATRASCU_HPP

#include <vector>
using namespace std;
vector<int> fibnacci(int max)
{
    vector<int> ivec;
    ivec.push_back(1);
    ivec.push_back(1);
    for(int i = 2; i < max; ++i)
    {
        ivec.push_back(ivec[i-1]+ivec[i-2]);
    }
    return ivec;
}

int fibnacciSearch(vector<int> ivec, int val)
{
    int low = 0;
    int high = ivec.size() - 1;
    int mid = 0;

    int k = 0;

    int i = 0;
    vector<int> fib = fibnacci(20);

    while(ivec.size() > fib[k]-1)
    {
        k++;
    }
    vector<int> tmp(fib[k] - 1);
    for(int i = 0; i < ivec.size(); ++i)
    {
        tmp[i] = ivec[i];
    }
    for(int i = ivec.size(); i < ivec[k] - 1; ++i)
    {
        tmp[i] = tmp[high];
    }
    while(low <= high)
    {
        mid = low + fib[k - 1] - 1;
        if(tmp[mid] > val)
        {
            high = mid - 1;
            k--;
        }else if(tmp[mid]<val){
            low = mid + 1;
            k -= 2;
        }else{
            if(mid <= high)
            {
                return mid;
            }else{
                return high;
            }
        }
    }
    return -1;
}
#endif //INC_4_22_MIHAIPATRASCU_HPP
