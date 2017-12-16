#include"MergeSorted.hpp"
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> ivec1;
    vector<int> ivec2;

    for(int i = 1; i < 20; i+=4){
        ivec1.push_back(i);
    }

    for(int i = 2; i < 20; i += 3){
        ivec2.push_back(i);
    }

    vector<int> ivec = MergeSorted(ivec1, ivec2);

    for(auto c : ivec){
        cout << c << endl;
    }

    return 0;
}
