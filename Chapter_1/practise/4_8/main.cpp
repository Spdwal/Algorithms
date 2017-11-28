#include"findEqual.hpp"
#include<vector>
#include<iostream>
using namespace std;

int main()
{
    vector<int> ivec;
    for(int i = 0; i< 1000; ++i)
    {
        ivec.push_back(i);
    }
    for(int i = 0; i< 1000; i += 3)
    {
        ivec.push_back(i);
    }

    cout << findEqual(ivec) << endl;
    cout << findEqualFast(ivec) << endl;

    return 0;
}
