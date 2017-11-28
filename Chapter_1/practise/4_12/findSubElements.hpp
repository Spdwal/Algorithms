#pragma once
#include<vector>
using namespace std;

vector<int> findSubElements(vector<int> ivec1, vector<int> ivec2)
{
    int i = 0;
    int j = 0;
    vector<int> ivec;
    while(i < ivec1.size() && j < ivec2.size())
    {
        if(ivec1[i] == ivec2[j])
        {
            ivec.push_back(ivec1[i]);
			i++;
			j++;
        }else if(ivec1[i] > ivec2[j])
        {
            j++;
        }else{
            i++;
        }
    }

    return ivec;
}
