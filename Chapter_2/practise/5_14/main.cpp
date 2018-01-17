#include"ReverseDomain.hpp"
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;


int main()
{
    vector<Domain> ivec;
    Domain str;
    while(cin >> str){
        ivec.push_back(str);
    }

    sort(ivec.begin(), ivec.end());
    for(auto c : ivec){
        cout << c << endl;
    }

    return 0;
}
