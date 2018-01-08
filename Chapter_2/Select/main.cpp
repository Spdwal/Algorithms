#include"Select.hpp"
#include<vector>
#include<random>
#include<iostream>
using namespace std;

int main()
{
    vector<int> ivec;
    for(int i = 0; i < 7; ++i){
        ivec.push_back(i);
    }

    for(auto c : ivec){
        cout << c << endl;
    }

    int i = Select(ivec, 4);
    cout << i << endl;

    return 0;
}
