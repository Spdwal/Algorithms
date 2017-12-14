#pragma once
#include<deque>
#include<utility>
using namespace std;

void GoToDown(deque<int> &deq)
{
    int n = *deq.begin();
    deq.pop_front();
    deq.push_back(n);
}


void DeckSort(deque<int> &deq)
{
    int Size = deq.size();
    for(int i = Size; i > 0; --i){
        for(int j = i - 1; j > 0; j--){
            int &First = deq[0];
            int &Second = deq[1];
            if(First > Second){
                std::swap(First, Second);
            }
            GoToDown(deq);
        }
        for(int k = 0; k < Size + 1 - i; ++k){
            GoToDown(deq);
        }
    }
}
