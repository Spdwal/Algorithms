#include"getLessNeighborIndex.hpp"
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> ivec;
    for(int i = 10; i > 0; --i)
    {
        ivec.push_back(i);
    }

    for(int i = 0; i < 5; ++i)
    {
        ivec.push_back(i);
    }

    cout << getLessNeighborIndex(ivec) << endl;

    return 0;
}
