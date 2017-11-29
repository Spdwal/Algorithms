#pragma once
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

pair<double, double> closePair(vector<double> &ivec)
{
    sort(ivec.begin(), ivec.end());
    double clo = abs(ivec[1] - ivec[0]);
    int pos = 0;
    for(int i = 0; i + 1 < ivec.size() - 1; ++i)
    {
        if(abs(ivec[i]- ivec[i+1]) < clo)
        {
            pos = i;
            clo = abs(ivec[i] - ivec[i+1]);
        }
    }

    return make_pair(ivec[pos], ivec[pos+1]);
}
