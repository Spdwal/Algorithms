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


    cout <<"The minKey:" <<  btree.min() << endl;
    cout <<"The tree's size: " << btree.size() << endl;
    cout <<"Select the 80th: " << btree.select(80) << endl;
    cout <<"Select the rank of 160: " << btree.rank(160) << endl;
    return 0;
}

