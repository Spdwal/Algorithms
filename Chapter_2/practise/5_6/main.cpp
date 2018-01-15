#include"select.hpp"
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

    int i = Select(ivec, 7);
    cout << i << endl;
    vector<int> arr{1,3,4,2,5,7,8,-1};
    for(int i = 1; i <= 8; ++i){
        cout << Select(arr, i) << endl;
    }

    
    return 0;
}
