#include"RBTree.hpp"
#include<iostream>

using namespace std;

int main()
{
    RBTree<int, int> rb;
    for(int i = 0; i < 10; i++){
        rb.put(i+1, i);
    }

    rb.deleteK(3);
    //rb.deleteMin();
    for(int i = 0; i < 10; i++){
        cout << rb.get(i+1) << endl;
    }

    return 0;
}
