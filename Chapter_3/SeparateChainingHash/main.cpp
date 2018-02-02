#include"SCHash.hpp"
#include<iostream>
using namespace std;

int main()
{
    SCHash<int, int> myhash;
    for(int i = 0; i <20; i++){
        myhash.insert(i, i + 1);
    }

    for(int i = 0; i < 20; i ++)
    {
        cout << myhash[i] << endl;
    }

    return 0;
}
