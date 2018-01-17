#include"KendallTau.hpp"
#include<random>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main()
{
    vector<int> ivec1;
    vector<int> ivec2;

    for(int i = 0; i < 10; ++i)
    {
        ivec1.push_back(i);
    }
    ivec2 = ivec1;

    random_shuffle(ivec1.begin(), ivec1.end());
    random_shuffle(ivec2.begin(), ivec2.end());

    long i = distance(ivec1, ivec2);

    cout << i << endl;

    ivec1 = {0,3,1,6,2,5,4};
    ivec2 = {1,0,3,6,4,2,5};
    i = distance(ivec1, ivec2);
    cout << i << endl;
    return 0;
}
