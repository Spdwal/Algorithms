#include"LPHash.hpp"
#include<iostream>
using namespace std;


int main()
{
    LPHash<int, int> L;
    for(int i = 0; i < 10; i++){
        L.insert(i, i);
    }

    L.erase(9);
    for(int i = 0; i < 10; ++i){
        cout << L.get(i) << endl;
    }

    return 0;
}
