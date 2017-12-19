#include<vector>
#include<iostream>
#include"QuickSort.hpp"
using namespace std;

int main()
{
    vector<int> ivec;
    for(int i = 0; i < 20; ++i)
    {
        ivec.push_back(i);
    }

    QuickSort(ivec);

    for(auto c : ivec){
        cout << c << endl;
    }

    return 0;
}
