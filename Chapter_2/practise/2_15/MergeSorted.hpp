#pragma once
#include<vector>

using namespace std;


vector<int> MergeSorted(vector<int> ivec1, vector<int> ivec2)
{
    int i = 0;
    int j = 0;
    vector<int> ivec;
    int Sz = ivec1.size() + ivec2.size();
    for(int k = 0; k < Sz; ++k){
        if(i >= ivec1.size()){
            ivec.push_back(ivec2[j++]);
        }else if(j >= ivec2.size()){
            ivec.push_back(ivec1[i++]);
        }else if(ivec1[i] > ivec2[j]){
            ivec.push_back(ivec2[j++]);
        }else{
            ivec.push_back(ivec1[i++]);
        }
    }

    return ivec;
}
