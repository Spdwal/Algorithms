#pragma once
#include<vector>
#include<iostream>
using namespace std;
template<typename T>
void printTransposition(const vector<vector<T>> &ivec)
{
    for(int i = 0; i < ivec[0].size(); ++i)
    {
        for(int j = 0; j < ivec.size(); ++j)
        {
            cout << ivec[j][i] << ' ';
        }
        cout << endl;
    }
}
