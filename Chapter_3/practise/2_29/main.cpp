#include"BST.hpp"
#include<iostream>
using namespace std;

int main()
{
    BST<int, int> btree;
    for(int i = 0; i < 20; i++){
        btree.put(100+i, i);
        cout << btree.size() << endl;
    }

    for(int i = 0; i < 20; i++){
        cout << btree.get(100+i) << endl;
    }


    cout <<"The minKey:" <<  btree.min() << endl;
    cout <<"The tree's size: " << btree.size() << endl;
    cout <<"Select the 18th: " << btree.select(18) << endl;
    cout <<"Select the rank of 116: " << btree.rank(116) << endl;
    btree.deleteKey(115);
    cout <<"Select the rank of 115: " << btree.rank(116) << endl;

    btree.print();
    std::queue<int> que = btree.keys();
    while(!que.empty()){
        cout << que.front() << endl;
        que.pop();
    }
    cout << boolalpha << btree.isBinaryTree() << endl;

    cout << btree.height() << endl;
    return 0;
}

