#pragma once
#include<vector>
#include<algorithm>
using namespace std;

int findEqual(const vector<int> &ivec)
{
    int myCount = 0;
    for(int i = 0; i < ivec.size() - 1; ++i)
    {
        for(int j = i + 1; j < ivec.size(); ++j)
        {
            if(ivec[i] == ivec[j])
            {
                myCount++;
            }
        }
    }

    return myCount;
}

int findEqualFast(const vector<int> &ivec)
{
    vector<int> vec(ivec);
    int myCount = 0;
    sort(vec.begin(), vec.end());
    int flag = vec[0];
    for(int i = 1; i < vec.size(); ++i)
    {
        if(vec[i] == flag)
        {
            myCount ++ ;
        }else{
            
        }
    }

    return myCount;
}
