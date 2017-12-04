#include <iostream>
#include "MihaiPatrascu.hpp"

int main() {
    vector<int> ivec;
    for(int i = 0; i < 100; i++)
    {
        ivec.push_back(i);
    }
    int i = fibnacciSearch(ivec, 40);

    cout << i << endl;
    return 0;
}