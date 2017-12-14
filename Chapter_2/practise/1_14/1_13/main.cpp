#include"DeckSort.hpp"
#include<iostream>
#include<deque>
#include<algorithm>

using namespace std;

int main()
{
    deque<int> deq;
    for(int i = 1; i < 53; ++i){
        deq.push_back(i);
    }

    random_shuffle(deq.begin(), deq.end());
    for(auto c : deq){
        cout << c << endl;
    }

    DeckSort(deq);

    cout << "sorted: " << endl;
    for(auto c : deq){
        cout << c << endl;
    }
}
