#include"BST.hpp"
#include<iostream>
using namespace std;

int main()
{
    BST<int, int> btree;
    for(int i = 0; i < 100; i++){
        btree.put(100+i, i);
        cout << btree.size() << endl;
    }

    for(int i = 0; i < 100; i++){
        cout << btree.get(100+i) << endl;
    }

    cout << btree.size() << endl;
    return 0;
}
