//
// Created by spdwal on 04/12/17.
//

#include "BitonicSearch.hpp"
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<int> ivec{1,3,5,7,9,8,6,4,2,0};
    int i = BintonicSearchRank(ivec, 5);
    cout << i << endl;
    return 0;
}
