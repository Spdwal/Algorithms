#pragma once
#include<vector>
#include<algorithm>

int fourSum(vector<int> ivec)
{
    int myCount;
    sort(ivec.begin(), ivec.end());
    for(int i = 0; i < ivec.size(); ++i)
    {
        for(int j = i+1; j < ivec.size(); ++j)
        {
            for(int k = j + 1; k < ivec.size(); ++k)
            {
                if(binarySearch(ivec, (0-ivec[i] - ivec[j] - ivec[k])) != -1)
                {
                    myCount++;
                }
            }
        }
    }

    return myCount;
}
