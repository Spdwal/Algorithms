#pragma once
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> FindCompound(vector<string> &ivec)
{
    vector<string> ivec2;
    for(int i = 0; i < ivec.size(); i++){
        for(int j = 0; j < ivec.size(); j++){
            ivec2.push_back(ivec[i] + ivec[j]);
        }
    }

    vector<string> ivec3;
    for(const auto &c : ivec2){
        if(find(ivec.begin(), ivec.end(), c) != ivec.end()){
            ivec3.push_back(c);
        }
    }

    return ivec3;
}
