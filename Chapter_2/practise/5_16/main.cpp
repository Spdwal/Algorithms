#include"UnbiasedElection.hpp"
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<Name> ivec;
    ivec.push_back(Name("zhang"));
    ivec.push_back(Name("li"));
    ivec.push_back(Name("he"));
    ivec.push_back(Name("zheng"));
    ivec.push_back(Name("wang"));
    ivec.push_back(Name("zhao"));
    ivec.push_back(Name("qian"));
    
    sort(ivec.begin(), ivec.end());

    for(auto c: ivec){
        cout << c << endl;
    }

    return 0;
}
