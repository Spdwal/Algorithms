#pragma once
#include<vector>
#include<algorithm>
#include<iostream>
#include<limits>
using namespace std;

int myMax(int a, int b)
{
    return a > b ? a : b;
}
int Throw(int Eggs, int Floors)
{
    int i, j, k, t, Max;
    vector<vector<int>> tmp(Eggs+1, vector<int>(Floors+1));
    for(i = 0; i < Floors + 1; ++i)
    {
        tmp[0][i] = 0;
        tmp[1][i] = i;
    }

    for(i = 2; i < Eggs + 1; ++i)
    {
        tmp[i][0] = 0;
        tmp[i][1] = 1;
    }
    Max = numeric_limits<int>::max();
    for(i = 2; i <= Eggs; ++i)
    {
        for(j = 2; j <= Floors; ++j)
        {
            for(k = 1; k < j; ++k)
            {
                cout << "Eggs: " << Eggs << endl;
                cout << "i: " << i << endl;
                cout << "j: " << j << endl;
                cout << "k: " << k << endl;
                cout << "tmp[" << i << "]" << "[" << j - k << "]:" << tmp[i][j-k] << endl;
                cout << "tmp[" << i-1 << "][" << k-1 << "]:" << tmp[i-1][k-1] << endl;
                t = myMax(tmp[i][j-k], tmp[i-1][k-1]);
                if(Max > t)
                {
                    Max = t;
                }
                cout << "Max: " << Max << endl;

            }
            tmp[i][j] = Max + 1;
        }
    }

    return tmp[Eggs][Floors];
}
