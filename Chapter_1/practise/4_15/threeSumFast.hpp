#pragma once
#include<vector>
using namespace std;

int twoSumFast(const vector<int> &ivec)
{
    int i = 0;
    int j = ivec.size() - 1;
    int myCount = 0;
    while(i < j)
    {
        if(ivec[i] == -ivec[j])
        {
            myCount++;
            i++;
            j--;
        }else if(ivec[j] + ivec[i] > 0)
        {
            j--;
        }else
        {
            i++;
        }
    }
    return myCount;
}


int threeSumFast(const vector<int> &ivec)
{
    int k = ivec.size();
    int myCount = 0;
    for(int i = 0; i < ivec.size(); ++i)
    {
        int j = i + 1;
        while(j < k)
        {
            if(ivec[i] + ivec[j] + ivec[k] == 0)
            {
                myCount++;
                j++;
                k--;
            }else if(ivec[i] + ivec[j] + ivec[k] >0)
            {
                k--;
            }else{
                j++;
            }
        }
    }

    return myCount;
}
