#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<utility>
#include<functional>
using namespace std;

void Frequency()
{
    vector<pair<string, int>> ivec;
    string str;
    while(cin >> str){
        auto it = find_if(ivec.begin(), ivec.end(), [&](const pair<string, int> &P){ return str == P.first;});
        if(it == ivec.end()){
            ivec.push_back(make_pair(str, 1));
        }else{
            it->second += 1;
        }
    }

    sort(ivec.begin(), ivec.end(),
         [](const pair<string, int> &lhs, const pair<string, int> &rhs)
         { return lhs.second > rhs.second;});

    for(auto c : ivec){
        cout << c.first << endl;
    }
}
