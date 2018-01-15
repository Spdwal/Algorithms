#pragma once
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

vector<string> dedup(vector<string> ivec)
{
    sort(ivec.begin(), ivec.end());
    auto last = unique(ivec.begin(), ivec.end());
    ivec.erase(last, ivec.end());
    return ivec;
}
