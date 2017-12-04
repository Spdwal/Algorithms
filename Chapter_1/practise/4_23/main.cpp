#include <iostream>
#include <vector>
#include <utility>
#include "BinarySearchFract.hpp"
using namespace std;

int main() {
    vector<pair<int, int>> ivec;
    for(int i = 0; i < 20; i++)
    {
        ivec.push_back(make_pair(i, i + 3));
    }

    for(auto c : ivec)
    {
        cout << c.first << " " << c.second << endl;
    }

    int i = binarySearch(ivec, make_pair(5, 8));
    cout << ivec[i].first << " " << ivec[i].second << endl;

    return 0;
}