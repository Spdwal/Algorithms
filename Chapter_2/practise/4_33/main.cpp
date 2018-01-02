#include"IndexPriorityQueue.hpp"
#include<iostream>

using namespace std;


int main(){
    IndexMinPQ PQ;
    PQ.insert(1, 20);
    PQ.insert(4, 15);
    PQ.insert(2, 40);

    cout << PQ.min_index() << endl;
    PQ.my_delete(4);
    cout << PQ.min_index() << endl;
    return 0;
}
