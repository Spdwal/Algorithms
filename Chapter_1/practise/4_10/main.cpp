#include"BinarySearch.hpp"
#include<vector>
#include<iostream>
using namespace std;


int main()
{
    vector<int> ivec = {1,2,3,4,4,4,5,6,7};
    cout << BinarySearchMin(ivec, 4) << endl;

    return 0;
}
