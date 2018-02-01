#include"AVL.hpp"
#include<iostream>
using namespace std;

int main(){
    AVLTree<int> t;
    for(int i = 0; i < 10; i++){
        t.insert(i);
    }

    t.print();

    return 0;
}
